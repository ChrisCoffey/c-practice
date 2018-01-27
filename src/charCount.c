#include <stdio.h>

long charCount (void) {
    long nc = 0;
    while(getchar() != EOF) {
        ++nc;
    }

    return nc;
}

long countWhiteSpace(void) {
    long wc = 0;
    char c;
    for(char c='a'; c!= EOF; c=getchar()) {
        switch (c) {
            case '\t' :
                wc++;
            case ' ' :
                wc++;
            case '\n' :
                wc++;
            case '\r' :
                wc++;
            default :
                continue;
        }
    }
    return wc;
}

char compress(char matchOn, char prev) {
    char currChar = getchar();
    if (currChar == EOF) {
        return currChar;
    }

    if (currChar == matchOn && currChar == prev) {
        compress(matchOn, currChar);
    } else {
        return currChar;
    }
}

void compressSpaces(void) {
    char c=EOF;
    do {
        c = compress(' ', c);
        printf("%c", c);
    } while(c != EOF);
}

void translateHiddenChars(void) {
    for (char c='a'; c!= EOF; c = getchar()) {
        switch(c){
            case '\t':
                printf("\\t");
            case '\b':
                printf("\\b");
            case '\\':
                printf("\\");
            default:
                printf("%c", c);
        }
    }
    printf("%c", EOF);
}


int main(void) {
    // long nc = charCount();
    //long wc = countWhiteSpace();
    //printf("%1d\n", wc);

    //compressSpaces();

    translateHiddenChars();
}
