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
	printf("첫번째 벡터(x,y,z) : ");
	scanf_s("%d, %d, %d", &a.x, &a.y, &a.z);
	printf("두번째 벡터(x,y,z) : ");
	scanf_s("%d, %d, %d", &b.x, &b.y, &b.z);

	printf("입력된 첫번째 벡터\t%d,\t%d,\t%d\n", a.x, a.y, a.z);
	printf("입력된 두번째 벡터\t%d,\t%d,\t%d\n", b.x, b.y, b.z);
	printf("\n-------------------------\n");
	printf("1. 벡터의 합\n");
	printf("2. 벡터의 차\n");
	printf("3. 벡터의 외적\n");
	printf("4. 벡터의 내적\n");
	printf("5. 종료\n");
	printf("-------------------------\n");



	while (1)
	{
		printf("명령 입력 : ");
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
			printf("프로그램을 종료합니다.");
			return 0;
			break;
		default:
			printf("1~5숫자로 다시 입력해주세요.\n");
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

	printf("벡터의 내적은 : vec1·vec2 = %d\n", sumop);
}

void vector_subop(num a, num b) {
	int subop_x, subop_y, subop_z;

	subop_x = (a.y * b.z - a.z * b.y);
	subop_y = (a.z * b.x - a.x * b.z);
	subop_z = (a.x * b.y - a.y * b.x);

	printf("벡터의 외적은x = %d, y = %d, z = %d\n", subop_x, subop_y, subop_z);
}