#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

int main(void) {
	int array[SIZE][SIZE];

	fillRandom(array); // �迭 ���� �ʱ�ȭ
	printArray(array); // �迭 ���
	movePointer(array); // �����͸� �̿��� �̵�

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

		printf("���� ��ġ : (%d, %d), �迭�� �� : %d\n", x , y, *((int*)array + (x * 10 + y)));

		
		i = i + (*((int*)array + (x * 10 + y)));
		
	}
	printf("�� �̻� �̵��� �� �����ϴ�.\n");
	printf("���� ��ġ : (%d, %d), �迭�� �� : %d\n", x, y, *((int*)array + (x * 10 + y)));
		
}