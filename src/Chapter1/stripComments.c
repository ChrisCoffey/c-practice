#include <stdio.h>

#define Bool int
#define True 1
#define False 0

Bool startsCommentBlock (char l, char r);
Bool closesCommentBlock (char l, char r);
Bool startsCommentLine (char l, char r);
Bool closesCommentLine (char l);
Bool startsCharLit (char l);
Bool closesCharLit (char l);
Bool startsStringLit(char c);
Bool closesStringLit(char c);

// Fairly straightforward
int main (void) {

    printf("confusing literal: // ");
    char c,b;
    c = b = 0;
    Bool inCharConstant, inCommentBlock, inCommentLine, inStringLiteral;
    inCharConstant = inCommentLine = inStringLiteral = inCommentBlock = False;

    b = getchar();
    while((c = getchar()) != EOF) {
       /*
        inCharConstant = startsCharLit(b);
        inStringLiteral = startsStringLit(b);
        inCommentLine = startsCommentLine(b, c);
        inCommentBlock = startsCommentBlock(b, c);
        */
        if(startsCharLit(b) && !inCharConstant) {
            inCharConstant = True;
            printf("%c", b);
        } else if (inCharConstant && closesCharLit(b)) {
            inCharConstant = False;
            printf("%c", b);
        }
        else if (startsStringLit(b) && !inStringLiteral){
            inStringLiteral = True;
            printf("%c", b);
        } else if (closesStringLit(b) && inStringLiteral) {
            inStringLiteral = False;
            printf("%c", b);
        } else if (startsCommentLine(b, c) && !inStringLiteral && !inCharConstant) {
            inCommentLine = True;
        } else if (closesCommentLine(b) && inCommentLine){
            inCommentLine = False;
            printf("\n");
        } else if (startsCommentBlock(b, c) && !inStringLiteral && !inCharConstant){
            inCommentBlock = True;
        } else if (closesCommentBlock(b, c) && inCommentBlock) {
            inCommentBlock = False;
        }
        else if (inCommentLine || inCommentBlock){
            ;
        } else {
            printf("%c", b);
        }

        b = c;
    }
}

Bool startsStringLit(char c){
    return c == '\"';
}

Bool closesStringLit(char c){
    return c == '\"';
}

Bool startsCharLit(char c){
    return c == '\'';
}

Bool closesCharLit(char c){
    return c == '\'';
}

Bool startsCommentLine(char l, char r){
    return l == '/' && r == '/';
}

Bool closesCommentLine(char c) {
    return c == '\n';
}

Bool startsCommentBlock(char l, char r){
    return l == '/' && r == '*';
}

Bool closesCommentBlock(char l, char r){
    return l == '*' && r == '/';
}
