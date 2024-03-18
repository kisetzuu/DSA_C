#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100


typedef struct
{
    char name[50];
    char email[50];
} Author;

typedef struct
{
    char title[50];
    char subject[50];
    Author author; // Nested structure
    char ISBN[20];
    int year;
}Book;

Book book[MAX_BOOKS]; // Array to hold books
int numBooks = 0;

void addBook(const char *title, const char *subject, const char *authorName, const char *authorEmail, const char *ISBN, int year)
{
    if(numBooks >= MAX_BOOKS)
    {
        printf("Maximum number of books reached.\n");
        return;
    }

    strcpy(book[numBooks].title, title);
    strcpy(book[numBooks].subject, subject);
    strcpy(book[numBooks].author.name, authorName);
    strcpy(book[numBooks].author.email, authorEmail);
    strcpy(book[numBooks].ISBN, ISBN);
    book[numBooks].year = year;

    numBooks++;
}

void printBookDetails() {
    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s\n", book[i].title);
        printf("Subject: %s\n", book[i].subject);
        printf("Author: %s\n", book[i].author.name);
        printf("Author's email: %s\n", book[i].author.email);
        printf("ISBN: %s\n", book[i].ISBN);
        printf("Year: %d\n\n", book[i].year);
    }
}

int main() 

{
    // Adding books to the library
    addBook("The C Programming Language", "Programming", "Brian Kernighan and Dennis Ritchie", "kr@example.com", "0-13-110362-8", 1978);
    addBook("Clean Code", "Software Engineering", "Robert C. Martin", "unclebob@example.com", "978-0132350884", 2008);

    // Printing the details of all books in the library
    printf("Library Inventory:\n");
    printBookDetails();

    return 0;
}