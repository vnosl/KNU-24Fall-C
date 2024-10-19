#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void err(char* num, int length) {

	int ok = 0;
	for (int i = 0; i < length; i++)
	{

	if (*(num + i) >= 65 && *(num + i) <= 90 || *(num + i) >= 97 && *(num + i) <= 122)
	{
		ok++;
	}
	}

	if (ok != length)
	{
		printf("영어만 입력해주세요");
		exit(0);
	}

}

int main(void) {
	char* num1;
	char temp;

	num1 = (char*)malloc(sizeof(char) * 100);

	scanf_s("%s", num1, 100);  // 문자열 입력
	printf("입력된 문자열: %s\n", num1);  // 원래 문자열 출력

	int length = strlen(num1);  // 문자열 길이 저장

	err(num1, length);

	for (int i = 0; i < length / 2; i++) {
		// 문자 교환
		temp = *(num1 + i);
		*(num1 + i) = *(num1 + length - (i + 1));
		*(num1 + length - (i + 1)) = temp;
	}

	printf("역순 문자열: %s\n", num1);  // 역순 문자열 출력

	free(num1);  // 동적 할당 메모리 해제
	return 0;
}