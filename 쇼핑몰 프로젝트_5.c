#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void maxMinSales(int* sold, int n);

int main() {
    int input[100] = { 0 };
    int sold[100] = { 0 };
    int stock[100] = { 0 };
    int n = 5;
    int total_input = 0;
    int total_sold = 0;
    int choice;
    char productName[5][30];
    int nameEntered = 0;

    while (1) {
        printf("\n[���θ� ���� ���α׷�]\n");
        printf("> ���ϴ� �޴��� �����ϼ���.\n");
        printf("(1. �԰�, 2. �Ǹ�, 3. ��ǰ��Ȳ, 4. ��ǰ�� �Է�, 5. ����)\n");
        printf("�Է�: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int method;
            printf("\n�԰���� �Է� : ��ü ��ǰ(1), ���� ��ǰ(2)\n�Է� > ");
            scanf("%d", &method);

            if (method == 1) {
                printf("�� ��ǰ�� �԰������ ������� �Է��ϼ���:\n�Է� > ");
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
                printf("��ǰ ID �Է�: ");
                scanf("%d", &id);
                id -= 1;
                if (id < 0 || id >= n) {
                    printf("�߸��� ��ǰID�Դϴ�.\n");
                    continue;
                }
                printf("�԰���� �Է�: ");
                scanf("%d", &amount);
                if (amount < 0) amount = 0;
                input[id] += amount;
                stock[id] += amount;
                total_input += amount;
            }

        }
        else if (choice == 2) {
            int method;
            printf("\n�Ǹż��� �Է� : ��ü ��ǰ(1), ���� ��ǰ(2)\n�Է� > ");
            scanf("%d", &method);

            if (method == 1) {
                printf("�� ��ǰ�� �Ǹż����� ������� �Է��ϼ���:\n�Է� > ");
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
                printf("��ǰ ID �Է� : ");
                scanf("%d", &id);
                id -= 1;
                if (id < 0 || id >= n) {
                    printf("�߸��� ��ǰID�Դϴ�.\n");
                    continue;
                }
                printf("�Ǹż��� �Է�: ");
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
            printf("\n[��ǰ ��Ȳ]\n");
            printf("������ : ");
            for (int i = 0; i < n; i++) {
                printf("%d ", stock[i]);
            }
            printf("\n");

            printf("�� �Ǹŷ� : %d (�Ǹ��� %.2f%%)\n", total_sold,
                total_input > 0 ? ((float)total_sold / total_input) * 100 : 0);

            maxMinSales(sold, n);

            printf("\n��ǰ�� ��Ȳ:\n");
            for (int i = 0; i < n; i++) {
                printf("ID %d (%s) : ��� %d��\n", i + 1,
                    nameEntered ? productName[i] : "�̵��", stock[i]);
            }
        }
        else if (choice == 4) {
            printf("\n< ��ǰ�� �Է� �޴� ���� >\n");
            for (int i = 0; i < n; i++) {
                printf("��ǰ ID %d �̸� �Է�: ", i + 1);
                scanf("%s", productName[i]);
            }
            nameEntered = 1;
            printf("��ǰ���� ��� ��ϵǾ����ϴ�.\n");
        }
        else if (choice == 5) {
            printf("\n���α׷��� �����մϴ�.\n");
            break;
        }
        else {
            printf("�� �߸��� �޴� ��ȣ�Դϴ�.\n");
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
    printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ�: %d\n", max_id + 1, max);
    printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ�: %d\n", min_id + 1, min);
}
