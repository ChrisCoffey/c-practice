#include <stdio.h>

#define Bool int
#define False 0
#define True !False
#define GraphHeight 20
#define HorizontalWidth 50
#define NumValues 20
#define AsciiRange 128

Bool whitespace(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

/* Determine the word length by getting the next stdin char
   until a whitespace or EOF character is encountered */
int wordLength(void) {
    int c , n;
    n =0;
    do {
        c = getchar();
        if (!whitespace(c) && c != EOF)
            ++n;
        else if (c == EOF) {
            n = EOF;
        }
    } while (!whitespace(c) && c != EOF);

    return n;
}

void buildHistogram(int len, int * buckets) {
    int wl;
    for (int i = 0; i <= len; i++) {buckets[i] = 0;}

    while((wl = wordLength()) != EOF) {
        // set wordLength as an index in the histogram
        if (wl >= len)
            buckets[len -1]++;
        else if (wl > 0)
            buckets[wl - 1]++;
        else
            ;
    }
    // once all words have been collected,
    // produce the vertical histogram by writing each
    // of the columns, scaled to 10  w/ the actual value at the top
}

int max (int l, int r) {
    return l > r ? l : r;
}

void padR (int padding) {
    for(int i=0; i< padding; i++)
        printf(" ");
}

// Assumes that width is >= value width
void printWithPadding (int width, int value) {
    int x, padding;
    padding = width;
    x = value;

    while((x /= 10) > 0){
        padding--;
    }

    printf("%d", value);
    padR(padding);
}

/* Produces the following, when run on this file:

    Historgram of word lengths:
    Labels: 1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20+
    Values: 85  77  53  52  22  19  23  17  19  13  8   8   6   0   8   4   0   2   3   1
            0   0
            0   0
            0   0
            0   0   0
            0   0   0   0
            0   0   0   0
            0   0   0   0
            0   0   0   0   0       0
            0   0   0   0   0   0   0   0   0   0
            0   0   0   0   0   0   0   0   0   0   0   0   0       0
*/
void drawHistogram (void) {
    int buckets [NumValues];
    buildHistogram(NumValues, buckets);
    int maxValue, tickSize;
    maxValue=0;
    for(int i=0; i<NumValues; i++){
        maxValue = max(maxValue, buckets[i]);
    }

    tickSize = maxValue / GraphHeight;

    printf("Historgram of word lengths: \n");
    printf("Labels: ");

    for(int i=0; i< NumValues-1; i++) {
        printWithPadding(3, i+1);
    }
    printf("%d+\n", NumValues);
    printf("Values: ");
    for(int i=0; i< NumValues; i++){
        printWithPadding(3, buckets[i]);
    }
    printf("\n");
    for(int i=0; i< GraphHeight; i++) {
        // Draw the actualy histogram as a 25x10 grid
        printf("        ");
        for(int x=0; x< NumValues; x++){
            if(buckets[x] >= (maxValue - tickSize)) {
                printWithPadding(3, 0);
                buckets[x] -= tickSize;
            }
            else printf("    ");
        }
        printf("\n");
        maxValue -= tickSize;
    }
}

// Builds a horizontal histogram
void buildCharHistogram(int * charFreqs) {
    char c;
    while( (c = getchar()) != EOF) {
        charFreqs[c]++;
    }
}

/* Creates a histogram of the 128 ascii characters,
   its a bit tall so I won't include all of it, but the output looks like this:
^  ->                                                     0
_  ->                                                     0
`  ->                                                     0
a  -> xxxx                                                147
b  -> x                                                   31
c  -> xxx                                                 95
d  -> xx                                                  88
e  -> xxxxxx                                              195
f  -> x                                                   55
g  -> x                                                   56
h  -> xx                                                  88
i  -> xxxxxxx                                             246
j  ->                                                     0
k  -> x                                                   32
l  -> xxx                                                 95
m  -> x                                                   45
n  -> xxxx                                                147
o  -> xx                                                  88
*/
void drawCharHistogram (void) {
    int maxValue, tickSize, bucketLength;
    bucketLength = AsciiRange +1;
    int buckets [bucketLength];
    for(int z=0; z< bucketLength; z++){
        buckets[z] = 0;
    }

    buildCharHistogram(buckets);

    maxValue=0;
    for(int i=0; i< bucketLength; i++){
        maxValue = max(maxValue, buckets[i]);
    }

    tickSize = maxValue / HorizontalWidth;
    printf("%d   %d", maxValue, tickSize);

    printf("Historgram of character frequencies: \n");
    for(int i=0; i< bucketLength; i++) {
        printf("%c  -> ", i);

        int localMax = 0;
        int val = buckets[i];
        for(int x=0; x <HorizontalWidth; x++) {
           if(buckets[i] >= (localMax + tickSize)) {
               printf("x");
               localMax += tickSize;
           }
           else printf(" ");
        }
        printf("  %d\n", val);
    }

}

void charCount (void) {
    int c, i, nwhite, nother;
    int ndigit[10];

    // Initialize the state
    nwhite = nother = 0;
    for (i=0; i < 10; i++) {
        ndigit[i] = 0;
    }

    // accumulate the results
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (whitespace(c))
            ++nwhite;
        else
            ++nother;
    }

    printf("digits: ");
    for (i =0; i < 10; i++)
        printf(" %d", ndigit[i]);

    printf(", ws: %d, other: %d\n", nwhite, nother);
}

int main (void) {
    //drawHistogram();
    drawCharHistogram();
}
