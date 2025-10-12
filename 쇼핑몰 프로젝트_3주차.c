#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Maxminsales(int* sold, int n);
void Stock(int* stock, int n);
int main() {
	int n;

	printf("상품의 개수(종류) 입력:");
	scanf("%d", &n);

	int input[100];
	int sold[100];
	int stock[100];
	int total_input = 0;
	int total_sold = 0;
	

	printf("상품 별 입고 수량 입력:");
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
		total_input += input[i];
	}
	printf("상품 별 판매 수량 입력:");
	for (int i = 0; i < n; i++) {
		scanf("%d", &sold[i]);
		total_sold += sold[i];
	}
	printf("재고 수량:");
	for (int i = 0; i < n; i++) {
		stock[i]=input[i] - sold[i];
		printf("%d\t", stock[i]);
	}
	float rate = ((float)total_sold / total_input) * 100;
	printf("총 판매량:%d(판매율 %.2f)\n", total_sold, rate);
	Maxminsales(sold, n);
	Stock(stock, n);
	return 0;
}
void Maxminsales(int* sold, int n) {
	int max = *sold;
	int min = *sold;
	int max_id = 0, min_id = 0;
	for (int i = 0; i < n; i++) {
		if (*(sold + i) > max) {
			max = *(sold + i);
			max_id = i;
		}
		if (*(sold + i) < min) {
			min = *(sold + i);
			min_id = i;
		}
	}
	printf("가장 많이 판매된 상품:ID %d, 판매량 %d\n", max_id, max);
	printf("가장 적게 판매된 상품:ID %d, 판매량 %d\n", min_id, min);

}
void Stock(int* stock, int n) {
	for (int i = 0; i < n; i++) {
		if (*(stock + i) <= 2) {
			printf("상품 ID %d: 재고부족(%d)\n", i, *(stock + i));
		}
	}
}
