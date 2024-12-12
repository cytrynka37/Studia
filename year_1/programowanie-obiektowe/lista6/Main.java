//Kaja Matuszewska, lista 6 zadanie 1 i 3
//java 22
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.FileInputStream;
import java.io.ObjectInputStream;

public class Main{
    @SuppressWarnings("unchecked")
    public static void main(final String args[]){
        try{
            Buffer<String> buf = new Buffer<String>(3);
            Producer<String> w1 = new Producer<String>(buf); 
            Consumer<String> w2 = new Consumer<String>(buf);
            w1.start();
            w2.start();
            Thread.sleep(12000);
            w1.interrupt();
            w2.interrupt();
            
//zadanie 1
            FileOutputStream fileOutput = new FileOutputStream("file.txt");
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutput);
            objectOutputStream.writeObject(buf);
            objectOutputStream.close();

            FileInputStream fileInputStream = new FileInputStream("file.txt");
            ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
            Buffer<String> r = (Buffer<String>) objectInputStream.readObject();
            objectInputStream.close();

            System.out.println(r.take()); 
            System.out.println(r.take()); 
        }
        catch(Exception e){
            System.err.println(e.getMessage() + e.getStackTrace());
        }
    }
}