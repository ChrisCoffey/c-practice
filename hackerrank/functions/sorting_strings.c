#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<check.h>

enum ordering { lt, gt, eq };

int lexicographic_sort(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int smallest = len_a > len_b ? len_b : len_a;

    for(int i=0; i< smallest; i++){
        if(a[i] > b[i]){
            return gt;
        } else if (a[i] < b[i]){
            return lt;
        }
    }

    return len_a == len_b       ? eq
         : len_a == smallest    ? lt
         :                        gt;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int res = lexicographic_sort(a,b);
    if (res == lt) {
        return gt;
    } else if (res == gt) {
        return lt;
    } else {
        return eq;
    }
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    // compute distinct a characters
    int *seen_a = calloc(26, sizeof(int));
    int len_a = strlen(a);
    for(int i=0; i < len_a; i++){
        int idx = a[i]-97;
        seen_a[idx] = 1;
    }

    int *seen_b = calloc(26, sizeof(int));
    int len_b = strlen(b);
    for(int i=0; i < len_b; i++){
        int idx = b[i]-97;
        seen_b[idx] = 1;
    }

    // compute distinct b characters

    int total_seen_a = 0;
    int total_seen_b = 0;
    for(int i=0; i<26; i++){
        total_seen_a += seen_a[i];
        total_seen_b += seen_b[i];
    }

    return total_seen_a > total_seen_b ? gt
         : total_seen_a < total_seen_b ? lt
         :                               lexicographic_sort(a,b);
}

int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    return len_a < len_b      ? lt
          : len_a == len_b    ? lexicographic_sort(a,b)
          :                     gt;
}



// Assumes that left and right are the same size and have been previously sorted
void merge (char** arr, int size, int midpoint ,int (*cmp_func)(const char* a, const char* b)){
    char **result = malloc(size * sizeof(char*));

    int idx, j,k;

    // This algorithm works by instantiating two pointers, one at the head of the array and one
    // at the midpoint. Conceptually, each half of the array represents an individual slice of the
    // array (in Haskell it would be its own list).
    //
    // The two pointers walk through the list, choosing the smaller of the left-most values in each
    // slice of the array.
    //
    // There are two corner cases:
    // 1) The full array has been traversed, and the 'j' indexer is at the end. In this case, a
    for (idx =0, j=midpoint, k= 0; k < size; k++){
        char* value;
        if( j == size){
            value = arr[idx++];
        } else if (idx == midpoint){
            value = arr[j++];
        } else if (cmp_func(arr[j], arr[idx]) == lt) {
            value = arr[j++];
        } else {
            value = arr[idx++];
        }

        result[k] = value;
    }

    for(int i = 0; i < size; i++){
        arr[i] = result[i];
    }
    free(result);

}

// Takes a list of strings and recursively sorts them. This is mutation based and modifies the
// provided array
void merge_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)){
    if (len < 2){
        return;
    }
    int midpoint = len / 2;
    merge_sort(arr, midpoint, cmp_func);
    merge_sort(arr+midpoint, len - midpoint, cmp_func);

    // use the source array and access via offsets rather than copying data from it. This gets away
    // from my immutable comfort zone, but that's not the worst thing.
    merge(arr, len, midpoint, cmp_func);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    merge_sort(arr, len, cmp_func);
}

int main()
{
    int n;
    scanf("%d", &n);

    char** arr;
	arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}
