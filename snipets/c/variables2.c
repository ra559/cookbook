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
