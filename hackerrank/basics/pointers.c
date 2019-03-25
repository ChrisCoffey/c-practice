#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* The &, or "referencing" operator, returns the memory address of the variable it is applied to.
 *
 *
 *
 * Task is to implement the function void update(int *a, int *b), that sets a to the sum and b w/ the diff
 */

void update (int*, int*);

int main (){
    int a,b;
    scanf("%d\n%d\n", &a, &b);
    update(&a, &b);
    printf("%d\n%d", a,b);
    return 0;
}

void update(int *a, int *b) {
    // Do some math, putting aside the results
    int x = *a + *b;
    int y = abs(*a - *b);

    // assign the results
    *a = x;
    *b = y;
}
