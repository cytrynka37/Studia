//Kaja Matuszewska, lista 6 zadanie 1 i 3
//java 22
import java.io.Serializable;

public class Buffer<T> implements Serializable{
    private T[] buffer;
    private int head;
    private int tail;

    @SuppressWarnings("unchecked")
    public Buffer(int capacity){
        buffer = (T[]) new Object[capacity];
        head = 0;
        tail = 0;
    }

    public synchronized void put(T element) throws InterruptedException{
        try{
            while ((tail - head) == buffer.length){
                wait();
            }
            buffer[tail % buffer.length] = element;
            tail++;
            notifyAll();
        } finally{
        }
    }

    public synchronized T take() throws InterruptedException{
        try{
            while ((tail - head) == 0){
                wait();
            }
            T elem = buffer[head % buffer.length];
            head = head + 1;
            notifyAll();
            return elem;
        } finally{
        }
    }
}
