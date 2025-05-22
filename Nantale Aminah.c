#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    struct Book book1; 

    printf("Enter book title: ");
    fgets(book1.title, sizeof(book1.title), stdin);
    
    book1.title[strcspn(book1.title, "\n")] = 0;

    printf("Enter author name: ");
    fgets(book1.author, sizeof(book1.author), stdin);
    book1.author[strcspn(book1.author, "\n")] = 0;

    printf("Enter book price: ");
    scanf("%f", &book1.price);

    while (getchar() != '\n' && getchar() != EOF);

    printf("\nBook details entered:\n");
    printf("Title: %s\n", book1.title);
    printf("Author: %s\n", book1.author);
    printf("Price: %.2f\n", book1.price);

    return 0;
}