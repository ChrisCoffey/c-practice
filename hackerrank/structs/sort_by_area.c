#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};


typedef struct triangle triangle;

float area(triangle t){
    float p = ((float)(t.a + t.b + t.c)) / 2.0;
    return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}

void print_triangle(triangle t){
    printf("triangle: a:%d b:%d c:%d\n", t.a, t.b, t.c);
}

void merge(triangle* arr, int midpoint, int size) {
    triangle* result = malloc(size * sizeof(triangle));
    int i,j, k;
    for(i=0, j=midpoint, k=0; k < size; k++){
        triangle value;
        // If the left pointer has fully traversed its list, then return the right value
        if(i == midpoint) {
            value = arr[j++];
        // If the right pointer has fully traversed its list, then return the left value
        } else if(j == size) {
            value = arr[i++];
        // If the right value is less than the left value, return the right value
        } else if(area(arr[j]) < area(arr[i])){
            value = arr[j++];
        // If the left value is less than the right value, return the left value
        } else if(area(arr[j]) > area(arr[i])){
            value = arr[i++];
        // Otherwise, the two values must be equal, so just go with the left value
        } else {
            value = arr[i++];
        }
        result[k] = value;
    }


    for(int i=0; i< size; i++) {
        arr[i] = result[i];
    }
    free(result);
}

void sort_by_area(triangle* tr, int n) {
    if(n < 2)
        return;

	/**
	* Sort an array a of the length n
	*/
    int midpoint = n/2;
    sort_by_area(tr, midpoint);
    sort_by_area(tr+midpoint, n - midpoint);
    merge(tr, midpoint, n);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
