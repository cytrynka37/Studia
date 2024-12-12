import requests
from queue import Queue
from bs4 import BeautifulSoup
from urllib.parse import urljoin

def crawl(start_page, distance, action):
    visited = set()
    queue = Queue()
    queue.put((start_page, 0))

    while not queue.empty():
        url, curr_distance = queue.get()
        if url in visited or curr_distance > distance:
            continue

        visited.add(url)

        try:
            response = requests.get(url, timeout=5)
            response.raise_for_status()
            content = response.text
        except (requests.RequestException, ValueError) as e:
            print(f"Błąd pobierania {url}: {e}")
            continue

        yield (url, action(content))

        if distance > curr_distance:
            soup = BeautifulSoup(content, 'html.parser')
            links = [urljoin(url, link.get('href')) for link in soup.find_all('a', href=True)]   
            for full_url in links:
                queue.put((full_url, curr_distance + 1))


for url, wynik in crawl("http://www.ii.uni.wroc.pl", 1, lambda tekst : 'Python' in tekst):
    print(f"{url}: {wynik}")