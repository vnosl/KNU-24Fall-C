#include <stdio.h>

int main(void) {

	int num1 = 100, num2 = 200;
	int* pnum;

	pnum = &num1; // ������ num1�� �ּҸ� �־��ֱ�
	(*pnum) += 30; // ��ȣ�� �̿��ϴ� ������ �ް����� �����ϱ� ����

	pnum = &num2;
	(*pnum) -= 30;

	printf("num1 : %d\n", num1);
	printf("num1 : %d\n", num2);

	return 0;
}