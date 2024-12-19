from sqlalchemy import Integer, ForeignKey, String, create_engine
from sqlalchemy.orm import relationship, mapped_column, validates, DeclarativeBase, sessionmaker
from datetime import datetime, timedelta
import argparse
import json

class Base(DeclarativeBase):
    pass

class Book(Base):
    __tablename__ = "Books"
    id = mapped_column(Integer, primary_key=True)
    title = mapped_column(String)
    author = mapped_column(String)
    year = mapped_column(Integer)
    loan = relationship("Loan", back_populates="book")

class Friend(Base):
    __tablename__ = "Friends"
    id = mapped_column(Integer, primary_key=True)
    name = mapped_column(String)
    email = mapped_column(String)
    loan = relationship("Loan", back_populates="friend")

class Loan(Base):
    __tablename__ = "Loans"
    id = mapped_column(Integer, primary_key=True)
    book_id = mapped_column(Integer, ForeignKey('Books.id'))
    friend_id = mapped_column(Integer, ForeignKey('Friends.id'))
    loan_date = mapped_column(String)
    return_date = mapped_column(String)
    book = relationship("Book", back_populates="loan")
    friend = relationship("Friend", back_populates="loan")

    @validates("loan_date", "return_date")
    def validate_date(self, key, value):
        try:
            datetime.strptime(value, "%Y-%m-%d")
        except ValueError:
            raise ValueError(f"Invalid date format for {key}. Use YYYY-MM-DD.")
        return value

def add_book(session, title, author, year):
    book = Book(title=title, author=author, year=year)
    session.add(book)
    session.commit()
    print(f"Added book: {title} by {author} ({year})")

def loan_book(session, book_id, friend_id, date):
    try:
        existing_loan = session.query(Loan).filter(
            Loan.book_id == book_id
        ).first()
        
        if existing_loan:
            print(f"Error: Book ID {book_id} is already loaned out.")
            return
        
        loan_date = datetime.strptime(date, "%Y-%m-%d")
        return_date = loan_date + timedelta(days=30)
        loan = Loan(
            book_id=book_id, 
            friend_id=friend_id, 
            loan_date=date,
            return_date=return_date.strftime("%Y-%m-%d")
        )
        session.add(loan)
        session.commit()
        print(f"Loaned book {book_id} to friend {friend_id} on {date}, return date: {return_date.strftime('%Y-%m-%d')}")
    
    except ValueError as e:
        print(f"Error with date format: {e}")

def return_book(session, loan_id):
    loan = session.query(Loan).filter_by(id=loan_id).first()
    if loan:
        session.delete(loan)
        session.commit()
        print(f"Loan {loan_id} has been successfully removed.")
    else:
        print(f"Loan {loan_id} not found.")

def list_books(session):
    books = session.query(Book).all()
    for book in books:
        print(f"ID: {book.id}, Title: {book.title}, Author: {book.author}, Year: {book.year}")

def list_friends(session):
    friends = session.query(Friend).all()
    for friend in friends:
        print(f"ID: {friend.id}, Name: {friend.name}, Email: {friend.email}")

def list_loans(session):
    loans = session.query(Loan).all()
    for loan in loans:
        print(f"Loan ID: {loan.id}, Book ID: {loan.book_id}, Friend ID: {loan.friend_id}, Loan Date: {loan.loan_date}, Return Date: {loan.return_date}")

def initialize_database(engine):
    Base.metadata.create_all(engine)
    Session = sessionmaker(bind=engine)
    session = Session()
    
    try:
        with open("dane.json", "r") as file:
            data = json.load(file)
            for book in data.get("books", []):
                existing_book = session.query(Book).filter_by(
                    title=book["title"], 
                    author=book["author"], 
                    year=book["year"]
                ).first()
                if not existing_book:
                    session.add(Book(**book))
            
            for friend in data.get("friends", []):
                existing_friend = session.query(Friend).filter_by(
                    name=friend["name"], 
                    email=friend["email"]
                ).first()
                if not existing_friend:
                    session.add(Friend(**friend))
        
        session.commit()
    except Exception as e:
        print(f"Error loading test data: {e}")
    finally:
        session.close()


def main():
    engine = create_engine("sqlite:///library.db")
    initialize_database(engine)
    Session = sessionmaker(bind=engine)
    session = Session()

    parser = argparse.ArgumentParser(description="Manage library system")
    subparsers = parser.add_subparsers(dest="command")

    list_parser = subparsers.add_parser("list", help="List of chosen entity")
    list_parser.add_argument("--books", action="store_true", help="List of books")
    list_parser.add_argument("--friends", action="store_true", help="List of friends")
    list_parser.add_argument("--loans", action="store_true", help="List of loans")

    add_parser = subparsers.add_parser("add", help="Add a new book")
    add_parser.add_argument("--title", help="Title of the book")
    add_parser.add_argument("--author", help="Author of the book")
    add_parser.add_argument("--year", help="Year of publication")

    loan_parser = subparsers.add_parser("loan", help="Loan a book")
    loan_parser.add_argument("--book_id", type=int, help="ID of the book to loan")
    loan_parser.add_argument("--friend_id", type=int, help="ID of the friend to loan a book to")
    loan_parser.add_argument("--date", type=str, help="Date of the loan")

    return_parser = subparsers.add_parser("return", help="Return a book")
    return_parser.add_argument("--loan_id", type=int, help="ID of the loan to return")

    args = parser.parse_args()

    if args.command == "list":
        if args.books:
            list_books(session)
        elif args.friends:
            list_friends(session)
        elif args.loans:
            list_loans(session)
        else:
            print("Error: --books, --friends, or --loans is required")
    
    elif args.command == "add":
        if not args.title or not args.author or not args.year:
            print("Error: --title, --author, and --year are required")
        else:
            add_book(session, args.title, args.author, args.year)

    elif args.command == "loan":
        if not args.book_id or not args.friend_id or not args.date:
            print("Error: --book_id, --friend_id, and --date are required")
        else:
            loan_book(session, args.book_id, args.friend_id, args.date)

    elif args.command == "return":
        if not args.loan_id:
            print("Error: --loan_id is required")
        else:
            return_book(session, args.loan_id)

if __name__ == "__main__":
    main()