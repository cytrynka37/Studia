//Kaja Matuszewska, lista 6 zadanie 1 i 3
//java 22
public class Consumer<T> extends Thread{
    private final Buffer<String> buffer;

    public Consumer(Buffer<String> buffer){
        this.buffer = buffer;
    }

    public void run(){
        try{
            while(true){
                String item = buffer.take();
                System.out.println("Consumed: " + item);
                Thread.sleep(2000);
            }
        } catch (InterruptedException e){
        }
    }
}
