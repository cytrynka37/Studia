# Kaja Matuszewska 345951
# Lista 2 zadanie 5
import requests

def compression(text):
    letters = []
    count = 1
    for i in range(1, len(text)):
        if text[i - 1] == text[i]:
            count += 1
        else:
            new_tuple = (count, text[i - 1])
            letters.append(new_tuple)
            count = 1
    new_tuple = (count, text[-1])
    letters.append(new_tuple)
    return letters

def decompression(compressed_text):
    text = ""
    for count, letter in compressed_text:
        text += letter * count

    return text

response = requests.get("https://wolnelektury.pl/media/book/txt/orwell-rok-1984.txt")
text = response.text

print("Tekst przed zmianami: ", text[2300:3000])

compressed_text = compression(text)
print("\nSkompresowany tekst: ", compressed_text[2300:3000])

decompressed_text = decompression(compressed_text)
print("\nSkompresowany tekst: ", decompressed_text[2300:3000])

print("\nczy text = decompressed_text?", text == decompressed_text)