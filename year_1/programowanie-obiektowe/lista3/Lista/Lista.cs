/* Kaja Matuszewska Lista 3 Zadanie 1
wersja mcs: 6.12.0.0
Uzyte komendy:
mcs -target:library Lista.cs
mcs -reference:Lista.dll Program - lista.cs
*/
using System;

namespace Lista
{
    public class Element<T>
    {
        public T Value;
        public Element<T>? Next;
        public Element<T>? Previous;

        public Element(T value){
            Value = value;
            Next = null;
            Previous = null;
        }
    }

    public class Lista<T>
    {
        protected Element<T>? head;
        protected Element<T>? tail;

        public Lista()
        {
            head = null;
            tail = null;
        }

        public void Push_front(T elem)
        {
            Element<T> element = new(elem);
            if (head == null)
            {
                head = element;
                tail = element;
                return;
            }
            element.Next = head;
            head.Previous = element;
            head = element;
        }

        public void Push_back(T elem)
        {
            Element<T> element = new(elem);
            if (tail == null)
            {
                head = element;
                tail = element;
                return;
            }
            element.Previous = tail;
            tail.Next = element;
            tail = element;
        }

        public bool IsEmpty()
        {
            if(head == null) return true;
            return false;
        }

        public T Pop_front()
        {
            if (IsEmpty()) throw new InvalidOperationException("Lista jest pusta.");

            T val = head!.Value;
            head = head.Next;
            if(head == null) tail = null;
            else head.Previous = null;
            return val;
        }
        public T Pop_back()
        {
            if (IsEmpty()) throw new InvalidOperationException("Lista jest pusta.");

            T val = tail!.Value;
            tail = tail.Previous;
            if(tail == null) head = null;
            else tail.Next = null;
            return val;
        }
    }
}