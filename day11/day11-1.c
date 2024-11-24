#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

int main(void) {

	int a, b, c, d = 0;
	float e = 0, x1 = 0, x2 = 0;


	printf("a값을 입력해 주세요 : ");
	scanf_s("%d", &a);
	printf("b값을 입력해 주세요 : ");
	scanf_s("%d", &b);
	printf("c값을 입력해 주세요 : ");
	scanf_s("%d", &c);

	d = 4 * a * c;
	d = pow(b, 2) - d;

	if (d < 0)
	{
		printf("이 이차방정식은 허근입니다.");
		return 0;
	}else if (d == 0) {
		e = sqrt((float)d);
		x1 = ((float)- b + e) / (2 * (float)a);
		printf("이 이차방정식은 중근입니다 : %.2f", x1);
	}
	else {
		e = sqrt((float)d);
		x1 = ((float)-b + e) / (2 * (float)a);
		x2 = ((float)-b - e) / (2 * (float)a);
		printf("계산된 근의 값입니다. %.2f %.2f", x1, x2);
	}
	

	return 0;
}