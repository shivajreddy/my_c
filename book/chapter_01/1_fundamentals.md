g++, clang are the compilers

- C99 is latest C standard

// line comments are introduced like this

/*
Multiline comments
are introduced like this
*/

- stdio.h is the standard library of C
- C is case-sensitive language

%d -> digit
%6d -> number with width of 6 digits
%10d -> number with width of 10 digits
%s -> string
%.1f -> precision
%p -> pointer

// C11 standard
char buffer[1000];
printf("Enter a string: ");
scanf_s("%[^\n]1000s", buffer, (unsigned)sizeof(buffer));
printf("You entered: %s\n", buffer);

// using the pre-processor directive	#define _CRT_SECURE_NO_WARNINGS
char buffer[1000];
printf("type something\n");

scanf("%[^\n]1000s", buffer);

printf("You entered: %s\n", buffer);

Three streams
(read as standard-input, standard-output, standard-error)
stdin -> gets the input from keyboard
stdout -> prints the output on screen
strderr -> prints the output on screen



- Array
creating an array will set the value of the variable to the
pointer of the first element with type of the elmenet that
the array holds.

```c
int arr[6] = {16, 17, 18, 19, 20, 21};
printf("arr: %p\n", arr);
printf("arr.size %d\n", sizeof(arr));
printf("*arr %d\n", *arr);
printf("*arr+1 %d\n", *(arr + 1));

char letters[10] = {'f', 'a', 'm', 'i', 'l', 'a', 'r' };

printf("%p\n", letters);
printf("%c\n", *letters);
printf("%c\n", *(letters+1));
printf("%c\n", *(letters+2));
printf("size of array: %lu bytes\n", sizeof(letters));
printf("%c\n", *(letters+20));

// print all the letters in the array
for(int i=0; i<sizeof(letters);i++)
  printf("%d:%c\n", i, letters[i]);
```


- Pointer Arithmetic
```c
int x = 10;

int *ptr_x = &x;
printf("ptr_x: %p\n", ptr_x);
printf("*ptr_x: %d\n", *ptr_x);

ptr_x += 1; // will point to garbage value
printf("ptr_x: %p\n", ptr_x);
printf("*ptr_x: %d\n", *ptr_x);

char letter = 'a';
printf("letter: %c\n", letter);
printf("size of letter: %d bytes\n", sizeof(letter));

char *ptr_letter = &letter;
printf("&letter: %p\n", &letter);
printf("ptr_x: %p\n", ptr_letter);
```
