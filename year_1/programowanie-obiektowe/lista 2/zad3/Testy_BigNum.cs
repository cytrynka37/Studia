//Kaja Matuszewska lista 2 zadanie 3
//wersja mcs: 6.12.0.0
using System;
using System.IO;

namespace Zad3
{
    class Program
    {
        static void Main(string[] args)
        {
            BigNum num1 = new BigNum(2100000000); 
            BigNum num2 = new BigNum(-987654321); 
            
            Console.Write("Num1: ");
            num1.Print();
            Console.Write("Num2: ");
            num2.Print();
            Console.WriteLine();

            num1.Subtract(num2);
            Console.WriteLine("Wartość po odejmowaniu (num1 - num2):"); // 2100000000 - (-987654321) = 3087654321
            Console.Write("Num1: ");
            num1.Print();

            num1.Add(num2);
            Console.WriteLine("Wartość po dodawaniu (num1 + num2):"); // 3087654321 - (-987654321) = 2100000000
            Console.Write("Num1: ");
            num1.Print();
            Console.WriteLine();
            Console.WriteLine();

            BigNum num3 = new BigNum(-2147483647); 
            BigNum num4 = new BigNum(-2147483647);
            Console.Write("Num3: ");
            num3.Print();
            Console.Write("Num4: ");
            num4.Print();
            Console.WriteLine();

            num3.Add(num4);
            Console.WriteLine("Wartość po dodawaniu (num3 + num4:"); // -2147483647 + (-2147483647) = -4294967294
            Console.Write("Num3: ");
            num3.Print();

            num3.Add(num4);
            Console.WriteLine("Wartość po dodawaniu (num3 + num4):"); // -4294967294 + (-2147483647) = -6442450941
            Console.Write("Num3: ");
            num3.Print();

            num3.Subtract(num4);
            Console.WriteLine("Wartość po odejmowaniu (num3 - num4):"); // -6442450941 - (-2147483647) = -4294967294
            Console.Write("Num3: ");
            num3.Print();
            Console.WriteLine();
        }
    }
}