#include "basic.h"

void floor_view(int floor) {
	clean_view();
	basic_view1("%d��° ��",floor);
	gotoxy(1, 5);
	printf("\n\n\n\n\n\n������ �����Ϸ��� enter�� ��������");
	getch();
}