#include "basic.h"

void floor_view(int floor) {
	int i;
	int j = 0;
	char title[10];
	char title2[] = "��° ��";
	sprintf(title, "%d", floor);
	strcat(title, title2);
	basic_view1(title);
	
	for (i = 0; i < 6-floor; i++) {

		gotoxy(j, 11);

		printf("������������\n");
		printf("��       ���       ��\n");
		printf("��       ���       ��\n");
		printf("��     �����     ��\n");
		printf("��     �����     ��\n");
		printf("��       ���       ��\n");
		printf("��       ���       ��\n");
		printf("������������\n");

		j += 24;
	}
}