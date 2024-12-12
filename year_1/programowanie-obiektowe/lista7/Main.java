//Kaja Matuszewska
//lista 7, zadanie 1 i 2
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Main{
    static public String path;

    public static void usage(){
        System.err.println("Użycie: java Main <nazwa_pliku> <nazwa_klasy_obiektu>");
        System.err.println("Obiekty: Book, Literature, PopularScienceBook");
    }

    public static void main(String[] args){
        if(args.length != 2){
            usage();
            return;
        }

        Book book;
        path = args[0];

        try(FileInputStream fileIn = new FileInputStream(path);
            ObjectInputStream objectIn = new ObjectInputStream(fileIn)){
            
            if ("Book".equals(args[1])) book = (Book) objectIn.readObject();
            else if ("Literature".equals(args[1])) book = (Literature) objectIn.readObject();
            else if ("PopularScienceBook".equals(args[1])) book = (PopularScienceBook) objectIn.readObject();                
            else return;
        } 
        catch (FileNotFoundException er){
            switch(args[1]){
                case "Book":
                    book = new Book("Tytuł", "Autor", 0);
                    break;
                case "Literature":
                    book = new Literature("Tytuł", "Autor", 0, "Gatunek");
                    break;
                case "PopularScienceBook":
                    book = new PopularScienceBook("Tytuł", "Autor", 0, "Gatunek");
                    break;
                default:
                    usage();
                    return;
            }

            try(FileOutputStream fileOut = new FileOutputStream(path);
                ObjectOutputStream objectOut = new ObjectOutputStream(fileOut)){
             
                objectOut.writeObject(book);

            } catch(Exception e){
                System.err.println("Nie udało się utworzyć nowego pliku.");
                e.printStackTrace();
                return;
            }

        } catch (Exception e){
            System.err.println("Nie udało się wczytać pliku.");
            e.printStackTrace();
            return;
        }

        try{
            new BookApp(book);
        } catch(Exception e){
            e.printStackTrace();
            System.err.println("Nie udało się utworzyć okienka do edycji.");
            return;
        } 
    }
}