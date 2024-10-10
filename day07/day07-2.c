#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(void) {

	double x = 0;
	double y = 0;
	double PI;
	int count = 0, of_circle = 0, of_count = 0;

	srand(time(NULL));
	
	
	for (int i = 1; i <= 100; i++)
	{
		while (count < 10000000) {
			x = (double)rand() / (double)RAND_MAX;
			y = (double)rand() / (double)RAND_MAX;
			if (sqrt(pow(x, 2) + pow(y, 2) < 1)) {
				of_circle++;// 원 안에 점 찍은 갯수 세기
			}
			of_count++;//반복한 횟수 세기
			count++;//반복을 위한 count증가

		}
		count = 0;//다시 반복을 위한 count초기화
		PI = 4 * ((double)of_circle / (double)of_count);//파이값 저장 of_circle와 of_count는 실수계산을 위해 double 지정
		
		printf("%d%%진행.. 원주율 : %lf ", i, PI);
		for (int o = 0; o < i / 5; o++)// ■는 
		{
			printf("■");
		}
		for (int a = 0; a < 20 - i / 5; a++)
		{
			printf("□");
		}
		printf("\n");
	}
	



	return 0;
}