import requests
import threading
from queue import Queue
from bs4 import BeautifulSoup
from urllib.parse import urljoin

def worker(shared_queue, action, distance, result, visited):
    while True:
        item = shared_queue.get()

        if item is None:
            break

        url, curr_distance = item


        if url in visited:
            shared_queue.task_done()
            continue
        visited.add(url) 

        try:
            response = requests.get(url, timeout=5)
            response.raise_for_status()
            content = response.text
            wynik = action(content)
            result[(url, curr_distance)] = wynik
            print(f"{url}: {wynik}")

            if distance > curr_distance:
                soup = BeautifulSoup(content, 'html.parser')
                links = [urljoin(url, link.get('href')) for link in soup.find_all('a', href=True)]
                for full_url in links:
                    shared_queue.put((full_url, curr_distance + 1))
        
        except (requests.RequestException, ValueError) as e:
            print(f"Error fetching {url}: {e}")

        shared_queue.task_done()
    
def crawl(start_page, distance, action, num_of_threads=5):
    visited = set()
    shared_queue = Queue()
    shared_queue.put((start_page, 0))

    result = {}
    threads = []
    for _ in range(num_of_threads):
        t = threading.Thread(target=worker, args=(shared_queue, action, distance, result, visited))
        threads.append(t)
        t.start()
    
    shared_queue.join()

    for _ in threads:
        shared_queue.put(None)

    [t.join() for t in threads]
    return result

crawl("http://www.ii.uni.wroc.pl", 1, lambda text: 'Python' in text)