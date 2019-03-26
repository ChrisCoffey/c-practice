#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int min(int, int);

int main (){
    int n;
    scanf("%d", &n);

    int size = (2 * n) - 1;
    int grid[size][size];

    // Constructs a size x size square. The values of each cell are determined by how
    // far they are from the center

    int sz = size -1;
    // rows
    for(int i = 0; i< n; i++){
    // columns
        for(int x =0; x < n; x++){
            int val = abs(n - ( min(i,x) ));
            grid[i][x] = val;
            grid[sz-i][x] = val;
            grid[i][sz-x] = val;
            grid[sz-i][sz-x] = val;
        }

    }

    for(int i=0; i< size; i++){
        for(int x=0; x<size; x++){
            printf("%d ", grid[i][x]);
        }

        printf("\n");
    }
    return 0;
}

int min(int a, int b){
    if(a < b){
        return a;
    } else {
        return b;
    }
}
