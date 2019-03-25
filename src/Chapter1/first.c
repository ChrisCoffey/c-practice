#include <stdio.h>
#include <string.h>

/* print Farenheit -> Celsius table
    for fahr = 0,20,..., 300 */

#define STEPSIZE 20
#define MAX_TEMP 300
#define FAHR_FREEZING 32
#define FAHR "Farenheit"
#define CELS "Celsius"

void printHeading(char* a,char* b) {
    printf("%s\t%s\n", a, b);
}

void farenheitToCelsius() {

   printHeading(FAHR, CELS);

   float fahr;
   for (fahr = MAX_TEMP; fahr >= 0; fahr = fahr - STEPSIZE) {
       float celsius = (5.0/ 9.0) * (fahr - FAHR_FREEZING);
       printf("%3.0f\t%6.1f\n", fahr, celsius);
   }
}

void celsiusToFarenheit() {

   printHeading(CELS, FAHR);

   float celsius;
   for (celsius = 0; celsius <= MAX_TEMP; celsius += STEPSIZE) {
       float fahr = (celsius / 0.555 ) + FAHR_FREEZING;
       printf("%3.0f\t%6.1f\n", celsius, fahr);
   }
}

int main(void) {
    farenheitToCelsius();
    printf("\n\nNext\n\n");
    celsiusToFarenheit();
    return 0;
}
