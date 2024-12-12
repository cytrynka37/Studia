//Kaja Matuszewska
//lista 7, zadanie 1 i 2
import java.io.Serializable;

public class Book implements Serializable{
    protected String title;
    protected String author;
    protected int publicationYear;

    public Book(String title, String author, int publicationYear){
        this.title = title;
        this.author = author;
        this.publicationYear = publicationYear;
    }

    public String toString(){
        return "Książka: tytuł = " + this.title + ", autor = " + this.author + ", rok wydania = " + this.publicationYear;
    }

    public String getTitle(){
        return title;
    }

    public void setTitle(String title){
        this.title = title;
    }

    public String getAuthor(){
        return author;
    }

    public void setAuthor(String author){
        this.author = author;
    }

    public int getPublicationYear(){
        return publicationYear;
    }

    public void setPublicationYear(int publicationYear){
        this.publicationYear = publicationYear;
    }
}
