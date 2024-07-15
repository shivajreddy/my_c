#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
// comments like this are introduced later.
stdio.h is the standard library of C
*/

/*
%d -> digit
%s -> string
%.1f -> precision
%p -> pointer
*/

/* C11 standard
char buffer[1000];
printf("Enter a string: ");
scanf_s("%[^\n]1000s", buffer, (unsigned)sizeof(buffer));
printf("You entered: %s\n", buffer);
*/

/* using the pre-processor directive	#define _CRT_SECURE_NO_WARNINGS
char buffer[1000];
printf("type something\n");

scanf("%[^\n]1000s", buffer);

printf("You entered: %s\n", buffer);
*/

/*
Three streams
(read as standard-input, standard-output, standard-error)
stdin -> gets the input from keyboard
stdout -> prints the output on screen
strderr -> prints the output on screen
*/

void fahrenheit_to_celcius();
void celcius_to_fahrenheit();


int main() {



}

