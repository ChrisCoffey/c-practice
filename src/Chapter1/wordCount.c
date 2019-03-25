#include <stdio.h>

#define IN 1
#define OUT 0

void wordCount(void) {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while( (c = getchar()) != EOF){
        ++nc;

        if (c == '\n'){
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
}

void wordPerLine(void) {
    char c;

    while ( (c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            printf("\n");
        }
        else {
            printf ("%c", c);
        }
    }
}

int main (void){
    wordPerLine();
}
