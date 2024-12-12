//Kaja Matuszewska
//lista 7, zadanie 1 i 2
import javax.swing.*;
import java.awt.*;

public class BookEditor extends JComponent{
    private JTextField titleField;
    private JTextField authorField;
    private JTextField publicationYearField;
    private JLabel genreLabel;
    private JTextField genreField;
    private JLabel fieldLabel;
    private JTextField fieldField;

    public BookEditor(){
        setLayout(new GridLayout(0, 2));

        add(new JLabel("Tytuł:"));
        titleField = new JTextField();
        add(titleField);

        add(new JLabel("Autor:"));
        authorField = new JTextField();
        add(authorField);

        add(new JLabel("Rok wydania:"));
        publicationYearField = new JTextField();
        add(publicationYearField);
    }

    public void setGenreVisible(boolean visible){
        if (visible){
            if (genreLabel == null){
                genreLabel = new JLabel("Gatunek:");
                add(genreLabel);
                genreField = new JTextField();
                add(genreField);
            }

        } else{
            if (genreLabel != null){
                remove(genreLabel);
                genreLabel = null;
            }
            if (genreField != null){
                remove(genreField);
                genreField = null;
            }
        }
        revalidate();
        repaint();
    }

    public void setFieldVisible(boolean visible){
        if (visible){
            if (fieldLabel == null){
                fieldLabel = new JLabel("Dziedzina:");
                add(fieldLabel);
                fieldField = new JTextField();
                add(fieldField);
            }

        } else{
            if (fieldLabel != null){
                remove(fieldLabel);
                fieldLabel = null;
            }
            if (fieldField != null){
                remove(fieldField);
                fieldField = null;
            }
        }
        revalidate();
        repaint();
    }

    public String getTitle(){
        return titleField.getText();
    }

    public void setTitle(String title){
        titleField.setText(title);
    }

    public String getAuthor(){
        return authorField.getText();
    }

    public void setAuthor(String author){
        authorField.setText(author);
    }

    public int getPublicationYear(){
        try{
            return Integer.parseInt(publicationYearField.getText());
        } catch (NumberFormatException e){
            return 0;
        }
    }

    public void setPublicationYear(int publicationYear){
        publicationYearField.setText(String.valueOf(publicationYear));
    }

    public String getGenre(){
        return genreField != null ? genreField.getText() : null;
    }

    public void setGenre(String genre){
        if (genreField != null){
            genreField.setText(genre);
        }
    }

    public String getField(){
        return fieldField != null ? fieldField.getText() : null;
    }

    public void setField(String field){
        if (fieldField != null) {
            fieldField.setText(field);
        }
    }
}
