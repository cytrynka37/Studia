// Kaja Matuszewska
// lista 1 zadanie 1
// konieczne jest użycie flagi -lm
// wersja kompilatora gcc 13.2.1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

typedef enum Typ{
    TROJKAT,
    KOLO,
    KWADRAT
} Typ;

typedef struct Figura{
    float x;
    float y;
    float a;
    float b;
    float c;
    Typ typ;
} Figura;

Figura* new_square(float x, float y, float a){
    if (a <= 0){
        printf("Zle dane!\n");
        return NULL;
    }

    Figura *f = (Figura *)malloc(sizeof(Figura));
    if (f == NULL){
        printf("Blad alokacji pamieci\n");
        return NULL;
    }

    f->x = x;
    f->y = y;
    f->a = a;
    f->typ = KWADRAT;
    return f;
}

Figura* new_triangle(float x, float y, float a, float b, float c){
    if (a + b <= c || a + c <= b || b + c <= a || a <= 0 || b <= 0 || c <= 0){
        printf("Zle dane!\n");
        return NULL;
    }

    Figura *f = (Figura *)malloc(sizeof(Figura));
    if (f == NULL){
        printf("Blad alokacji pamieci\n");
        return NULL;
    }

    f->x = x;
    f->y = y;
    f->a = a;
    f->b = b;
    f->c = c;
    f->typ = TROJKAT;
    return f;
}

Figura* new_circle(float x, float y, float r){
    if (r <= 0){
        printf("Zle dane!\n");
        return NULL;
    }

    Figura *f = (Figura *)malloc(sizeof(Figura));
    if (f == NULL){
        printf("Blad alokacji pamieci\n");
        return NULL;
    }

    f->x = x;
    f->y = y;
    f->a = r;
    f->typ = KOLO;
    return f;
}

float pole(Figura* f){
    if (f == NULL){
        printf("Figura nie istnieje\n");
        return 0;
    }    
    switch(f->typ){
        case KWADRAT:
            return f->a * f->a;

        case TROJKAT:
            float p = (f->a + f->b + f->c) / 2.0;
            return sqrt(p * (p - f->a) * (p - f->b) * (p - f->c));

        case KOLO:
            return PI * f->a * f->a;
    }
    return 0;
}

void przesun(Figura* f, float x, float y){
    if (f == NULL){
        printf("Figura nie istnieje\n");
        return;
    }    
    f->x += x;
    f->y += y;
}

void show(Figura* f){
    if (f == NULL){
        printf("Figura nie istnieje\n");
        return;
    }
    switch(f->typ){
        case KWADRAT:
            printf("Typ: kwadrat; ");
            break;
        case TROJKAT:
            printf("Typ: trojkat; ");
            break;
        case KOLO:
            printf("Typ: kolo; ");
            break;

    }
    printf("Polozenie: (%f, %f)\n", f->x, f->y);
}

float sumapol(Figura* f[], int size){
    float suma = 0;
    for (int i = 0; i < size; i++){
        if (f[i] == NULL){
            continue;
        }
        suma += pole(f[i]);
    }

    return suma;
}
//Jesli chcielibysmy dodac trapez do naszych figur, to musielibysmy dodac do struktury Figura dwie dodatkowe zmienne (np. d oraz h, wtedy
//w przypadku trapezu zmienne a i b to podstawy, c i d to ramiona, h to wysokosc), dodac funkcje tworzaca trapez, a takze zmodyfikowac 
//funkcje show i pole dodajac do nich case TRAPEZ, pole mozna wyliczyc oczywiscie ze wzoru (a + b)*h/2.
int main(){
    Figura* f[3];
    f[0] = new_square(4.0, 3.0, 5.0);
    f[1] = new_triangle(1.0, 2.0, 3.0, 3.0, 3.0);
    f[2] = new_circle(-1.0, -3.0, 6.0);

    show(f[0]);
    przesun(f[0], 2.0, 2.0);
    show(f[0]);
    printf("Pola 1, 2 i 3 figury (w kolejnosci): %f, %f, %f\n", pole(f[0]), pole(f[1]), pole(f[2]));
    printf("Suma pol: %f\n", sumapol(f, 3));

    for (int i = 0; i < 3; i++) {
        free(f[i]);
    }
    return 0;
}