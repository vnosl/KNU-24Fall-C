#include <stdio.h>

int main(void) {

	int num1 = 100, num2 = 200;
	int* pnum;

	pnum = &num1; // 변수에 num1의 주소를 넣어주기
	(*pnum) += 30; // 괄호를 이용하는 이유는 햇갈림을 방지하기 위해

	pnum = &num2;
	(*pnum) -= 30;

	printf("num1 : %d\n", num1);
	printf("num1 : %d\n", num2);

	return 0;
}