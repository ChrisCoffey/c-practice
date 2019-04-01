#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A lexographic comparison
int lex_compare(char* l, char* r){
    int len_l = strlen(l);
    int len_r = strlen(r);
    int smallest = len_l < len_r ? len_l : len_r;

    for(int i=0; i< smallest; i++){
        if(l[i] < r[i]) {
            return -1;
        } else if (l[i] > r[i]) {
            return 1;
        }
    }
    if(len_l == smallest && len_l != len_r){
        return -1;
    }
    return 0;
}

void swap (char** arr, int a, int b){
    char* tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int right_largest(char** arr, int length, int pivot){
    char* pivotElem = arr[pivot];
    int result;
    for(result=length -1; result > pivot ; result--){
        if( lex_compare(pivotElem, arr[result]) < 0) {
            break;
        }
    }

    return result;
}

void reverse_slice(char** arr, int start, int end) {
    for(int a=start, z=end; a < z; a++, z--){
        swap(arr, a, z);
    }
}

// This is a generator of permutations.
int next_permutation(int n, char** s)
{
    // From the end of the array, find the longest sub-array of descending values.
    //
    int pivot = n-2;
    while (pivot >= 0 && // Have not traversed entire array
           lex_compare(s[pivot], s[pivot + 1]) >= 0 // pivot is still increasing
          ) {
        pivot--;
    } ;

    if(pivot < 0){
        return 0;
    }

    // Swap the pivot with the right-most string larger than the pivot
    int swap_target = right_largest(s, n, pivot);
    swap(s, pivot, swap_target);

    if(lex_compare(s[swap_target], s[pivot]) == 0) {

    }

    reverse_slice(s, pivot+1, n-1);


    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
