# Kaja Matuszewska 345951
# lista 3 zadanie 5
import itertools

def cryptarithm(words, operator):
    unique_letters = set("".join(words))

    for digits in itertools.permutations(range(10), len(unique_letters)):
        letter_to_digit = dict(zip(unique_letters, digits))
        if any(letter_to_digit[word[0]] == 0 for word in words):
            continue

        word_numbers = [int("".join(str(letter_to_digit[letter]) for letter in word)) for word in words]

        operations = {
            "+": lambda x, y: x + y,
            "-": lambda x, y: x - y,
            "*": lambda x, y: x * y,
            "/": lambda x, y: x / y if y != 0 else None
        }

        if operations[operator](word_numbers[0], word_numbers[1]) == word_numbers[2]:
            yield letter_to_digit

def print_solutions (words, operator):
    print(f"{words[0]} {operator} {words[1]} = {words[2]}")
    for solution in cryptarithm(words, operator):
        print(solution)

print_solutions(["OSAKA", "KIOTO", "TOKIO"], "+")
print_solutions(["T", "T", "MT"], "*")
print_solutions(["MW", "W", "W"], "/")