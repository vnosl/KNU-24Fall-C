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
				of_circle++;// �� �ȿ� �� ���� ���� ����
			}
			of_count++;//�ݺ��� Ƚ�� ����
			count++;//�ݺ��� ���� count����

		}
		count = 0;//�ٽ� �ݺ��� ���� count�ʱ�ȭ
		PI = 4 * ((double)of_circle / (double)of_count);//���̰� ���� of_circle�� of_count�� �Ǽ������ ���� double ����
		
		printf("%d%%����.. ������ : %lf ", i, PI);
		for (int o = 0; o < i / 5; o++)// ��� 
		{
			printf("��");
		}
		for (int a = 0; a < 20 - i / 5; a++)
		{
			printf("��");
		}
		printf("\n");
	}
	



	return 0;
}