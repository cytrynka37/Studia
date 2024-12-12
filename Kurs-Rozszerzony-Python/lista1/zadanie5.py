#Kaja Matuszewska 345951
#Lista 1 Zadanie 5

def two_words_prefix(w1, w2):
    prefix = ""
    for i in range(min(len(w1), len(w2))):
        if w1[i] == w2[i]:
            prefix += w1[i]
        else:
            break
    return prefix

def common_prefix(words):
    words = [word.lower() for word in words]
    longest_prefix = ""
    prefixes = {}

    for i in range(len(words)):
        for j in range(i + 1, len(words)):
            prefix = two_words_prefix(words[i], words[j])
            if prefix in prefixes:
                prefixes[prefix] += 1
            else:
                prefixes[prefix] = 1
    
    for prefix, count in prefixes.items():
        if len(prefix) > len(longest_prefix) and count >= 2:
            longest_prefix = prefix

    return longest_prefix


words = ["Cyprian", "cyberotoman", "cynik", "ceniąc", "czule"]
print(f"wspolny najdluzszy prefiks dla {words}: {common_prefix(words)}")

