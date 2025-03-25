#include <stdio.h>
#include <time.h> 

int main()
{
	time_t now; // time_t is a clock tick value. (number of seconds since 01/01/70 - EPOCH)
	time(&now); // time func. gets system current epoch and saves it in now var
	printf("%s",ctime(&now)); // ctime translate epoch to human readable timestamp
	return(0);
}
