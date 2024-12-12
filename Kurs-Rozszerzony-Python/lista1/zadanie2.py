#Kaja Matuszewska 345951
#Lista 1 Zadanie 2

def is_palindrom(text):
    text = ''.join(c.lower() for c in text if c.isalnum())
    
    for i in range(len(text) // 2):
        if text[i] != text [-(i + 1)]:
            return False
        
    return True

words = [
    "palindrom",
    "kajak",
    "Kobyła ma mały bok.",
    "Eine güldne, gute Tugend: Lüge nie!",
    "Míč omočím."]

for word in words:
    print(f"'{word}': {is_palindrom(word)}")