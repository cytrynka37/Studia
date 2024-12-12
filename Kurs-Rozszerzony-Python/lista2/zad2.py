# Kaja Matuszewska 345951
# Lista 2 zadanie 2
from time import time

memorized = {}

def sudan(n, x, y):
    if (n, x, y) in memorized:
        return memorized[(n, x, y)]
    
    if n == 0:
        memorized[(n, x, y)] = x + y
    elif y == 0:
        memorized[(n, x, y)] = x
    else:
        f = sudan(n, x, y - 1)
        memorized[(n, x, y)] = sudan(n - 1, f, (f + y))

    return memorized[(n, x, y)]

def sudan_no_memo(n, x, y):
    if n == 0:
        return x + y
    elif y == 0:
        return x
    else:
        return sudan_no_memo(n - 1, sudan_no_memo(n, x, y - 1), (sudan_no_memo(n, x, y - 1) + y))

def measure_time(func, n, x, y):
    start_time = time()
    result = func(n, x, y)
    end_time = time()
    return result, end_time - start_time

print("\nTest dla n=0, x=9, y=9")
print("Wersja z memoizacją:")
result, duration = measure_time(sudan, 0, 9, 9)
print(f"Wynik: {result}, Czas wykonania: {duration:.10f} sekund") # 0.0000016689 sekund
print("Wersja bez memoizacji:")
result, duration = measure_time(sudan_no_memo, 0, 9, 9)
print(f"Wynik: {result}, Czas wykonania: {duration:.10f} sekund") # 0.0000007153 sekund
#Wersja bez memoizacji jest szybsza

print("\nTest dla n=1, x=5, y=5")
print("Wersja z memoizacją:")
result, duration = measure_time(sudan, 1, 5, 5)
print(f"Wynik: {result}, Czas wykonania: {duration:.10f} sekund") # 0.0000052452 sekund
print("Wersja bez memoizacji:")
result, duration = measure_time(sudan_no_memo, 1, 5, 5)
print(f"Wynik: {result}, Czas wykonania: {duration:.10f} sekund") # 0.0000057220 sekund
# Wersja z memoizacją szybsza
# Dla n = 1, x = 5 i y = 5 wersja z memoizacją staje się szybsza.
# Przy n = 2, x = 2, y = 2 róznica czasów robi się bardzo duża 
#(dla wersji z memoizacją jest to ~0.0002 sekundy, dla wersji bez to przynajmniej 30 sekund (nie chciało mi się dłużej czekać)