#include <stdio.h>

void swap(int* num1, int* num2) {

	int save;
	save = *num2;
	*num2 = *num1;
	*num1 = save;
}



int main(void) {

	int num1 = 10, num2 = 20;
	int* num;

	printf("num1 = %d, num2 = %d\n", num1, num2);
	swap(&num1, &num2);
	printf("num1 = %d, num2 = %d\n", num1, num2);


	return 0;
}