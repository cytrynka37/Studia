/* Kaja Matuszewska Lista 3 Zadanie 1
wersja mcs: 6.12.0.0
Uzyte komendy:
mcs -target:library Lista.cs
mcs -reference:Lista.dll Program - lista.cs
*/
using System;
using Lista;

namespace Program{
    class Program
        {
        static void Main()
        {
            Lista<int> lista = new();
            lista.Push_front(4);
            lista.Push_front(5);
            lista.Push_back(6);

            try
            {
                int removedValue = lista.Pop_front();
                Console.WriteLine("Usunięta wartość: " + removedValue);
            }
            catch (InvalidOperationException ex)
            {
                Console.WriteLine(ex.Message);
            }

            try
            {
                int removedValue = lista.Pop_back();
                Console.WriteLine("Usunięta wartość: " + removedValue);
            }
            catch (InvalidOperationException ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}