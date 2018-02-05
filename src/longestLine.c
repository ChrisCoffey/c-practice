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
    while(!printLineLongerThanN(PrintThreshold))
        ;
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
