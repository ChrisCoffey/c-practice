#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* To take a single charcter _c_ as iput, you can use scanf("%c", &ch). This has a bit of magic in it. First, it assumes that there is a variable _ch_ defined.
 * Next, it uses & to
 *
 * `scanf` will pull in all input until it hits the first space. In order to take a full line, you need to provide a regular expression.
 *
 * Task is to pull three separate lines of input.
 * 1st is a character
 * 2nd is a string
 * 3rd is a sentence with multiple words
*/

int main()
{

    char c;
    char xs[100];
    char sen[100];

    scanf("%c\n", &c);
    gets(xs);
    gets(sen);

    printf("%c\n", c);
    puts(xs);
    puts(sen);
    return 0;
}
