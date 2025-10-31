#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void maxMinSales(int* sold, int n);

int main() {
    int input[100] = { 0 };
    int sold[100] = { 0 };
    int stock[100] = { 0 };
    int n = 5;
    int total_input = 0;
    int total_sold = 0;
    int choice;

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("> 원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n");
        printf("입력: ");
        scanf("%d", &choice);

        if (choice == 1) { 
            int method;
            printf("\n입고수량 입력 : 전체 상품(1), 개별 상품(2)\n입력 > ");
            scanf("%d", &method);

            if (method == 1) {
                printf("각 상품의 입고수량을 순서대로 입력하세요:\n입력 > ");
                for (int i = 0; i < n; i++) {
                    int amount;
                    scanf("%d", &amount);
                    if (amount < 0) amount = 0;
                    input[i] += amount;
                    stock[i] += amount;
                    total_input += amount;
                }
            }
            else if (method == 2) {
                int id, amount;
                printf("상품 ID 입력: ");
                scanf("%d", &id);
                id -= 1;  
                if (id < 0 || id >= n) {
                    printf("잘못된 상품ID입니다.\n");
                    continue;
                }
                printf("입고수량 입력: ");
                scanf("%d", &amount);
                if (amount < 0) amount = 0;
                input[id] += amount;
                stock[id] += amount;
                total_input += amount;
            }
            
        }
        else if (choice == 2) { 
            int method;
            printf("\n판매수량 입력 : 전체 상품(1), 개별 상품(2)\n입력 > ");
            scanf("%d", &method);

            if (method == 1) {
                printf("각 상품의 판매수량을 순서대로 입력하세요:\n입력 > ");
                for (int i = 0; i < n; i++) {
                    int amount;
                    scanf("%d", &amount);
                    if (amount < 0) amount = 0;
                    if (amount > stock[i]) {
                        total_sold += stock[i];
                        sold[i] += stock[i];
                        stock[i] = 0;
                    }
                    else {
                        sold[i] += amount;
                        stock[i] -= amount;
                        total_sold += amount;
                    }
                }
            }
            else if (method == 2) {
                int id, amount;
                printf("상품 ID 입력 : ");
                scanf("%d", &id);
                id -= 1;
                if (id < 0 || id >= n) {
                   
                    continue;
                }
                printf("판매수량 입력: ");
                scanf("%d", &amount);
                if (amount < 0) amount = 0;
                if (amount > stock[id]) {
                    total_sold += stock[id];
                    sold[id] += stock[id];
                    stock[id] = 0;
                }
                else {
                    sold[id] += amount;
                    stock[id] -= amount;
                    total_sold += amount;
                }
            }
            
        }
        else if (choice == 3) {  
            printf("\n[상품 현황]\n");
            for (int i = 0; i < n; i++) {
                if (stock[i] <= 2) {
                    printf("상품 ID %d : 재고 %d\n", i + 1, stock[i]);
                }
                else {
                    printf("상품 ID %d : 재고 %d\n", i + 1, stock[i]);
                }
            }
            float rate = total_input > 0 ? ((float)total_sold / total_input) * 100 : 0;
            printf("\n총 판매량 : %d (판매율 %.2f%%)\n", total_sold, rate);

            maxMinSales(sold, n);
        }
        else if (choice == 4) {
            printf("\n프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("※ 잘못된 메뉴 번호입니다.\n");
        }
    }
    return 0;
}

void maxMinSales(int* sold, int n) {
    int max = sold[0], min = sold[0];
    int max_id = 0, min_id = 0;

    for (int i = 1; i < n; i++) {
        if (sold[i] > max) {
            max = sold[i];
            max_id = i;
        }
        if (sold[i] < min) {
            min = sold[i];
            min_id = i;
        }
    }
    printf("가장 많이 판매된 상품 : ID %d, 판매량: %d\n", max_id + 1, max);
    printf("가장 적게 판매된 상품 : ID %d, 판매량: %d\n", min_id + 1, min);
}
