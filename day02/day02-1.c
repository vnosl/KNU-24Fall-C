#include<stdio.h>

int main(void) {

	int num1;
	double num2, num3, num4 = 0;

	printf("원하는 기능을 입력하시오.\n");
	printf("1.더하기 2.빼기 3.곱하기 4.나누기\n");
	printf("기능 : ");
	scanf_s("%d",&num1);
		
	printf("숫자 1 입력 : ");
	scanf_s("%lf", &num2);
	printf("숫자 2 입력 : ");
	scanf_s("%lf", &num3);

	if (num1 == 1) {
		num4 = num2 + num3;
		printf("%lf + %lf = %lf", num2, num3, num4);
	}
	else if (num1 == 2) {
		num4 = num2 - num3;
		printf("%lf - %lf = %lf", num2, num3, num4);
	}
	else if (num1 == 3) {
		num4 = num2 * num3;
		printf("%lf * %lf = %lf", num2, num3, num4);
	}
	else if (num1 == 4) {
		num4 = num2 / num3;
		printf("%lf / %lf = %lf", num2, num3, num4);
	}
	else {
		printf("잘못 입력하셨습니다.");

	}

	return 0;
}