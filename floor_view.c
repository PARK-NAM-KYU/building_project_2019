#include "basic.h"
#include <string.h>

void floor_view(int floor) {
	char title[10];
	char title2[] = "��° ��";
	
	sprintf(title, "%d", floor);
	strcat(title, title2);
	basic_view1(title);
	gotoxy(1, 5);
	printf("\n\n\n\n\n\n ���� �����ϼ���(0~%d) : ", 5-floor);
}