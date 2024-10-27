#include<stdio.h>

typedef struct{

	int x;
	int y;
	int z;

}num;

void vector_sum(num a, num b);
void vector_sub(num a, num b);
void vector_sumop(num a, num b);
void vector_subop(num a, num b);

int main(void) {
	int num1;
	num a, b;
	printf("ù��° ����(x,y,z) : ");
	scanf_s("%d, %d, %d", &a.x, &a.y, &a.z);
	printf("�ι�° ����(x,y,z) : ");
	scanf_s("%d, %d, %d", &b.x, &b.y, &b.z);

	printf("�Էµ� ù��° ����\t%d,\t%d,\t%d\n", a.x, a.y, a.z);
	printf("�Էµ� �ι�° ����\t%d,\t%d,\t%d\n", b.x, b.y, b.z);
	printf("\n-------------------------\n");
	printf("1. ������ ��\n");
	printf("2. ������ ��\n");
	printf("3. ������ ����\n");
	printf("4. ������ ����\n");
	printf("5. ����\n");
	printf("-------------------------\n");



	while (1)
	{
		printf("��� �Է� : ");
		scanf_s("%d", &num1);

		switch (num1)
		{
		case 1:
			vector_sum(a, b);
			break;
		case 2:
			vector_sub(a, b);
			break;
		case 3:
			vector_subop(a, b);
			break;
		case 4:
			vector_sumop(a, b);
			break;
		case 5:
			printf("���α׷��� �����մϴ�.");
			return 0;
			break;
		default:
			printf("1~5���ڷ� �ٽ� �Է����ּ���.\n");
			break;
		}


	}
	return 0;
}

void vector_sum(num a, num b) {
	int sum_x, sum_y, sum_z;

	sum_x = (a.x + b.x);
	sum_y = (a.y + b.y);
	sum_z = (a.z + b.z);

	printf("x = %d, y = %d, z = %d\n", sum_x, sum_y, sum_z);

}

void vector_sub(num a, num b) {
	int sub_x, sub_y, sub_z;

	sub_x = (a.x - b.x);
	sub_y = (a.y - b.y);
	sub_z = (a.z - b.z);

	printf("x = %d, y = %d, z = %d\n", sub_x, sub_y, sub_z);
}

void vector_sumop(num a, num b) {
	int sumop;

	sumop = (a.x * a.x) + (a.z * a.z) + (a.z * a.z);

	printf("������ ������ : vec1��vec2 = %d\n", sumop);
}

void vector_subop(num a, num b) {
	int subop_x, subop_y, subop_z;

	subop_x = (a.y * b.z - a.z * b.y);
	subop_y = (a.z * b.x - a.x * b.z);
	subop_z = (a.x * b.y - a.y * b.x);

	printf("������ ������x = %d, y = %d, z = %d\n", subop_x, subop_y, subop_z);
}