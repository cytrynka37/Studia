//Kaja Matuszewska
//lista 1 zadanie 2
// wersja kompilatora gcc 13.2.1
#include <stdio.h>
#include <stdlib.h>

typedef struct Ulamek{
    int num;
    int denom;
} Ulamek;


int gcd(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// Funkcja do skracania ułamka
void skracanie(int *num, int *denom){
    int d = gcd(*num, *denom);
    *num /= d;
    *denom /= d;
}

Ulamek* nowy_ulamek(int num, int denom){
    skracanie(&num, &denom);
    Ulamek* ul = (Ulamek*)malloc(sizeof(Ulamek));
    if (ul == NULL){
        printf("Blad alokacji pamieci\n");
        return NULL;
    }
    ul->num = num;
    ul->denom = denom;
    return ul;
}

void show(Ulamek* ul){
    printf("%d/%d\n", ul->num, ul->denom);
}

//Operacje arytmetyczne - tworzenie nowego ulamka z wynikiem
Ulamek* addition_new(Ulamek* ul1, Ulamek* ul2){
    int num = ul1->denom * ul2->num + ul2->denom * ul1->num;
    int denom = ul1->denom * ul2->denom;
    return nowy_ulamek(num, denom);
}

Ulamek* subtraction_new(Ulamek* ul1, Ulamek* ul2){
    int num = ul2->denom * ul1->num - ul1->denom * ul2->num;
    int denom = ul1->denom * ul2->denom;
    return nowy_ulamek(num, denom);
}

Ulamek* multiplication_new(Ulamek* ul1, Ulamek* ul2){
    int num = ul1->num * ul2->num;
    int denom = ul1->denom * ul2->denom;
    return nowy_ulamek(num, denom);
}

Ulamek* division_new(Ulamek* ul1, Ulamek* ul2){
    int num = ul1->num * ul2->denom;
    int denom = ul1->denom * ul2->num;
    return nowy_ulamek(num, denom);
}

//Operacje arytmetyczne - zamiana drugiego ulamka
void addition(Ulamek* ul1, Ulamek* ul2){
    ul2->num = ul1->denom * ul2->num + ul2->denom * ul1->num;
    ul2->denom = ul1->denom * ul2->denom;
    skracanie(&ul2->num, &ul2->denom);
}

void subtraction(Ulamek* ul1, Ulamek* ul2){
    ul2->num = ul2->denom * ul1->num - ul1->denom * ul2->num;
    ul2->denom = ul1->denom * ul2->denom;
    skracanie(&ul2->num, &ul2->denom);
}

void multiplication(Ulamek* ul1, Ulamek* ul2){
    ul2->num = ul1->num * ul2->num;
    ul2->denom = ul1->denom * ul2->denom;
    skracanie(&ul2->num, &ul2->denom);
}

void division(Ulamek* ul1, Ulamek* ul2){
    int temp = ul2->num;
    ul2->num = ul1->num * ul2->denom;
    ul2->denom = ul1->denom * temp;
    skracanie(&ul2->num, &ul2->denom);
}


int main(){
    Ulamek* ul1 = nowy_ulamek(1, 4);
    Ulamek* ul2 = nowy_ulamek(1, 4);
    Ulamek* result = addition_new(ul1, ul2);
    show(ul2);
    addition(ul1, ul2);
    show(result);
    show(ul2);

    free(ul1);
    free(ul2);
    free(result);
    return 0;
}