#include<stdio.h>

struct goods
{
	int ID;
	char goodsname[100];
	int price;
};

void printProduct(struct goods a) {

	printf("��ǰ ID : %d\n", a.ID);
	printf("��ǰ�� : %s\n", a.goodsname);
	printf("���� : %d��\n", a.price);

}



int main(void) {

	struct goods num[5];
	int cnt = 0;
	while (cnt < 5)
	{

		printf("��ǰ ID : ");
		scanf_s("%d", &num[cnt].ID);
		if (num[cnt].ID == 0)
		{
			break;
		}
		printf("��ǰ�� : ");
		scanf_s("%s", num[cnt].goodsname, 100);
		printf("���� : ");
		scanf_s("%d", &num[cnt].price);

		cnt++;
	}
	printf("<<�Էµ� ��ǰ ���>>\n");
	for (int i = 0; i < cnt; i++)
	{
		printProduct(num[i]);
	}
	

	

	return 0;
}