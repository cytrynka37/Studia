# Kaja Matuszewska 345951
# lista 3 zadanie 1
import timeit
import math

def is_prime(num):
    if num < 2:
        return False
    if num == 2:
        return True
    if num % 2 == 0:
        return False

    for i in range(3, int(math.sqrt(num)) + 1, 2):
        if num % i == 0:
            return False
            
    return True

def pierwsze_imperatywna(n):
    numbers = []
    for num in range(2, n):
        if is_prime(num):
            numbers.append(num)
    return numbers

def pierwsze_skladana(n):
    return [num for num in range(2, n) if is_prime(num)]

def pierwsze_funkcyjna(n):
    return list(filter(lambda num: is_prime(num), range(2, n)))

def table():
    max_ns = [10, 20, 30, 40, 50, 75, 100, 150, 200]

    print(f"{'n':<10}{'skladana':<15}{'imperatywna':<15}{'funkcyjna':<15}")

    for n in max_ns:
        skladana_time = timeit.timeit(lambda: pierwsze_skladana(n), number=1000)
        imperatywna_time = timeit.timeit(lambda: pierwsze_imperatywna(n), number=1000)
        funkcjna_time = timeit.timeit(lambda: pierwsze_funkcyjna(n), number=1000)

        print(f"{n:<10}{skladana_time:<15.5f}{imperatywna_time:<15.5f}{funkcjna_time:<15.5f}")

table()