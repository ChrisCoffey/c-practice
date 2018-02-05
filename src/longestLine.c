#include <stdio.h>
// constants
#define MaxLine 10
#define PrintThreshold 80

int get_line(char line[], int maxLine);
int get_line2(char line[], int maxLine);
void copy(char to[], char from[]);


int get_line(char line[], int maxLine);
int get_line2(char line[], int maxLine);
void copy(char to[], char from[]);
int printLineLongerThanN(int n);
int removeTrailingBlanks(char line[]);
void reverseLine(char line[]);
int readline(char line[]);

int basicMain() {
    int len,max;
    char line[MaxLine];
    char longest[MaxLine];

    max=0;
    while ((len = get_line2(line, MaxLine)) > 0){
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("%d -> %s", max, longest);

    return 0;
}

int main() {
    char line[1000];
    int n=0;
    char reversed[1000];
    int i,j;
    do {
        n = readline(line);
        i = j = 0;
        while(line[i] != '\0')
            i++;
        while(i > 0){
            reversed[j] = line[i-1];
            j++;
            i--;
        }
        reversed[j] = '\0';

        printf("%s", reversed);
    } while (n != EOF);
    return 0;
}

int get_line2(char s[], int limit) {
    int c,i;

    for(i=0; i< limit - 1 && (c=getchar()) != EOF && c!= '\n'; ++i){
        s[i] = c;
    }
    int end=i;
    if (c == '\n') {
        s[i]=c;
        i++;
        end=i;
    } else {
        while ((c=getchar()) != EOF && c != '\n') {
            i++;
        }
    }

    s[end] = '\0'; // null

    return i;

}

int printLineLongerThanN(int n){
    char prefix[PrintThreshold];
    int triggered, c, i;

    for(i=0; i < n && (c = getchar()) != EOF && c != '\n'; ++i) {
        prefix[i] = c;
    }
    triggered = (i == n);
    prefix[PrintThreshold-1] = '\0';

    if(triggered){
        printf("%s", prefix);
        while((c = getchar()) != EOF && c != '\n')
            printf("%c", c);
        printf("\n");
    }
    return c == EOF;
}

// modifies the input array 's', and returns the length of the string written to it
int get_line(char s[], int limit) {
    int c, i;

    for(i=0; i< limit - 1 && (c=getchar()) != EOF && c!= '\n'; ++i){
        s[i] = c;
    }
    if (c == '\n') {
        s[i]=c;
        i++;
    }
    s[i] = '\0'; // null
    return i;
}

// Assumes the input strings are non-empty
void copy(char to[], char from[]) {
    int i = 0;

    while((to[i] = from[i]) != '\0') {
        i++;
    }
}

int runTrailingBlanks() {
    char line[1000];
    int n, dummy;
    dummy = 0;
    do {
        n = removeTrailingBlanks(line);
        if (n > 1)
           printf("%s|\n", line);
        for(int i=0; i< 1000; i++)
            line[i]=0;
    } while(n != EOF);

    return 0;
}

int removeTrailingBlanks(char line[]) {
    int c, i;
    for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    while(line[i] == ' ' || line[i] == '\t') {
        i--;
    }
    line[i+1] = '\0';

    if(c == EOF)
        return EOF;
    else
        return i;
}

int readline(char line[]){
    int c, i;
    for(i=0; (c = getchar()) != EOF && c != '\n'; ++i){
        line[i] = c;
    }
    line[++i] = '\n';
    line[++i]='\0';
    return c;
}

void reverseLine(char line[]) {
    char reversed[1000];
    int i,j;
    i = j = 0;
    while(line[i] != '\0')
        i++;
    while(i >= 0){
        reversed[j] = line[i];
        j++;
        i--;
    }
    reversed[j] = '\0';
    for(i=0;i<j;i++){
        line[i] = reversed[i];
    }
}
