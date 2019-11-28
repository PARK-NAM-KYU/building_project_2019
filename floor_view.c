#include "basic.h"

void floor_view(int floor) {
	clean_view();
	basic_view1("%d번째 층",floor);
	gotoxy(1, 5);
	printf("\n\n\n\n\n\n게임을 지속하려면 enter를 누르세요");
	getch();
}