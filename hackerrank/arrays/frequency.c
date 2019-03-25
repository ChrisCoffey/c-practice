#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s)+1);

    int *histogram = calloc(10, sizeof(int));
    for(int i=0; i< strlen(s); i++){
        char val = s[i] - 48;
        if(val >= 0 && val < 10) {
            histogram[val]++;
        }
    }

    for(int i=0; i< 10; i++){
        printf("%d ", histogram[i]);
    }

    return 0;
}
