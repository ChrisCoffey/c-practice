#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *str;
    str = malloc(5 * sizeof(char));
    scanf("%[^\n]", str);
    str = realloc(str, strlen(str) + 1);

    int sum=0;
    for(int i=0; i < strlen(str); i++){
        sum+=str[i] - 48;
    }

    printf("%d", sum);
    return 0;
}

