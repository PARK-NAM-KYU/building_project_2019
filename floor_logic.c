#include "basic.h"

int floor_logic(int floor, Player *me) {

	int num = 6 - floor;
	int choice;
	int i;

	while (1) {
		floor_view(floor);
		gotoxy(30, 22);
		printf("���� �������ּ���(1~%d): ", num);
		scanf("%d", &choice);
		while (getchar() != '\n'); // �Է¹��ۿ��� ���� ���ֱ�
		if (choice > num || choice < 1) {
			system("cls");
			basic_view2(me);
			continue;
		}
		else break;
	}
	return choice;
}