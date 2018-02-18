#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxLineLengthCoeficient 40
#define True 1
#define False 0
#define Bool int

int parseLineLength(int count, char* argValues[]);

int naiveExponent(int base, int power);
int toInt(char* str);
int readInputLine(char line [], int *idx);
// ^ reads stdin into the provided char[], returns the final character read & length
void foldLine(char line[], int maxLength);
// ^ Given an input line, return the fold & zero out the remainder of the line

int main(int argCount, char* argValues[]) {
    int length = parseLineLength(argCount, argValues);
    printf("The longest possible line will be: %d characters\n", length * MaxLineLengthCoeficient);

    char line[length * MaxLineLengthCoeficient];
    int *idx=malloc(sizeof(int));
    int ret;
    while((ret = readInputLine(line, idx)) != EOF){
        foldLine(line, length);
    }
    free(idx);
    return 0;
}

// Read a line into a buffer, returning the index and last char read
// If (idx <= maxLength)
//    continue;
// else
//    read the line backwards from (maxLineLength - 1) to the first whitespace character
//    print characters up to that point, then a newline
//    print remainder of the line up to idx
//
// if there is no whitespace, insert a '-' at (maxLength -1)
//                            print characters up to that point, then a newline
//                            repeat for remainder of the line

Bool isWhiteSpace(char c) {
    if (c == ' ' || c == '\t')
        return True;
    else
        return False;
}

int diff(int a, int b) {
    return a - b;
}

// There are three main cases:
// 1) newline occurs before maxLength
// 2) newline occurs after maxLength, and a space occurs before maxLength
// 3) newline after maxLength & no whitespace before maxLength
void foldLine(char line[], int maxLength) {
    int c, i, x, accum;
    i = x = 0;
    while((c = line[i]) != EOF) {
        // Record the index of whitespace characters as we see them
        if (isWhiteSpace(c)){
            x = i;
        }
        // The line segment is shorter than the maximum length, print it as is
        if(c == '\n') {
            int idx = i < maxLength ? 0 : i - accum;
            for(;idx < i; idx++){
                printf("%c", line[idx]);
            }
            printf("%c", c);
            accum = 0;
            break;
        }
        // The line is longer than maxLength & no newline has been hit yet.
        // Print up to the most recent whitespace
        else if(accum == maxLength) {
            for(int idx = i - maxLength; idx < x; idx++) {
                printf("%c", line[idx]);
            }
            printf("\n");
            // print the rest of the line
            accum = 0;
        }
        i++;
        accum++;
    }
}

int readInputLine(char line[], int *idx){
    int c, i;
    i=0;
    while((c = getchar()) != EOF && c != '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\n';
    line[i+1] = '\0';
    *idx = i;
    return c;
}

int parseLineLength(int argCount, char *argValues[]) {
    int i, length;
    for(i = 1; i < argCount; i++) {
        if(0 == strcmp(argValues[i], "-len") && i+1 <= argCount){
            i++;
            length = toInt(argValues[i]);
            return length;
        }
    }
    return -1;
}

// negative exponents are not supported
int naiveExponent(int base, int power) {
    if(power == 1)
        return base;
    else if (power == 0)
        return 1;
    else
        return base  * naiveExponent(base, power - 1);
}

int toInt(char *str){
    int i,c,n;
    i=0;
    while(c != '\0'){
        c = str[i];
        i++;
    }
    n=c=0; // c is reused as the exponent

    // i-2 to skip past the null terminator & extra hop above
    for(int x=i-2; x>=0; x--){
        n += (str[x] - '0') * naiveExponent(10, c);
        c++;
    }

    return n;
}
