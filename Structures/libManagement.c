#include <stdio.h>
#include <string.h> // Required for strcpy

// Assuming a maximum size for the book array
#define MAX_BOOKS 100

// Define the Author structure
struct Author {
    char name[50];
    char email[50];
};

// Define the Book structure, including an Author structure within it
struct Book {
    char title[50];
    char subject[50];
    struct Author author; // Nested structure
    char ISBN[20];
    int year;
};

// Function to add a book to the book array
void addBook(struct Book book[], int *num_books, const char *title, const char *subject, const char *authorName, const char *authorEmail, const char *ISBN, int year) {
    if (*num_books >= MAX_BOOKS) { // Check to avoid exceeding the array
        printf("Maximum number of books reached.\n");
        return;
    }

    // Copy the provided information into the book array at the next available index
    strcpy(book[*num_books].title, title);
    strcpy(book[*num_books].subject, subject);
    strcpy(book[*num_books].author.name, authorName);
    strcpy(book[*num_books].author.email, authorEmail);
    strcpy(book[*num_books].ISBN, ISBN);
    book[*num_books].year = year;

    (*num_books)++; // Increment the total number of books
}

// Function to print the details of all books in the array
void printBookDetails(const struct Book book[], int num_books) {
    for (int i = 0; i < num_books; i++) {
        printf("Title: %s\n", book[i].title);
        printf("Subject: %s\n", book[i].subject);
        printf("Author: %s\n", book[i].author.name);
        printf("Author's email: %s\n", book[i].author.email);
        printf("ISBN: %s\n", book[i].ISBN);
        printf("Year: %d\n\n", book[i].year);
    }
}

// Main function
int main() {
    struct Book library[MAX_BOOKS]; // Array of books
    int num_books = 0; // Counter for the number of books

    // Adding books to the library
    addBook(library, &num_books, "The C Programming Language", "Programming", "Brian Kernighan and Dennis Ritchie", "kr@example.com", "0-13-110362-8", 1978);
    addBook(library, &num_books, "Clean Code", "Software Engineering", "Robert C. Martin", "unclebob@example.com", "978-0132350884", 2008);

    // Printing the details of all books in the library
    printf("Library Inventory:\n");
    printBookDetails(library, num_books);

    return 0;
}
