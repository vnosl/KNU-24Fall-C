#include<stdio.h>

int main(void) {

	int num1;
	double num2, num3, num4 = 0;

	printf("���ϴ� ����� �Է��Ͻÿ�.\n");
	printf("1.���ϱ� 2.���� 3.���ϱ� 4.������\n");
	printf("��� : ");
	scanf_s("%d",&num1);
		
	printf("���� 1 �Է� : ");
	scanf_s("%lf", &num2);
	printf("���� 2 �Է� : ");
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
		printf("�߸� �Է��ϼ̽��ϴ�.");

	}

	return 0;
}