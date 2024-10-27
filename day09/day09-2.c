#include<stdio.h>

struct goods
{
	int ID;
	char goodsname[100];
	int price;
};

void printProduct(struct goods a) {

	printf("상품 ID : %d\n", a.ID);
	printf("상품명 : %s\n", a.goodsname);
	printf("가격 : %d원\n", a.price);

}



int main(void) {

	struct goods num[5];
	int cnt = 0;
	while (cnt < 5)
	{

		printf("상품 ID : ");
		scanf_s("%d", &num[cnt].ID);
		if (num[cnt].ID == 0)
		{
			break;
		}
		printf("상품명 : ");
		scanf_s("%s", num[cnt].goodsname, 100);
		printf("가격 : ");
		scanf_s("%d", &num[cnt].price);

		cnt++;
	}
	printf("<<입력된 상품 목록>>\n");
	for (int i = 0; i < cnt; i++)
	{
		printProduct(num[i]);
	}
	

	

	return 0;
}