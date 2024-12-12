//Kaja Matuszewska lista 2 zadanie 1
//wersja mcs: 6.12.0.0
using System;
using System.IO;

namespace Zad1
{
    class Program
    {
        static void Main(string[] args)
        {
            IntStream istr = new IntStream();
            Console.WriteLine("Liczby: ");
            for(int i = 0; i < 10; i++){
                Console.Write(istr.Next() + " "); 
            }
            Console.WriteLine();

            FibStream fib = new FibStream();
            Console.WriteLine("Liczby Fibonacciego: ");
            for(int i = 0; i < 10; i++){
                Console.Write(fib.Next() + " "); 
            }
            Console.WriteLine();

            RandomWordStream rws = new RandomWordStream();
            Console.WriteLine("Stringi dlugosci kolejnych liczb Fibonacciego: ");
            for(int i = 0; i < 10; i++){
                Console.Write(rws.Next() + " "); 
            }
            Console.WriteLine();

            fib.Reset();
            Console.WriteLine("Liczby Fibonacciego po resecie: ");
            for(int i = 0; i < 10; i++){
                Console.Write(fib.Next() + " "); 
            }
            Console.WriteLine();
        }
    }
}