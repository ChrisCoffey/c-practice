#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    int n, k;
    scanf("%d %d", &n, &k);


    // The maximum of the n-choose-two values
    int maxAnd = 0;
    int maxOr = 0;
    int maxXor = 0;
    for(int a=1; a<=n; a++){
        for(int b=a+1; b<=n; b++){
            if(( a&b ) > maxAnd && (a&b) < k){
                maxAnd = a&b;
            }

            if (( a|b ) > maxOr && (a|b) < k){
                maxOr = a|b;
            }

            if ((a^b) > maxXor && (a^b) < k){
                maxXor = a^b;
            }
        }
    }

    printf("%d\n%d\n%d", maxAnd, maxOr, maxXor);

    return 0;
}
