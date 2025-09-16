#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int n;

    printf("상품 개수를 입력하세요: ");
    scanf("%d", &n);

    int input[100];     
    int sold[100];     
    int stock[100];     


    printf("상품별 입고 수량을 입력하세요:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    
    printf("상품별 판매 수량을 입력하세요:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sold[i]);
    }

    
    for (int i = 0; i < n; i++) {
        stock[i] = input[i] - sold[i];
    }

   
    int id;
    printf("ID를 입력하세요: ");
    scanf("%d", &id);

    
    
    printf("%d\n", stock[id - 1]);

    for (int i = 0; i < n; i++) {
        printf("%d", stock[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}