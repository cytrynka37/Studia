//Kaja Matuszewska
//lista 7, zadanie 1 i 2
public class Literature extends Book{
    private String genre;

    public Literature(String title, String author, int publicationYear, String genre){
        super(title, author, publicationYear);
        this.genre = genre;
    }
    
    @Override
    public String toString(){
        return "Literatura piękna: tytuł = " + super.title + ", autor = " + super.author + ", rok wydania = "
                + super.publicationYear + ", dziedzina = " + this.genre;
    }

    public String getGenre(){
        return genre;
    }

    public void setGenre(String genre){
        this.genre = genre;
    }
}