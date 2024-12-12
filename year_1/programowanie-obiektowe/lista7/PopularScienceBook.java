//Kaja Matuszewska
//lista 7, zadanie 1 i 2
public class PopularScienceBook extends Book{
    private String field;

    public PopularScienceBook(String title, String author, int publicationYear, String field){
        super(title, author, publicationYear);
        this.field = field;
    }
    
    @Override
    public String toString(){
        return "Książka popularnonaukowa: tytuł = " + super.title + ", autor = " + super.author + ", rok wydania = "
                + super.publicationYear + ", dziedzina = " + this.field;
    }

    public String getField(){
        return field;
    }

    public void setField(String field){
        this.field = field;
    }
}
