#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char title[50];
    char author[50];
    char isbn[50];
    int year;
    int avail;
}Book;

void printBook(Book book)
{
    printf("\nTitle: %s\nAuthor: %s\nInternational Standard Book Number: %s\nYear: %d\nAvailability: %s\n\n", book.title, book.author, book.isbn, book.year, book.avail ? "Yes" : "No");
}

int main() {
    Book library[] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", "1234567890", 1925, 1},
        {"To Kill a Mockingbird", "Harper Lee", "2345678901", 1960, 0},
        {"1984", "George Orwell", "3456789012", 1949, 1}
    };

    int librarySize = sizeof(library) / sizeof(library[0]);
    
    for(int i = 0; i < librarySize; i++)
    {
        if(library[i].avail)
        {
            printBook(library[i]);
        }
    }

    return 0;
}