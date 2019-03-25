#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* Write a function to find the largest of four integer arguments
 *
 *
 */

int max_of_n(int[], int);
void read_n(int, int[]);

int main (){
    int nums[4];
    read_n(4, nums);
    int result = max_of_n(nums, 4);

    printf("%d\n", result);
    return 0;
}

int max_of_n(int *xs, int n){
    int currentMax= xs[0];
    for(int i=0;i < n; i++){
        if (xs[i] > currentMax){
            currentMax = xs[i];
        }
    }

    return currentMax;
}

void read_n(int n, int* target){
    for(int i=0; i< n; i++){
        int x;
        scanf("%d\n", &x);
        target[i] = x;
    }
}
