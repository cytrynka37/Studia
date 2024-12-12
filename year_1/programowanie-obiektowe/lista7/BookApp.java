import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class BookApp extends JFrame{
    private BookEditor bookEditor;
    private JComboBox<String> bookTypeComboBox;

    public BookApp(Book book) {
        setTitle("Edytor książek");
        setSize(450, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setLayout(new BorderLayout());

        JPanel typePanel = new JPanel();
        typePanel.add(new JLabel("Wybierz typ książki:"));
        String[] bookTypes = {"Książka", "Literatura piękna", "Książka popularnonaukowa"};
        bookTypeComboBox = new JComboBox<>(bookTypes);
        typePanel.add(bookTypeComboBox);
        add(typePanel, BorderLayout.NORTH);


        bookEditor = new BookEditor();
        add(bookEditor, BorderLayout.CENTER);

        JButton saveButton = new JButton("Zapisz");
        saveButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                saveBook();
            }
        });
        add(saveButton, BorderLayout.SOUTH);

        bookEditor.setTitle(book.getTitle());
        bookEditor.setAuthor(book.getAuthor());
        bookEditor.setPublicationYear(book.getPublicationYear());

        if (book instanceof Literature){
            Literature literature = (Literature) book;
            bookTypeComboBox.setSelectedItem("Literatura piękna");
            bookEditor.setGenreVisible(true);   
            bookEditor.setGenre(literature.getGenre());
        } else if (book instanceof PopularScienceBook){
            PopularScienceBook popularScienceBook = (PopularScienceBook) book;
            bookTypeComboBox.setSelectedItem("Książka popularnonaukowa");
            bookEditor.setFieldVisible(true);
            bookEditor.setField(popularScienceBook.getField());
        } else {
            bookTypeComboBox.setSelectedItem("Książka");
        }

        bookTypeComboBox.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                String selectedType = (String) bookTypeComboBox.getSelectedItem();

                if (selectedType.equals("Literatura piękna")){
                    bookEditor.setGenreVisible(true);
                } else{
                    bookEditor.setGenreVisible(false);
                }

                if (selectedType.equals("Książka popularnonaukowa")){
                    bookEditor.setFieldVisible(true);
                } else{
                    bookEditor.setFieldVisible((false));
                }
            }
        });

        setVisible(true);
    }

    private void saveBook(){
        String title = bookEditor.getTitle();
        String author = bookEditor.getAuthor();
        int publicationYear = bookEditor.getPublicationYear();

        if (title.isEmpty() || author.isEmpty() || publicationYear == 0) {
            JOptionPane.showMessageDialog(this, "Proszę wypełnić wszystkie pola poprawnie.");
        } else {
            Book book;
            String bookType = (String) bookTypeComboBox.getSelectedItem();
            if (bookType.equals("Literatura piękna")){
                String genre = bookEditor.getGenre();
                book = new Literature(title, author, publicationYear, genre);
            } else if (bookType.equals("Książka popularnonaukowa")){
                String field = bookEditor.getField();
                book = new PopularScienceBook(title, author, publicationYear, field);
            } else{
                book = new Book(title, author, publicationYear);
            }

            try (FileOutputStream fileOut = new FileOutputStream(Main.path);
                ObjectOutputStream objectOut = new ObjectOutputStream(fileOut)){
                objectOut.writeObject(book);
                JOptionPane.showMessageDialog(this, "Zapisano książkę do pliku " + Main.path);
            } catch (IOException e){
                e.printStackTrace();
                JOptionPane.showMessageDialog(this, "Wystąpił błąd podczas zapisywania książki do pliku.");
            }    
        }
    }
}
