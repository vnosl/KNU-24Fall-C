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
		printf("��� �Է����ּ���");
		exit(0);
	}

}

int main(void) {
	char* num1;
	char temp;

	num1 = (char*)malloc(sizeof(char) * 100);

	scanf_s("%s", num1, 100);  // ���ڿ� �Է�
	printf("�Էµ� ���ڿ�: %s\n", num1);  // ���� ���ڿ� ���

	int length = strlen(num1);  // ���ڿ� ���� ����

	err(num1, length);

	for (int i = 0; i < length / 2; i++) {
		// ���� ��ȯ
		temp = *(num1 + i);
		*(num1 + i) = *(num1 + length - (i + 1));
		*(num1 + length - (i + 1)) = temp;
	}

	printf("���� ���ڿ�: %s\n", num1);  // ���� ���ڿ� ���

	free(num1);  // ���� �Ҵ� �޸� ����
	return 0;
}