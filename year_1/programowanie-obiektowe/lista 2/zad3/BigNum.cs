﻿//Kaja Matuszewska lista 2 zadanie 3
//wersja mcs: 6.12.0.0
using System;
using System.IO;
using System.Text;

namespace Zad3{
    public class BigNum
    {
        private int[] digits;
        private int size;
        private bool isNegative;

        private bool isChanged;
        public BigNum(int num)
        {    
            isNegative = num < 0;
            if(isNegative) num *= -1;
            int size = 0;
            int tempNum = num;

            while (tempNum != 0)
            {
                tempNum /= 10;
                size++;
            }

            this.size = size;
            digits = new int[size];
            isChanged = false;

            for (int i = size - 1; i >= 0; i--)
            {
                digits[i] = num % 10;
                num /= 10;

            }
        }
        public void Add(BigNum secondNumber)
        {
            if (isNegative && secondNumber.isNegative == false){
                isNegative = false;
                isChanged = true;
                this.Subtract(secondNumber);
                return;
            }

            if (isNegative == false && secondNumber.isNegative){
                secondNumber.isNegative = false;
                secondNumber.isChanged = true;
                this.Subtract(secondNumber);
                return;
            }

            int a = 0;
            for (int i = size - 1; i >= 0; i--)
            {
                digits[i] += (secondNumber.size - size + i < 0 ? 0 : secondNumber.digits[secondNumber.size - size + i]) + a;
                a = digits[i] / 10;
                if(i != 0) digits[i] %= 10;
            }

            if(isChanged) isNegative = true;
            if(secondNumber.isChanged) secondNumber.isNegative = true;
            isChanged = false;
            secondNumber.isChanged = false;
        }

        public void Subtract(BigNum secondNumber)
        {
            if (isNegative && secondNumber.isNegative == false){
                Console.WriteLine("tu");
                isNegative = false;
                isChanged = true;
                this.Add(secondNumber);
                return;
            }

            if (isNegative == false && secondNumber.isNegative){
                secondNumber.isNegative = false;
                secondNumber.isChanged = true;
                this.Add(secondNumber);
                return;
            }

            if (isNegative && secondNumber.isNegative){
                BigNum help = secondNumber;
                help.isNegative = false;
                isNegative = false;
                isChanged = true;
                this.Subtract(help);
                return;            
            }
            
            int diff = 0;
            int a = 0;
            bool isSecondBigger = secondNumber.size > size || (secondNumber.size == size && secondNumber.digits[0] > digits[0]);    
            for (int i = isSecondBigger ? secondNumber.size - 1 : size - 1; i >= 0; i--)
            {
                if(isSecondBigger){
                    diff = secondNumber.digits[i] - (size - secondNumber.size + i < 0 ? 0 : digits[size - size + i]) - a;
                }
                else {
                    diff = digits[i] - (secondNumber.size - size + i < 0 ? 0 : secondNumber.digits[secondNumber.size - size + i]) - a;
                }

                if (diff < 0)
                {
                    diff += 10;
                    a = 1;
                }
                else a = 0;

                digits[i] = diff;
            }

            if(isSecondBigger ^ isChanged){
                isNegative = true;
            }
            if(isChanged) isNegative = true;
            if(secondNumber.isChanged) secondNumber.isNegative = true;
            isChanged = false;
            secondNumber.isChanged = false;         
        }

        public void Print()
        {
            bool leadingZero = true;
            StringBuilder sb = new StringBuilder();
            if (isNegative) sb.Append('-');
            for (int i = 0; i < size; i++)
            {
                if (leadingZero && digits[i] != 0)
                {
                    leadingZero = false;
                }
                if (!leadingZero)
                {
                    sb.Append(digits[i]);
                }
            }
            if (sb.Length == 0)
            {
                Console.WriteLine("0");
            }
            else
            {
                Console.WriteLine(sb);
            }
        }
    }
}