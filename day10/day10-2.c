#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum rank { FAMILY = 1, SILVER, GOLD, PLATINUM, VIP };

struct Customer {
    char* customerName;
    enum rank customerRank;
    int order_amount;
    int point;
    struct Customer* prev, * next;
};

struct Customer* head = NULL;

struct Customer* create_Customer(char* customerName, enum rank customerRank, int order_amount, int point) {
    struct Customer* new_Customer = (struct Customer*)malloc(sizeof(struct Customer));
    new_Customer->customerName = (char*)malloc(strlen(customerName) + 1);
    new_Customer->customerRank = customerRank;
    new_Customer->order_amount = order_amount;
    new_Customer->point = point;
    strcpy(new_Customer->customerName, customerName);
    new_Customer->prev = NULL;
    new_Customer->next = NULL;
    return new_Customer;
}

int Compare(struct Customer* A, struct Customer* B) {
    if (A->customerRank != B->customerRank) {
        return B->customerRank - A->customerRank;  
    }
    if (A->order_amount != B->order_amount) {
        return B->order_amount - A->order_amount;  
    }
    return B->point - A->point; 
}

int Check_Name(char* customerName) {
    struct Customer* cur = head->next;
    while (cur != NULL) {
        if (strcmp(cur->customerName, customerName) == 0) {
            return -1;  // �ߺ��� �̸�
        }
        cur = cur->next;
    }
    return 0;  // �ߺ� ����
}

void insert_Customer(struct Customer* new_Customer) {
    if (Check_Name(new_Customer->customerName) == -1) {
        printf("----------------------------\n");
        printf("�ߺ��� �̸��� �ֽ��ϴ�!\n");
        free(new_Customer->customerName);
        free(new_Customer);
        return;
    }

    struct Customer* cur = head->next;
    struct Customer* prev = head;
    while (cur != NULL && Compare(cur, new_Customer) > 0) {
        prev = cur;
        cur = cur->next;
    }
    new_Customer->next = cur;
    if (cur != NULL) {
        cur->prev = new_Customer;
    }
    prev->next = new_Customer;
    new_Customer->prev = prev;
}

int delete_Customer(char* customerName) {
    struct Customer* cur = head->next;
    while (cur != NULL) {
        if (strcmp(cur->customerName, customerName) == 0) {
            if (cur->prev != NULL) {
                cur->prev->next = cur->next;
            }
            if (cur->next != NULL) {
                cur->next->prev = cur->prev;
            }
            free(cur->customerName);
            free(cur);
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

void modify_Customer(char* customerName, enum rank customerRank, int order_amount, int point) {
    struct Customer* cur = head->next;
    while (cur != NULL) {
        if (strcmp(cur->customerName, customerName) == 0) {
            cur->customerRank = customerRank;
            cur->order_amount = order_amount;
            cur->point = point;
            return;
        }
        cur = cur->next;
    }
    printf("�Է��Ͻ� �� ������ ã�� �� �����ϴ�.\n");
}

void print_nodes() {
    printf("<�� ����>\n");
    struct Customer* cur = head->next;
    while (cur != NULL) {
        printf("�̸� : %s, ��� : %d, �ֹ��� : %d, ����Ʈ : %d\n",
            cur->customerName, cur->customerRank, cur->order_amount, cur->point);
        cur = cur->next;
    }
}

void free_all_nodes() {
    struct Customer* cur = head;
    while (cur != NULL) {
        struct Customer* temp = cur;
        cur = cur->next;
        free(temp->customerName);
        free(temp);
    }
}

int main() {
    int choice = 0;
    int order_amount, point;
    enum rank CustomerRank;
    char name[100];

    head = (struct Customer*)malloc(sizeof(struct Customer));
    head->next = NULL;
    head->prev = NULL;

    while (choice != 4) {
        printf("----------------------------\n");
        print_nodes();
        printf("----------------------------\n");
        printf("1. ���� ������ �Է�\n");
        printf("2. ���� ������ ����\n");
        printf("3. ���� ������ ����\n");
        printf("4. ���α׷� ����\n");
        printf("input : ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            printf("�� �̸� : ");
            scanf_s("%s", name);
            printf("��� (1 : FAMILY, 2 : SILVER, 3 : GOLD, 4 : PLATINUM, 5 : VIP) : ");
            scanf_s("%d", &CustomerRank);
            if (CustomerRank < FAMILY || CustomerRank > VIP) {
                printf("�߸��� ����Դϴ�!\n");
                continue;
            }
            printf("�ֹ��� : ");
            scanf_s("%d", &order_amount);
            if (order_amount < 0) {
                printf("�ֹ����� 0 �̻��̾�� �մϴ�!\n");
                continue;
            }
            printf("����Ʈ : ");
            scanf_s("%d", &point);
            if (point < 0) {
                printf("����Ʈ�� 0 �̻��̾�� �մϴ�!\n");
                continue;
            }
            insert_Customer(create_Customer(name, CustomerRank, order_amount, point));
        }
        else if (choice == 2) {
            printf("� ���� ������ �����Ͻðڽ��ϱ� : ");
            scanf_s("%s", name);
            if (delete_Customer(name)) {
                printf("���������� ���ŵǾ����ϴ�.\n");
            }
            else {
                printf("�Է��Ͻ� �� ������ ã�� �� �����ϴ�.\n");
            }
        }
        else if (choice == 3) {
            printf("� ���� ������ �����Ͻðڽ��ϱ� : ");
            scanf_s("%s", name);
            printf("������ ��� (1 : FAMILY, 2 : SILVER, 3 : GOLD, 4 : PLATINUM, 5 : VIP) : ");
            scanf_s("%d", &CustomerRank);
            if (CustomerRank < FAMILY || CustomerRank > VIP) {
                printf("�߸��� ����Դϴ�!\n");
                continue;
            }
            printf("������ �ֹ��� : ");
            scanf_s("%d", &order_amount);
            printf("������ ����Ʈ : ");
            scanf_s("%d", &point);
            modify_Customer(name, CustomerRank, order_amount, point);
        }
        else if (choice != 4) {
            printf("[WARNING!] �߸��� �Է��Դϴ�!\n");
        }
    }

    printf("���α׷��� ���������� ����Ǿ����ϴ�.\n");
    free_all_nodes();
    return 0;
}
