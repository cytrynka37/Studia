# Kaja Matuszewska 345951
# Lista 2 zadanie 4
import requests

def simplify_sentence(sentence, max_word_length, max_number_of_words):
    new_sentence = []
    for word in sentence.split():
        letter_count = sum(1 for c in word if c.isalpha())
        if letter_count < max_word_length:
            new_sentence.append(word)

    return " ".join(new_sentence[:max_number_of_words])

def simplify_text(text, max_word_length, max_number_of_words):
    sentences = []
    curr_sentence = ""
    for c in text:
        if c in ".!?":
            sentences.append(curr_sentence)
            sentences.append(c)
            curr_sentence = ""
        else: 
            curr_sentence += c

    simplified_sentences = []
    for i in range (0, len(sentences) - 1, 2):
        new_sentence = simplify_sentence(sentences[i], max_word_length, max_number_of_words)
        symbol = sentences[i + 1]
        simplified_sentences.append(new_sentence + symbol)

    return " ".join(simplified_sentences)

response = requests.get("https://wolnelektury.pl/media/book/txt/orwell-rok-1984.txt")
text = response.text
print("Tekst na początku: ", text[1535:2000])
print("\nTekst po uproszczeniu:\n", simplify_text(text[1535:2000], 10, 5))