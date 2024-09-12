#include<stdio.h>

int main(void) {

	for (int num1 = 0; num1 <= 99; num1++)
	{
		if (num1 % 7 == 0 || num1 % 12 == 0)
		{
			printf("%d\n", num1);
		}
	}


	return 0;
}