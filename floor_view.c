#include "basic.h"
#include <string.h>

void floor_view(int floor) {
	char title[10];
	char title2[] = "번째 층";
	
	clean_view();
	sprintf(title, "%d", floor);
	strcat(title, title2);
	basic_view1(title);
	gotoxy(1, 5);
	printf("\n\n\n\n\n\n게임을 지속하려면 enter를 누르세요");
	getch();
	system("cls");
}