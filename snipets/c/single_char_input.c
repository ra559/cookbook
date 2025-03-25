#include <stdio.h>

int main()
{
	char gender;
	printf("Type Single Character Gender Idenfifier\n\tM - Masculine\n\tF - Feminine \n\tO - Other\n");
	scanf("%c",&gender);
	printf("You have selected \"%c\" \n", gender);
	return(0);
}
