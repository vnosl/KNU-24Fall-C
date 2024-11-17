#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct NODE {
	char data[20];
	int score;
	struct NODE* next;
};

struct NODE* head;


struct NODE* create_std(char name[20], int score) {
	struct NODE* new_std = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy_s(new_std->data, sizeof(name), name);
	new_std->score = score;
	new_std->next = NULL;

	return new_std;
}

int insert_std(struct NODE* new_std) {
	struct NODE* prev;
	struct NODE* cur;

	prev = head;
	cur = head->next;

	while (cur != NULL) {

		if (new_std->score > cur->score) {
			prev->next = new_std;
			new_std->next = cur;
			return 1;
		}

		prev = cur;
		cur = cur->next;
	}

	if (cur == NULL) {
		prev->next = new_std;
		return 2;
	}

	return 0;

}


void print_std() {
	struct NODE* cur = head->next;

	printf("�̸�\t\t����\n");
	while (cur != NULL) {
		printf("%s\t:\t%d\n", cur->data, cur->score);

		cur = cur->next;
	}
}


int del(char name[20]) {
	struct NODE* prev = head;
	struct NODE* cur = NULL;

	cur = head->next;

	while (cur != NULL) {
		if (strcmp(cur->data, name) == 0) {

			if (cur->next == NULL) {
				prev->next = NULL;
			}
			else {
				prev->next = cur->next;
			}
			free(cur);

			return 1;
		}

		prev = cur;
		cur = cur->next;
	}

	return 0;
}


void free_std(struct NODE* std) {
	struct NODE* cur = std;
	struct NODE* next = cur->next;

	while (next != NULL) {
		free(cur);
		cur = next;
		next = next->next;
	}
}

int main() {
	head = (struct NODE*)malloc(sizeof(struct NODE));
	head->next = NULL;

	char name[20];
	int score;
	int input;


	while (1) {
		printf("1. �л��� ������ �Է�\n");
		printf("2. �л��� ���� ����\n");
		printf("3. ���α׷� ����\n");

		printf("input : ");
		scanf_s("%d", &input);

		switch (input) {
		case 1:
			printf("�л��� �̸� : ");
			scanf_s("%s", name, 20);
			printf("%s�� ���� : ", name);
			scanf_s("%d", &score);

			insert_std(create_std(name, score));
			break;

		case 2:
			printf("�л��� �̸� : ");
			scanf_s("%s", name, 20);

			del(name);
			break;

		case 3:
			free_std(head);
			return;

		default:

			break;
		}

		printf("---------------------------------------\n");
		print_std();
		printf("---------------------------------------\n");
	}


	return 0;
}