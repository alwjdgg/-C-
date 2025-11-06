#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int id;          
    char name[30];   
    int price;      
    int stock;      
    int sold;        
    int inputTotal;  
    int revenue;   
} Product;

void inputProduct(Product* p);
void sellProduct(Product* p);
void showSingle(Product* p);
void showAll(Product* p, int count);
int findProduct(Product* p, int id);

int main() {
    Product p[MAX] = { 0 };
    int count = 0;
    int menu;

    printf("=== 쇼핑몰 재고 관리 프로그램 ===\n");

    while (1) {
        printf("\n원하는 메뉴를 선택하세요.\n");
        printf("(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료)\n> ");
        scanf("%d", &menu);

        if (menu == 1) {  
            printf("\n<< 입고메뉴 실행 >>\n");
            if (count >= MAX) {
                printf("※ 더 이상 상품을 등록할 수 없습니다.\n");
                continue;
            }

            int id;
            printf("상품 ID 입력(1~5): ");
            scanf("%d", &id);

            int idx = findProduct(p, id);
            if (idx == -1) { 
                p[count].id = id;
                inputProduct(&p[count]);
                count++;
            }
            else { 
                int add;
                printf("기존 상품입니다. 입고수량 입력: ");
                scanf("%d", &add);
                if (add < 0) add = 0;
                p[idx].stock += add;
                p[idx].inputTotal += add;
                printf("입고 완료! 현재 재고: %d개\n", p[idx].stock);
            }
        }

        else if (menu == 2) { 
            printf("\n<< 판매메뉴 실행 >>\n");
            int id;
            printf("상품 ID 입력: ");
            scanf("%d", &id);

            int idx = findProduct(p, id);
            if (idx == -1) printf("※ 해당 ID 상품이 없습니다.\n");
            else sellProduct(&p[idx]);
        }

        else if (menu == 3) {  
            printf("\n<< 개별현황 메뉴 실행 >>\n");
            int id;
            printf("상품 ID 입력: ");
            scanf("%d", &id);

            int idx = findProduct(p, id);
            if (idx == -1) printf("※ 해당 상품이 없습니다.\n");
            else showSingle(&p[idx]);
        }

        else if (menu == 4) {  
            printf("\n<< 전체현황 메뉴 실행 >>\n");
            if (count == 0) printf("등록된 상품이 없습니다.\n");
            else showAll(p, count);
        }

        else if (menu == 5) {
            printf("\n프로그램을 종료합니다.\n");
            break;
        }
        else printf("※ 잘못된 메뉴 번호입니다.\n");
    }

    return 0;
}


void inputProduct(Product* p) {
    printf("상품명: "); scanf("%s", p->name);
    printf("입고수량: "); scanf("%d", &p->stock);
    printf("판매가격: "); scanf("%d", &p->price);
    p->sold = 0;
    p->inputTotal = p->stock;
    p->revenue = 0;
    printf("상품 등록 완료!\n");
}

void sellProduct(Product* p) {
    int qty;
    printf("판매수량 입력: ");
    scanf("%d", &qty);

    if (qty <= 0) {
        printf("※ 판매수량은 1 이상이어야 합니다.\n");
        return;
    }
    if (qty > p->stock) {
        printf("※ 재고 부족! 현재 재고: %d개\n", p->stock);
        return;
    }

    p->stock -= qty;
    p->sold += qty;
    p->revenue += qty * p->price;

    printf("판매 완료! 남은 재고: %d개, 누적판매: %d개, 총매출액: %d원\n",
        p->stock, p->sold, p->revenue);
}

void showSingle(Product* p) {
    printf("\n[상품정보]\n");
    printf("상품ID: %d\n", p->id);
    printf("상품명: %s\n", p->name);
    printf("가격: %d원\n", p->price);
    printf("누적입고: %d개\n", p->inputTotal);
    printf("현재재고: %d개\n", p->stock);
    printf("판매량: %d개\n", p->sold);
    printf("총매출액: %d원\n", p->revenue);
    double rate = p->inputTotal > 0 ? (double)p->sold / p->inputTotal * 100 : 0;
    printf("판매율: %.1f%%\n", rate);
}

void showAll(Product* p, int count) {
    int totalSold = 0, totalRevenue = 0, totalInput = 0;

    printf("\n[전체상품 현황]\n");
    printf("%-5s %-10s %-8s %-8s %-8s %-8s %-8s\n",
        "ID", "상품명", "가격", "입고", "재고", "판매", "매출");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-10s %-8d %-8d %-8d %-8d %-8d\n",
            p[i].id, p[i].name, p[i].price, p[i].inputTotal, p[i].stock, p[i].sold, p[i].revenue);
        totalSold += p[i].sold;
        totalRevenue += p[i].revenue;
        totalInput += p[i].inputTotal;
    }

    double totalRate = totalInput > 0 ? (double)totalSold / totalInput * 100 : 0;

    printf("총 입고량: %d개, 총 판매량: %d개, 총 매출액: %d원, 전체 판매율: %.1f%%\n",
        totalInput, totalSold, totalRevenue, totalRate);
}

int findProduct(Product* p, int id) {
    for (int i = 0; i < MAX; i++)
        if (p[i].id == id) return i;
    return -1;
}
