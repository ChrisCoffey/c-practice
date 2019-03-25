#include <stdio.h>

#define Tab '\t'
#define Space ' '
#define LF '\n'
#define MaxWhitespace 1000

// 'entab' converts multiple spaces to tabs & spaces. In the event that a tab or a space will work, the
// space is chosen.
//
// "tabWidth 2", The    quick brown dog  -> "The\t\t quick brown dog"

int tabsToAdd(int wsLen, int tabWidth);
int spacesToAdd(int wsLen, int tabWidth);
void expand(int length, int tabWidth);

int main (int argc, char *argv []) {
    int i, c, padWidth, tabWidth, wsLen;
    tabWidth = argv[1][0] - '0';
    i = wsLen = 0;

    while((c=getchar()) != EOF) {
        switch(c){
            case LF: {
                printf("%c", c);
                i = wsLen = 0;
                break;
                }
            case Space:{
                wsLen++;
                break;
                       }
            default: {
                if (wsLen > 0) {
                    expand(wsLen, tabWidth);
                    wsLen=0;
                }
                printf("%c", c);
                }
        }
    }
}

void expand(int length, int tabWidth) {
    for(int i=0; i< tabsToAdd(length, tabWidth); i++)
        printf("\t");

    for(int i=0; i< spacesToAdd(length, tabWidth); i++)
        printf(" ");
}

int tabsToAdd(int wsLen, int tabWidth) {
    return wsLen / tabWidth;
}

int spacesToAdd(int wsLen, int tabWidth) {
    return wsLen % tabWidth;
}
