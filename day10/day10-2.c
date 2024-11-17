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
            return -1;  // 중복된 이름
        }
        cur = cur->next;
    }
    return 0;  // 중복 없음
}

void insert_Customer(struct Customer* new_Customer) {
    if (Check_Name(new_Customer->customerName) == -1) {
        printf("----------------------------\n");
        printf("중복된 이름이 있습니다!\n");
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
    printf("입력하신 고객 정보를 찾을 수 없습니다.\n");
}

void print_nodes() {
    printf("<고객 정보>\n");
    struct Customer* cur = head->next;
    while (cur != NULL) {
        printf("이름 : %s, 등급 : %d, 주문량 : %d, 포인트 : %d\n",
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
        printf("1. 고객의 정보를 입력\n");
        printf("2. 고객의 정보를 제거\n");
        printf("3. 고객의 정보를 수정\n");
        printf("4. 프로그램 종료\n");
        printf("input : ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            printf("고객 이름 : ");
            scanf_s("%s", name);
            printf("등급 (1 : FAMILY, 2 : SILVER, 3 : GOLD, 4 : PLATINUM, 5 : VIP) : ");
            scanf_s("%d", &CustomerRank);
            if (CustomerRank < FAMILY || CustomerRank > VIP) {
                printf("잘못된 등급입니다!\n");
                continue;
            }
            printf("주문량 : ");
            scanf_s("%d", &order_amount);
            if (order_amount < 0) {
                printf("주문량은 0 이상이어야 합니다!\n");
                continue;
            }
            printf("포인트 : ");
            scanf_s("%d", &point);
            if (point < 0) {
                printf("포인트는 0 이상이어야 합니다!\n");
                continue;
            }
            insert_Customer(create_Customer(name, CustomerRank, order_amount, point));
        }
        else if (choice == 2) {
            printf("어떤 고객의 정보를 제거하시겠습니까 : ");
            scanf_s("%s", name);
            if (delete_Customer(name)) {
                printf("성공적으로 제거되었습니다.\n");
            }
            else {
                printf("입력하신 고객 정보를 찾을 수 없습니다.\n");
            }
        }
        else if (choice == 3) {
            printf("어떤 고객의 정보를 수정하시겠습니까 : ");
            scanf_s("%s", name);
            printf("수정할 등급 (1 : FAMILY, 2 : SILVER, 3 : GOLD, 4 : PLATINUM, 5 : VIP) : ");
            scanf_s("%d", &CustomerRank);
            if (CustomerRank < FAMILY || CustomerRank > VIP) {
                printf("잘못된 등급입니다!\n");
                continue;
            }
            printf("수정할 주문량 : ");
            scanf_s("%d", &order_amount);
            printf("수정할 포인트 : ");
            scanf_s("%d", &point);
            modify_Customer(name, CustomerRank, order_amount, point);
        }
        else if (choice != 4) {
            printf("[WARNING!] 잘못된 입력입니다!\n");
        }
    }

    printf("프로그램이 성공적으로 종료되었습니다.\n");
    free_all_nodes();
    return 0;
}
