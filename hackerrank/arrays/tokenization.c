#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STOPW "__THEEND__"
// Splits the string on the provided character
char** split(char*, char);

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    for(int i=0; i<strlen(s); i++){
        if(s[i] == ' '){
            printf("\n");
        }
        else {
            printf("%c", s[i]);
        }
    }


    return 0;
}

char* substring(char *str, int start, int end){
    char *subStr = malloc(((end-start)+1) * sizeof(char));
    memcpy(subStr, &str[start], end-start);
    subStr[end-start] = '\0';
    return subStr;
}

char** split(char *str, char splitOn){
    size_t len = strlen(str);
    int resultIndex = 0;
    char *result[100];
    for(int i=0; i< 100; i++){
        result[i] = NULL;
    }

    int currIndex=0;
    for(int needle=0; needle < len; needle++) {
        if(str[needle] == splitOn) {
            char *subStr = substring(str, currIndex, needle);
            result[resultIndex] = subStr;
            currIndex = needle+1;
            resultIndex++;
        }
    }
    result[resultIndex] = substring(str, currIndex, len);
    result[resultIndex+1] = STOPW;

    return result;
}
