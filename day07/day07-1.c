#include<stdio.h>

int main(void) {

	int num;
	printf("�Ƕ�̵��� �� ���� �Է��� �ּ��� : ");
	scanf_s("%d", &num);//���� �Է¹ޱ�



	for (int i = 1; i <= num; i++)//�� ����ŭ �ݺ�
	{
		for (int o = 0; o < num - i; o++)//���� ���� �Է� ���� - �ݺ���
		{
			printf(" ");
			
		}
		for (int z = 0; z < i*2-1; z++)//*���� �ݺ� : �ݺ��� * 2 - 1
		{
			printf("*");

		}
		printf("\n");//�� ������

	}



	return 0;
}