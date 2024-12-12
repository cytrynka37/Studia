//Kaja Matuszewska, lista 6 zadanie 1 i 3
//java 22
public class Producer<T> extends Thread{
    private final Buffer<String> buffer;
    public Producer(Buffer<String> buf){
        this.buffer = buf;
    }

    public void run(){
        try{
            int counter = 0;
            while (true){
                String item = "Item" + counter++;
                buffer.put(item);
                System.out.println("Produced: " + item);
                Thread.sleep(1000); 

            }
        } catch (InterruptedException e){
        }
    }
}
    