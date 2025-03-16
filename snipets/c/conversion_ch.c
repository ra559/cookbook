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

