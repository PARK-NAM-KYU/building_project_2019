#include "basic.h"

void floor_view(int floor) {
	clean_view();
	basic_view1("%d��° ��", floor);
	gotoxy(1, 5);
	printf("\n\n\n\n\n\n������ �����Ϸ��� enter�� ��������");
	int i;
	int j = 1;

	for (i = 0; i < floor; i++) {

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
	getch();
}