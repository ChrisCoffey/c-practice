#include <stdio.h>

#define Tab '\t'
#define LF '\n'

// 'detab' is a program that streams the input and converts tabs to spaces.
//
// It takes a single argument, the tab witdh, and reads its input from stdin

int tabPadding(int tabIndex, int tabWidth);
void expand(int spacesToAdd);

int main (int argc, char *argv []) {
    int i, c, padWidth, tabWidth;
    tabWidth = (argv[1][0]) - '0';
    i=0;
    while((c= getchar()) != EOF) {
        switch(c){
            case Tab: {
                padWidth = tabPadding(i, tabWidth);
                expand(padWidth);
                i+= padWidth;
                }
            case LF:
                printf("%c", c);
                i=0;
            default:
                printf("%c", c);
                i++;
        }
    }
}

int tabPadding(int tabIndex, int tabWidth) {
    return (tabIndex % tabWidth) + 1;
}

void expand(int spacesToAdd){
    for(int i=0; i<spacesToAdd; i++) {
        printf(" ");
    }
}
