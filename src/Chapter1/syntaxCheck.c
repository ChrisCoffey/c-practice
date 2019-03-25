#include <stdio.h>
#include <stdlib.h>

#define Bool int
#define True 1
#define False 0
// Indices for the various syntax patterns to match
#define PatternsChecked 8
#define Pattern int
#define Brace 0
#define Paren 1
#define Bracket 2
#define Quote 3
#define SingleQuote 4
#define Escape 5
#define CommentBlock 6
#define CommentLine 7

#define MaxErrorLength 300

Bool activePattern(Pattern p);
Bool isFailedPattern(Pattern p);
void openPattern(Pattern p);
void closePattern(Pattern p);
void init(char collectedErrors[50][MaxErrorLength]);
void clearErrors(char collectedErrors[50][MaxErrorLength]);
void markMostRecentInstance(Pattern p);
void getMostRecentInstance(Pattern p);

extern int patternCounts[PatternsChecked];
extern int mostRecentInstances[2*PatternsChecked];

int main (void) {
    // in 'mostRecentInstances', the opening take 0-6, closing 7-13
    int mostRecentInstances[2*PatternsChecked];
    char collectedErrors [50][MaxErrorLength];
    init(collectedErrors);
    char c, b, line, column;
    b = getchar();
    while((c = getchar()) != EOF) {
        switch(b) {
            case '\n': {
                line++;
                column=0;

                if(activePattern(CommentLine)){
                    closePattern(CommentLine);
                }

                break;
            }
            case '/': {
                switch(c){
                    case '*': {
                        if(!activePattern( CommentLine) &&
                           !activePattern( CommentBlock)) {
                            openPattern(CommentBlock);
                            mostRecentInstances()
                        }
                        break;
                    }
                    case '/': {
                        if(!activePattern(CommentLine) &&
                           !activePattern(CommentBlock)) {
                            openPattern(CommentLine);
                            mostRecentInstances(Patt)
                        }
                        break;
                    }
                    default :
                        ;
                column++;
                }
                column++;
            }

        }

        printf("%c", b);
        b = c;
    }

}

Bool activePattern(Pattern p){
    return patternCounts[p] > 0;
}

// Patterns fail immediately if they're opened inverted, but also if they're never closed.
Bool isFailedPattern(Pattern p){
    return patternCounts[p] < 0;
}

void init(char collectedErrors[][MaxErrorLength]){
    for(int i=0; i<PatternsChecked; i++)
        patternCounts[i] = 0;

    for(int i=0; i<2*PatternsChecked; i++)
        mostRecentInstances[i] = 0;

    clearErrors(collectedErrors);
}

void clearErrors(char collectedErrors[50][MaxErrorLength]){
    for(int i=0; i< 50; i++){
        collectedErrors[i][0] = '\0';
    }
}
