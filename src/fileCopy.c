#include <stdio.h>

/* copy the contents of a file */
int main(void) {
    int c;

    c=getchar();
    while (c != EOF) {
       putchar(c);
       c = getchar();
    }
}
