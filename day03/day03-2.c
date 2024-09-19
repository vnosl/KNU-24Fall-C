#include<stdio.h>

int fact(int num);


int main(void) {

	int num1;
	scanf_s("%d", &num1);

	int num2 = fact(num1);


	printf("%d", num2);

	return 0;
}


int fact(int num) {

	int res;

	if (num == 0 || num == 1)
	{
		res = 1;
		return res;
	}
	res = num * fact(num - 1);
}