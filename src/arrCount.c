#include <stdio.h>

int main (void) {
    int c, i, nwhite, nother;
    int ndigit[10];

    // Initialize the state
    nwhite = nother = 0;
    for (i=0; i < 10; i++) {
        ndigit[i] = 0;
    }

    // accumulate the results
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("digits: ");
    for (i =0; i < 10; i++)
        printf(" %d", ndigit[i]);

    printf(", ws: %d, other: %d\n", nwhite, nother);
}
