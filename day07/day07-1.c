#include<stdio.h>

int main(void) {

	int num;
	printf("피라미드의 층 수를 입력해 주세요 : ");
	scanf_s("%d", &num);//층수 입력받기



	for (int i = 1; i <= num; i++)//층 수만큼 반복
	{
		for (int o = 0; o < num - i; o++)//앞쪽 공백 입력 층수 - 반복수
		{
			printf(" ");
			
		}
		for (int z = 0; z < i*2-1; z++)//*갯수 반복 : 반복수 * 2 - 1
		{
			printf("*");

		}
		printf("\n");//층 나누기

	}



	return 0;
}