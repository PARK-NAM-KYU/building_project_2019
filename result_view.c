#include "basic.h"

void result_view() {
	clean_view();
	basic_view1("마지막 화면");
	gotoxy(1, 5);
	printf("\n\n\n\n\n\n게임을 지속하려면 enter를 누르세요");
	getch();
	system("cls");
}