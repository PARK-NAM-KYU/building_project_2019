#include "basic.h"
#define YP 7
#define KEY 224
#define LEFT 75
#define COLUMN 10
#define ROW 5
#define START 4
int get_key() {
	int k;
	while (1) {
		if (_kbhit()) {
			k = _getch();
			if (k == KEY) {
				k = _getch();
				return k;
			}
		}
	}
}

void clear_person() {
	gotoxy(10, 7 + START);
	printf("                                                                 ");
	gotoxy(10, 8 + START);
	printf("                                                                 ");
	gotoxy(10, 9 + START);
	printf("                                                                 ");
}
void print_person(int x) {
	gotoxy(x, YP + START);
	printf(" o\n");
	gotoxy(x, YP + 1 + START);
	printf("/l＼\n");
	gotoxy(x, YP + 2 + START);
	printf("/ ＼");
}
void print_building(int building[][5]) {
	int i, j;
	gotoxy(0, 0 + START);
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 5; j++) {
			if (building[i][j] > 0) {
				printf("■");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
}
void set_floor(int building[][5], int floor[5]) {
	int i;
	for (i = 0; i < 5; i++) {
		building[0][i] = floor[i];
	}
}
int collision_down2(int blocks[][ROW]) {		//블록 밑에 블록이 있으면 충돌
	int i, j;
	for (i = 0; i < COLUMN; i++) {
		for (j = 0; j < ROW; j++) {
			if (blocks[i][j] == 1) {
				blocks[i][j] = 2;
			}
		}
	}

}
int floor_down(int blocks[][ROW]) {		//블록을 한칸씩 내리면서 충돌하면 멈춘다.
	int i, j;
	for (i = COLUMN - 1; i >= 0; i--) {				//블록의 아래쪽 부터 충돌하는지 검사한다.
		for (j = 0; j < ROW; j++) {

			if ((blocks[i][j] == 1) && ((i == COLUMN - 1) || (blocks[i + 1][j] == 2))) {	//충돌한다.
				collision_down2(blocks);
				return 0;
			}
		}
	}
	for (i = COLUMN - 1; i >= 0; i--) {				//충돌하지 않았다. 블럭을 한칸씩 밑으로 내린다.
		for (j = 0; j < ROW; j++) {
			if (blocks[i][j] == 1) {
				blocks[i + 1][j] = 1;
				blocks[i][j] = 0;
			}
		}
	}
	return 1;

}

void building_view() {
	basic_view1("빌딩 생성중인화면");
	int key;
	int x = 70;
	int i, next;
	int building[10][5] = { 0 };
	int floor[5][5] = {
		{1,1,1,1,1}, {1,1,1,1,0}, {1,1,1,0,0}, {1,1,0,0,0},{1,0,0,0,0}
	};
	print_person(x);

	for (i = 0; i < 5; i++) {
		set_floor(building, floor[i]);
		next = 1;

		while (next) {
			print_building(building);
			next = floor_down(building);
			Sleep(20);

		}
	}
	gotoxy(45, 3 + START);
	printf("KONKUK BUILDING");
	gotoxy(0, 16 + START);
	printf("방향키를 눌러 빌딩에 들어가십시오");
	while (1) {
		clear_person();
		print_person(x);
		key = get_key();
		if (key == LEFT) {
			x = x - 5;
		}
		if (x < 13) {
			system("cls");
			return 0;
		}
	}

	
}