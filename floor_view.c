#include "basic.h"

void floor_view(int floor) {
	int i;
	int j = 0;
	char title[10];
	char title2[] = "╣°┬░ ├■";
	sprintf(title, "%d", floor);
	strcat(title, title2);
	basic_view1(title);

	for (i = 0; i < 6 - floor; i++) {

		gotoxy(j, 11);
		printf("брбрбрбрбрбрбрбр");
		gotoxy(j, 12);
		printf("бр    брбр    бр");
		gotoxy(j, 13);
		printf("бр    брбр    бр");
		gotoxy(j, 14);
		printf("бр  брбрбрбр  бр");
		gotoxy(j, 15);
		printf("бр  брбрбрбр  бр");
		gotoxy(j, 16);
		printf("бр    брбр    бр");
		gotoxy(j, 17);
		printf("бр    брбр    бр");
		gotoxy(j, 18);
		printf("брбрбрбрбрбрбрбр");

		j += 20;
	}
}