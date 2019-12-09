#include "basic.h"

int floor_logic(int floor) {
	int num = 6 - floor;
	int choice;
	while (1) {
		printf("방을 선택해주세요(1~%d): ", num);
		scanf("%d", &choice);
		while (getchar() != '\n');
		if (choice > num || choice < 1) {
			printf("다시 입력해주세요\n");

		}
		else break;
	}
	return choice;
}