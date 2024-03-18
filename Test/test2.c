#include <stdio.h>
#include <stdlib.h>

struct book {
    int pages;
    char title[10];
};

int main()
{
struct book novel = {123, "Hamlet"};
printf("Title: %s, Pages: %d", novel.pages, novel.title);
}