#include <stdio.h>
#include <string.h>

/* print Farenheit -> Celsius table
    for fahr = 0,20,..., 300 */


void printHeading(char* a,char* b) {
    printf("%s\t%s\n", a, b);
}

void farenheitToCelsius() {
   float fahr;

   printHeading("Farenheit", "Celsius");

   for (fahr =0; fahr <= 300; fahr = fahr+20) {
       float celsius = (5.0/ 9.0) * (fahr-32.0);
       printf("%3.0f\t%6.1f\n", fahr, celsius);
   }
}

void celsiusToFarenheit() {
   float fahr, celsius;
   int lower, upper, step;

   lower = 0;
   upper = 300;
   step = 20;

   celsius = lower;

   printHeading("Celsius", "Farenheit");

   for (celsius = 0; celsius <= 300; celsius += 20) {
       float fahr = (celsius / 0.555 ) + 32;
       printf("%3.0f\t%6.1f\n", celsius, fahr);
   }
}

int main(void) {
    farenheitToCelsius();
    printf("\n\nNext\n\n");
    celsiusToFarenheit();
    return 0;
}
