#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    int a = 0;
    int z = num -1;
    int temporary;
    while (a < z) {
        temporary = arr[a];
        arr[a] = arr[z];
        arr[z] = temporary;

        // advance the pointers
        a++;
        z--;
    }


    for(i = 0; i < num; i++) {
        printf("%d ", *(arr + i));
    }
    return 0;
}
