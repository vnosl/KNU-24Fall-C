//malloc = ����â��

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student
{
	int snum;
	char name[100];
	int score;
};



int main(void) {

	/*int N;
	struct Student person[2];

	person[0].snum = 1111;
	strcpy_s(person[0].name, 100, "ö��");
	person[0].score = 100;
	*/
	int min = 999, max = 0, avg = 0;
	int num1;
	int* stud_num;
	char** name;
	//char* name;
	int* score;

	printf("�л����� �Է����ּ��� : ");
	scanf_s("%d", &num1);

	stud_num = (int*)malloc(sizeof(int) * num1);
	name = (char**)malloc(sizeof(char*) * num1);
	//name = (char*)malloc(num1 * 100 * sizeof(char));
	score = (int*)malloc(sizeof(int) * num1);

	for (int i = 0; i < num1; i++)
	{
		name[i] = (char*)malloc(100 * sizeof(char));
	}
	


	for (int i = 0; i < num1 ; i++)
	{
		printf("�й� : ");
		scanf_s("%d", &stud_num[i]);

		printf("�̸� : ");
		scanf_s("%s", name[i], 100);
		//name+(100*i)

		printf("���� : ");
		scanf_s("%d", &score[i]);

	}

	for (int i = 0; i < num1; i++)
	{
		printf("%d %s %d\n", stud_num[i], name[i], score[i]);

		//name+(100*i)
	}
	
	for (int i = 0; i < num1 ; i++)
	{
		if (max < score[i])
		{
			max = score[i];
		}
		if (min > score[i])
		{
			min = score[i];
		}
		avg += score[i];
	}
	

	printf("�ִ밪 : %d\n", max);
	printf("�ּڰ� : %d\n", min);
	printf("��հ� : %d\n", avg / num1);

	for (int i = 0; i < num1; i++)
	{
		free(name[i]);
	}

	free(stud_num);
	free(name);
	free(score);

	stud_num = NULL;
	name = NULL;
	score = NULL;
	for (int i = 0; i < num1; i++)
	{
		name[i] = NULL;
	}


	return 0;
}