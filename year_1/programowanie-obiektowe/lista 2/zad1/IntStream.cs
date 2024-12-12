//Kaja Matuszewska lista 2 zadanie 1
//wersja mcs: 6.12.0.0
using System;
using System.IO;

namespace Zad1{
    public class IntStream
    {
        protected int curr = 0;
        public virtual int Next()
        {
            if(Eos()){
                throw new EndOfStreamException();
            }            
            return curr++;
        }
        public virtual bool Eos()
        {
            if(curr == int.MaxValue) return true;
            return false;
        }
        public virtual void Reset()
        {
            curr = 0;
        }
    }
    public class FibStream : IntStream
    {
        private int prev = 0;
        private int next = 1;
        public override int Next()
        {
            if(Eos()){
                throw new EndOfStreamException();
            }
            prev = curr;
            curr = next;
            next = prev + curr;
            return curr;
        }
        public override bool Eos()
        {
            if(curr >= int.MaxValue - prev) return true;
            return false;
        }
        public override void Reset()
        {
            prev = 0;
            next = 1;
            base.Reset();
        }
    }
    public class RandomStream : IntStream
    {
        Random random = new Random();
        public override int Next()
        {
            if(Eos()){
                throw new EndOfStreamException();
            }
                        
            return random.Next();
        }
        public override bool Eos()
        {
            return false;
        }
        public override void Reset()
        {
            base.Reset();
            random = new Random();
        }
    }

    public class RandomWordStream
    {  
         private FibStream fibStream = new FibStream();
        private RandomStream randomStream = new RandomStream();

        public string Next()
        {
            int length = fibStream.Next();
            char[] word = new char[length];
            for (int i = 0; i < length; i++)
            {
                word[i] = (char)(33 + randomStream.Next() % (126 - 33));
            }
            return new string(word);
        }
    }
}