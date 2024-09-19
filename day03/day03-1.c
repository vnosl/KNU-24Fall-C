#include<stdio.h>

int sosu(int num1);


int main(void) {

	int num1 = 0;

	scanf_s("%d", &num1);

	sosu(num1);
	if (sosu(num1) == 1)
	{
		printf("소수");
	}
	else {
		printf("노소수");
	}


	return 0;
}



int sosu(int num1) {

	for (int i = 2; i < num1 / 2; i++){

		if (num1 % i == 0) {
			return 0;
		}

	}
	return 1;
}