#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

/*
fahrenheit_to_celcius();

printf("\n");

for (int fahr = 0; fahr <= 300; fahr += 20)
	printf("%3d %8.3f\n", fahr, (5.0 / 9.0) * (fahr - 32));

//celcius_to_fahrenheit(0, 300, 20);
*/

void fahrenheit_to_celcius() {
	int fahrenheit_value = LOWER;
	double celcius_value;

	while (fahrenheit_value <= UPPER) {
		celcius_value = 5.0 / 9.0 * (fahrenheit_value - 32);
		/* <Fahrenheight> <tab> <Celcius(at_least 12 characters wide)> */
		printf("%d\t%12f\n", fahrenheit_value, celcius_value);
		fahrenheit_value += STEP;
	}
}

void celcius_to_fahrenheit() {
	int celsius = LOWER;
	int fahrenheit;

	while (celsius <= UPPER) {
		fahrenheit = celsius * 9 / 5 + 32;
		/* <Celcius> <tab> <Fahrenheight(at_least 6 characters wide)> */
		printf("%d\t%6d\n", celsius, fahrenheit);
		celsius += STEP;
	}
}
