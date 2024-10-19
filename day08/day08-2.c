#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

int main(void) {
	int array[SIZE][SIZE];

	fillRandom(array); // 배열 랜덤 초기화
	printArray(array); // 배열 출력
	movePointer(array); // 포인터를 이용한 이동

	return 0;
}

void fillRandom(int array[SIZE][SIZE]) {
	srand(time(NULL));
	for (int o = 0; o < 10; o++)
	{
		for (int i = 0; i < 10; i++)
		{
			array[o][i] = rand() % 20 + 1;
		}
	}

}
void printArray(int array[SIZE][SIZE]) {
	
	for (int o = 0; o < 10; o++)
	{
		for (int i = 0; i < 10; i++)
		{
			printf("%2d ", array[o][i]);

		}
		printf("\n");
	}

}
void movePointer(void* array) {
	int x = 0, y = 0;
	for (int i = 0; i < 100;)
	{
		x = i / 10;
		y = i % 10;

		printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", x , y, *((int*)array + (x * 10 + y)));

		
		i = i + (*((int*)array + (x * 10 + y)));
		
	}
	printf("더 이상 이동할 수 없습니다.\n");
	printf("종료 위치 : (%d, %d), 배열의 값 : %d\n", x, y, *((int*)array + (x * 10 + y)));
		
}