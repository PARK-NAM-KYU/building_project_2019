#include "basic.h"

int floor_logic(int floor) {
	int num = 6 - floor;
	int choice;
	while (1) {
		printf("���� �������ּ���(1~%d): ", num);
		scanf("%d", &choice);
		while (getchar() != '\n');
		if (choice > num || choice < 1) {
			printf("�ٽ� �Է����ּ���\n");

		}
		else break;
	}
	return choice;
}