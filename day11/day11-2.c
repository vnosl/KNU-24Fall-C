#include<stdio.h>
#include<math.h>


int main(void) {
	int num1, num2, cut;
	double end_result, k, width, result = 0, height;

	printf("������ ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &num1);
	printf("������ �� ���� �Է��ϼ��� : ");
	scanf_s("%d", &num2);
	printf("������ �ִ� ������ �Է��ϼ��� : ");
	scanf_s("%d", &cut);

	
	for (unsigned int i = 1; i <= pow(2, cut); i = i*2)
	{
		k = num1;
		end_result = 0;
		width = (double)(num2 - num1) / i;
		for (int j = 0; j < i; j++) {
			height = pow(k, 2) + 1;
			//height = (-1) * log(1 / k) + sin(k);
			result = height * width;
			end_result += result;
			//k += width;
		}
		printf("���� : %d, ���� ��� : %lf\n", i, end_result);
	}




	return 0;
}