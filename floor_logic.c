#include "basic.h"

int floor_logic(int floor) {

	int num = 6 - floor;
	int choice;

	while (1) {
		gotoxy(30, 22);
		printf("방을 선택해주세요(1~%d): ", num);
		scanf("%d", &choice);
		if (choice > num || choice < 1) {
			printf("\n다시 입력해주세요");
			continue;
		}
		else break;
	}
	return choice;
}