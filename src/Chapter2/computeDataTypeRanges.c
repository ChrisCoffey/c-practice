#include <stdio.h>
#include <float.h>

void printIntRange();
void printUIntRange();
void printULongRange();
void printLongRange();
void printCharRange();
void printUCharRange();
void printUShortRange();
void printShortRange();

int main(void) {
    printIntRange();
    printUIntRange();

    printLongRange();
    printULongRange();

    printShortRange();
    printUShortRange();

    printCharRange();
    printUCharRange();
}

void printUIntRange() {
    unsigned int a, b;
    a=b=0;
    b--;

    printf("unsigned int ranges: min-%u   max- %u\n", a, b);
}

void printIntRange(){
    int c,d;
    d = ((unsigned int) 0-1) / 2;
    c = d +1;
    printf("int ranges: min-%d   max- %d\n", c, d);
}

void printULongRange() {
    unsigned long a, b;
    a=b=0;
    b--;

    printf("unsigned long ranges: min-%lu   max- %lu\n", a, b);
}

void printLongRange(){
    long c,d;
    d = ((unsigned long) 0-1) / 2;
    c = d +1;
    printf("long ranges: min-%ld   max- %ld\n", c, d);
}

void printUShortRange() {
    unsigned short a, b;
    a=b=0;
    b--;

    printf("unsigned short ranges: min-%hu   max- %hu\n", a, b);
}

void printShortRange(){
    short c,d;
    d |= 1 << 15;
    d--;
    c = d +1;
    printf("short ranges: min-%hd   max- %hd\n", c, d);
}

void printUCharRange() {
    unsigned char a, b;
    a=b=0;
    b--;

    printf("unsigned char ranges: min-%hhu   max- %hhu\n", a, b);
}

void printCharRange(){
    char c,d;
    d |= 1 << 7;
    d--;
    c = d + 1;
    printf("char ranges: min-%hhd   max- %hhd\n", c, d);
}

void printFloatingPointRange() {
    float a,b;
    a=b=0.0;

    // to actually compute this, for each sign bit, set all of the exponent & sign bits.
    printf("float ranges: min- %f    max- %f", a, b);
}
