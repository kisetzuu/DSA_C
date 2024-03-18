#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct Author
{
    char name[50];
    char email[50];
};

struct Book
{
    char title[50];
    char subject[50];
    struct Author author;
    char ISBN[50];
    int year;
};

void addBook(struct Book book[], int *num_books, const char *title, const char *subject, const char *authorName, const char *authorEmail, const char *ISBN, int year)
{
    if (*num_books >= MAX_BOOKS)
    {
        printf("Maximum number of books reached\n");
        return;
    }

    strcpy(book[*num_books].title, title);
    strcpy(book[*num_books].subject, subject);
    strcpy(book[*num_books].author.name, authorName);
    strcpy(book[*num_books].author.email, authorEmail);
    book[*num_books].year = year;

    (*num_books)++;
}

void printBookDetails(const struct Book book[], int num_books)
{
    for(int i = 0; i < num_books; i++)
    {
        printf("Title %s\n", book[i].title);
        printf("Subject %s\n", book[i].subject);
        printf("Author Name: %s\n", book[i].author.name);
        printf("Author Email: %s\n", book[i].author.email);
        printf("ISBN: %s\n", book[i].ISBN);
        printf("Year: %d\n\n", book[i].year);
    }
}

int main()
{
    struct Book library[MAX_BOOKS];
    int num_books = 0;

    addBook(library, &num_books, "The C Programming Language", "Programming", "Brian Kernighan and Dennis Ritchie", "kr@example.com", "0-13-110362-8", 1978);
    addBook(library, &num_books, "Clean Code", "Software Engineering", "Robert C. Martin", "unclebob@example.com", "978-0132350884", 2008);

    printf("Library Inventory: \n");
    printBookDetails(library, num_books);
}
