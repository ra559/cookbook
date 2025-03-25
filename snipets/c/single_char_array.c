#include <stdio.h>

int main()
{
	char greeting[4] = { 'H','I','\x21','\0'};
	puts(greeting);
	return(0);

}
