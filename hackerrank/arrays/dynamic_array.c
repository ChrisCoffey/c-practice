#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

// stores the next index to insert into on the shelf
int* next_book;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    total_number_of_books = calloc(total_number_of_shelves,sizeof(int));
    total_number_of_pages = malloc(total_number_of_shelves * sizeof(int*));
    for(int i=0; i < total_number_of_shelves; i++){
        total_number_of_pages[i] = (int*)malloc(1100 * sizeof(int));
    }

    next_book = calloc(total_number_of_shelves,sizeof(int));
    for (int i=0; i < total_number_of_shelves; i++){
        next_book[i] = 0;
    }

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1) {
            // This inserts a book into the xth shelf with y pages
            int shelf, pages;
            scanf("%d %d", &shelf, &pages);
            total_number_of_books[shelf]++;
            total_number_of_pages[shelf][next_book[shelf]] = pages;
            next_book[shelf]++;
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
        free(next_book);
    }

    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }

    if (total_number_of_pages) {
        free(total_number_of_pages);
    }

    return 0;
}
