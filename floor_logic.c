#include "basic.h"

int floor_logic(int floor) {

	int num = 6 - floor;
	int choice;

	while (1) {
		gotoxy(30, 22);
		printf("���� �������ּ���(1~%d): ", num);
		scanf("%d", &choice);
		if (choice > num || choice < 1) {
			printf("\n�ٽ� �Է����ּ���");
			continue;
		}
		else break;
	}
	return choice;
}