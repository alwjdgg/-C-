#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int n;

    printf("��ǰ ������ �Է��ϼ���: ");
    scanf("%d", &n);

    int input[100];     
    int sold[100];     
    int stock[100];     


    printf("��ǰ�� �԰� ������ �Է��ϼ���:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    
    printf("��ǰ�� �Ǹ� ������ �Է��ϼ���:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sold[i]);
    }

    
    for (int i = 0; i < n; i++) {
        stock[i] = input[i] - sold[i];
    }

   
    int id;
    printf("ID�� �Է��ϼ���: ");
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