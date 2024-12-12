#Kaja Matuszewska 345951
#Lista 1 Zadanie 1

from decimal import Decimal

def vat_faktura(lista):
    vat = Decimal(0.23) if (type(lista[0]) == Decimal) else 0.23
    return vat * sum(lista)

def vat_paragon(lista):
    vat = Decimal(0.23) if (type(lista[0]) == Decimal) else 0.23
    return sum(vat * element for element in lista)

zakupy = [1.5, 2.4, 3.6, 14.2, 19.6]
falszywa_lista = [1.5, 2.4, 3.6, 14.0002, 0.000000019]
decimal_falszywa_lista = [Decimal(str(x)) for x in falszywa_lista]

for lista in [zakupy, falszywa_lista, decimal_falszywa_lista]:
    print(f"{lista}: {vat_faktura(lista) == vat_paragon(lista)}")