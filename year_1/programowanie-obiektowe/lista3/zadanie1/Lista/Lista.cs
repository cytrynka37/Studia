using System;

namespace Lista{
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

    public class List<T>
    {
        private Element<T>? head;
        private Element<T>? tail;

        public List(){
            head = null;
            tail = null;
        }

        public void Push_front(T elem){
            Element<T> element = new Element<T>(elem);
            if (head == null){
                head = element;
                tail = element;
                return;
            }
            element.Next = head;
            head.Previous = element;
            head = element;
        }

        public void Push_back(T elem){
            Element<T> element = new Element<T>(elem);
            if (tail == null){
                head = element;
                tail = element;
                return;
            }
            element.Previous = tail;
            tail.Next = element;
            tail = element;
        }

        public bool IsEmpty(){
            if(head == null) return true;
            return false;
        }

        public T Pop_front(){
            if (IsEmpty()){
                throw new InvalidOperationException("Lista jest pusta - nie ma co usuwać.");
            }

            T val = head!.Value;
            head = head.Next;
            if(head == null) tail = null;
            else head.Previous = null;

            return val;
        }
        public T Pop_back(){
            if (IsEmpty()){
                throw new InvalidOperationException("Lista jest pusta - nie ma co usuwać.");
            }

            T val = tail!.Value;
            tail = tail.Previous;
            if(tail == null) head = null;
            else tail.Next = null;

            return val;
        }
    }
    class Program
        {
        static void Main(string[] args)
        {
            List<int> lista = new List<int>();

            try
            {
                int removedValue = lista.Pop_front();
                Console.WriteLine("Usunięta wartość: " + removedValue);
            }
            catch (InvalidOperationException ex)
            {
                Console.WriteLine(ex.Message);
            }

            lista.Push_front(4);
            lista.Push_front(5);
            lista.Push_front(5);

            try
            {
                int removedValue = lista.Pop_front();
                Console.WriteLine("Usunięta wartość: " + removedValue);
            }
            catch (InvalidOperationException ex)
            {
                Console.WriteLine(ex.Message);
            }

        }
    }
}