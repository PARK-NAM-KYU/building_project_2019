#include "basic.h"

void floor_view(int floor) {
	int i;
	int j = 0;
	char title[10];
	char title2[] = "��° ��";
	sprintf(title, "%d", floor);
	strcat(title, title2);
	basic_view1(title);

	for (i = 0; i < 6 - floor; i++) {

		gotoxy(j, 11);
		printf("���������");
		gotoxy(j, 12);
		printf("��    ���    ��");
		gotoxy(j, 13);
		printf("��    ���    ��");
		gotoxy(j, 14);
		printf("��  �����  ��");
		gotoxy(j, 15);
		printf("��  �����  ��");
		gotoxy(j, 16);
		printf("��    ���    ��");
		gotoxy(j, 17);
		printf("��    ���    ��");
		gotoxy(j, 18);
		printf("���������");

		j += 20;
	}
}