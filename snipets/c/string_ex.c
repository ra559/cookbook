#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	
	char buffer[32]; // will store up to 32 characters
	printf("Name: ");
	fgets(buffer, 32, stdin); // fgets reads the chars from std
	printf("Hello, %s", buffer);
	return 0;
}
