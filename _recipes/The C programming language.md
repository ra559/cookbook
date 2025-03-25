---
layout: page
title: C
---

# {{page.title}}

> This is the start of my journey to learning C

# Hello World!
First install `gcc` and `make`: `sudo apt install gcc make` 
This is hello world in c:

```c
#include <stdio.h>
int main(){
	printf("Hello World!\n");
}
```
To execute this, first compile it with: `gcc filename.c`. Then run: `./a.out` 

Another hello world example. This one explicitly returns 0 and uses puts rather than printf
```c
#include <stdio.h>
int main()
{
	puts("Hello, World");
	return 0;
}
```

Comments in c are:
```c
/* this is a multi line comment
this is another line */
// this is a single line comment
// this is another line
```

## C preprocessor

- **Preprocessor Directives**: These are instructions that prepare the source code for compiling, starting with a hash (#) character. Common directives include `#define` and `#include`.
- **Include Directive**: This directive inserts the contents of a specified file into the code. Angle brackets are used for default directories, while double quotes are for the same directory as the source code.
- **Define Directive**: Used for substitution, it creates constants and macros, which are expanded by the compiler throughout the code. Constants are usually written in all caps for easy identification.
* Other preprocessors:
	* `#error`
	* `#if`
	* `#elif`
	* `#line`
	* `#else`
	* `#ifdef`
	* `#pragma`
	* `#endif
	* `#ifndef`
	* `#undef`
* Location of header files: `/usr/include` and `/usr/local/incude`
* when using `<>` the compiler looks for header files in the default directory
* `#define` is used for defining constants. Here is an example:
```c
#include <stdio.h>
#define GREETING "Hellow World"
int main ()
{
	puts (GREETING);
	return 0;
}
```
## C data types
c has 4 basic data types:
* **Char**:  Stores a single character or byte
* **Int**: Stores integer or whole numbers
* **Float**: Stores decimals with single precision accurate up to 8 digits
* **Double**: Stores decimals with double precision accurate up to 16 digits

### Data types qualifiers:
they help define the data type scope
* **Short**: This qualifier reduces the storage size of an integer. For example, `short int` typically uses less memory than a standard `int`.
 * **Long**: This qualifier increases the storage size of an integer. For example, `long int` can store larger values than a standard `int`.
* **Signed**: This is the default qualifier for integer types, meaning the variable can store both positive and negative values.
* **Unsigned**:This qualifier means the variable can only store positive values, effectively doubling the maximum positive value it can hold compared to a signed variable.
* **Long long:** is used for storing larger integer values than the standard `int` or `long` types. It typically provides at least 64 bits of storage, allowing for a much larger range of values.****
- **Volatile**: This qualifier tells the compiler that a variable's value may change at any time, preventing the compiler from optimizing code that assumes the value remains constant.

### Example program using input and variables
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char gender;
	int age;
	float height;
	double money;
	
	printf("Enter gender: ");
	scanf("%c",&gender); // %c for character input
	printf("Enter Age: "); 
	scanf("%i",&age); // %i for ints
	printf("Enter height: ");
	scanf("%f",&height); // %f for floats
	printf("Enter money: ");
	scanf("%lg",&money); // %lg for doubles

	// output
	puts("You have entered the following values:");
	printf("Gender:%c",gender);
	printf("\n");
	printf("Age:%i",age);
	printf("\n");
	printf("Heigh:%f",height);
	printf("\n");
	printf("Money:%lg",money);
	printf("\n");
	return 0;
	
}
```

## Other data types
* Void is used for allocating memory
* C has no string data type. Instead an array of characters of a defined size is used. Here is an example:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	
	char buffer[32];
	printf("Name: ");
	fgets(buffer, 32, stdin);
	printf("Hello, %s", buffer);
	return 0;
}
```

## Printf

example program that uses variables with printf:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char gender;
	int age;
	float height;
	double money;
	
	printf("Enter gender: ");
	scanf("%c",&gender); // %c for character input
	printf("Enter Age: "); 
	scanf("%i",&age); // %i for ints
	printf("Enter height: ");
	scanf("%f",&height); // %f for floats
	printf("Enter money: ");
	scanf("%lg",&money); // %lg for doubles

	// output
/* 
	puts("You have entered the following values:");
	printf("Gender:%c",gender);
	printf("\n");
	printf("Age:%i",age);
	printf("\n");
	printf("Heigh:%f",height);
	printf("\n");
	printf("Money:%lg",money);
	printf("\n");
*/	
	printf("You have entered the following values\nGender:\t%c\nAge:\t%i\nHeight:\t%f\nMoney:\t%lg\n",gender, age, height, money);
	return 0;
	
}
```

### Conversion characters
####  **Integer Types**

- `%d` or `%i` → Signed decimal integer
- `%u` → Unsigned decimal integer
- `%o` → Unsigned octal integer
- `%x` → Unsigned hexadecimal integer (lowercase)
- `%X` → Unsigned hexadecimal integer (uppercase)

#### **Floating-Point Types**

- `%f` → Decimal floating-point notation
- `%F` → Same as `%f`, but uppercase
- `%e` → Scientific notation (lowercase, e.g., `1.23e+03`)
- `%E` → Scientific notation (uppercase, e.g., `1.23E+03`)
- `%g` → Uses `%f` or `%e`, whichever is shorter (removes trailing zeros)
- `%G` → Uses `%F` or `%E`, whichever is shorter

#### **Character & String Types**

- `%c` → Single character
- `%s` → String of characters
- `%p` → Pointer address

#### **Other Special Format Specifiers**

- `%n` → Writes the number of printed characters to a variable (requires an `int*` argument)
- `%%` → Prints a literal `%` character

#### **Length Modifiers (Optional)**

These modify integer formats (`d`, `i`, `u`, `o`, `x`, `X`):

- `%h` → Short (`short int`)
- `%hh` → Very short (`signed char`)
- `%l` → Long (`long int`)
- `%ll` → Long long (`long long int`)
- `%j` → `intmax_t`
- `%z` → `size_t`
- `%t` → `ptrdiff_t`
### Example program
```c
#include <stdio.h>

int main() {
    int i = -42;
    unsigned int u = 42;
    float f = 3.14159;
    double d = 2.71828;
    char c = 'A';
    char str[] = "Hello, world!";
    void *ptr = (void *)&i;
    int count;

    printf("Integer (%%d, %%i): %d, %i\n", i, i);
    printf("Unsigned integer (%%u): %u\n", u);
    printf("Octal (%%o): %o\n", u);
    printf("Hexadecimal (%%x, %%X): %x, %X\n", u, u);

    printf("Floating-point (%%f, %%F): %f, %F\n", f, f);
    printf("Scientific notation (%%e, %%E): %e, %E\n", d, d);
    printf("Shortest representation (%%g, %%G): %g, %G\n", d, d);

    printf("Character (%%c): %c\n", c);
    printf("String (%%s): %s\n", str);
    printf("Pointer (%%p): %p\n", ptr);

    printf("Percent sign (%%%%): %%\n");

    printf("Number of characters printed so far (%%n): ");
    printf("%n", &count);
    printf("%d\n", count);
    return 0;
}
```

## Constants
No different from any other language

### Example:
```c
#include <stdio.h>
int main(){
	const int count = 4;
	printf("Please count to %d\n",count);
	printf("Do not count to %d\n",count+1);
	printf("Do not stop at %d\n",count-1);
	return(0);
}
```

> **Note:**
> These two statements are not the same: `const char b = "z";` and `const char b = 'z';` 
> `"h"` is a **string literal**, which in C means an array of characters that ends with a null terminator `'\0'`.So, `"h"` is actually equivalent to a `const char[2]` array, containing:
    - The character `'h'`
    - The null terminator `'\0'`
-`'h'` is a **character literal** and represents a single character with a numeric ASCII value (in this case, the ASCII value of `'h'` is 104).

## Variable scope
* **Storage class:** sets a variable scope (variables availability to other functions)
* **Auto:** private variable local to a function. The values are released from memory after the function quits. ***This is the default class***
* **Static:** Also local to their functions but the value is retained when the function quits 
* **Extern**: variables that exist outside of any function. These are available to all functions. Like a global variable.
> **Note:**
* `extern` is used to declare a **global variable or function that is defined in another file** or in a different part of the program. It tells the compiler, "This variable exists somewhere else, so don't allocate memory for it here; just reference it."
* ***Example Use Case for `extern`:** 
	* If you're working with multiple files in your C program and you want to access the same global variable across them, you'd use `extern` to avoid redefining it.
### Example:
```c
#include <stdio.h>
// Global variable
int global_var = 10;
void demonstrateScopes() {
    int local_var = 5;   
    static int static_var = 0;       
    printf("Enter a new value for the global variable: ");
    scanf("%d", &global_var);    
    local_var++;            
    static_var++;       
    printf("Local variable: %d\n", local_var);
    printf("Static variable: %d\n", static_var);
    printf("Global variable (modified by user): %d\n", global_var);
}
int main() {
    printf("Initial global variable: %d\n", global_var);
    printf("\nCalling demonstrateScopes() the first time:\n");
    demonstrateScopes();
    printf("\nCalling demonstrateScopes() the second time:\n");
    demonstrateScopes(); 
    printf("\nFinal global variable in main: %d\n", global_var);
    return 0;
}
```

## Making new data types

* `typedef` (defined data types) 
	* Typically defined in a header file. Ex `include <time.h>` for `time_t` 
```c
#include <stdio.h>
#include <time.h> 

int main()
{
	time_t now; // time_t is a clock tick value. (number of seconds since 01/01/70 - EPOCH)
	time(&now); // time func. gets system current epoch and saves it in now var
	printf("%s",ctime(&now)); // ctime translate epoch to human readable timestamp
	return(0);
}
```

* the `typedef` keyword defines new data types
	* `typedef data_type new_definition`
		* EX: Define `time_t` as a long unsigned int:
			* `typedef long unsigned time_t`
* **Why create typedefs?**
	* Special data types may differ from system to system
	* The typedef keeps the data type consistent to maintain and compatible across OSs
	* Often used with structures to reduce structure declaration
	* nonstandard data types are created using typedef
	* The man page explains how the defined data type should be used
* Typedefs can be declared externally or internally

## Specifying Characters and strings
-  To declare a single character literal use `'` . Ex: `'R'` `'\n'` `'1'`
- Escape sequence literal count as a single character

| **Escape Sequence** | **Description**         | **Example Output**         |
| ------------------- | ----------------------- | -------------------------- |
| `\\`                | Backslash               | Prints a `\` character     |
| `\'`                | Single quote            | Prints a `'` character     |
| `\"`                | Double quote            | Prints a `"` character     |
| `\?`                | Question mark           | Prints a `?` character     |
| `\a`                | Alert (bell)            | Triggers an alert/beep     |
| `\b`                | Backspace               | Moves cursor back one step |
| `\f`                | Form feed               | Moves to the next page     |
| `\n`                | Newline                 | Moves to the next line     |
| `\r`                | Carriage return         | Moves to the start of line |
| `\t`                | Horizontal tab          | Inserts a tab space        |
| `\v`                | Vertical tab            | Inserts a vertical tab     |
| `\0`                | Null character          | Marks end of string (NUL)  |
| `\ooo`              | Octal number (3 digits) | Represents octal value     |
| `\xhh`              | Hexadecimal number      | Represents hex value       |
### Example program that takes a single character input
```c
#include <stdio.h>

int main()
{
	char gender;
	printf("Type Single Character Gender Idenfifier\n\tM - Masculine\n\tF - Feminine \n\tO - Other\n");
	scanf("%c",&gender);
	printf("You have selected \"%c\" \n", gender);
	return(0);
}

```

### Example program that creates a single character array
```c
#include <stdio.h>

int main()
{
	char greeting[4] = { 'H','I','\x21','\0' };
	puts(greeting);
	return(0);

}
```
* `\0` the null character makes the array a string. Null characters terminate strings in c. Remember that c does not have a string data type and character arrays are used in its place.
* Using `""` makes the text a string literal.
* The null character is added automatically to string literals.
* When manipulating strings keep the existence of the `\0` character in mind

### Example program that creates a string literal
```c
#include <stdio.h>
int main()
{
	char full_name[] = "J. A. Romero";
	puts(full_name);
}
```
* The compiler will set the buffer size when the brackets are empty
* This is the only time we can use assignment operator when working with strings

## Specifying integers and real numbers

