#include "basic.h"

#define COLUMN 15
#define ROW 10
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define KEY 224

int show_blocks(char blocks[][ROW]);			//쌓인 블록들 보이기
int set_block(char blocks[][ROW], char block[][4]);// 새로운 블록 나타내기
int show_nowBlock(char block[][4]);			//새로운 블록 보여주기
int proceed_game(char blocks[][ROW]);		//블록을 내리거나 충돌 감지하기
int collision_down(char blocks[][ROW]);		//밑이 1일때 모든 2를 1로 바꿈
int detect_result(char blocks[][ROW]);// 패배시 1을 리턴

int move_block(char blocks[][ROW]);
int move_left(char blocks[][ROW]);
int move_right(char blocks[][ROW]);
int bomb(char blocks[][ROW]);
//int get_key();
void game4(Player* player, int* floor) {
	system("cls");
	basic_view1("테트리스 게임");
	basic_view2(&player);
	gotoxy(0, 4);
	int result = game4_view();
	if (result == 1)
		(*floor)++;
	system("cls");
}
int game4_view() {
	char blocks[COLUMN][ROW] = { 0 };		//1은 고정된 블록, 2는 현재 움직이는 블록을 나타낸다.
	//int i, j; //테스트용
	char block[7][4][4] = {
		{ {0, 0, 0, 0}, { 0,0,0,0 }, { 0,0,2,2 }, { 0,0,2,2 } },// O미노
		{ {0, 0, 0, 0}, { 0,0,0,0 }, { 0,0,0,2 }, { 0,2,2,2 } },// L미노
		{ {0, 0, 0, 0}, { 0,0,0,0 }, { 0,0,2,2 }, { 0,2,2,0 } },// S미노
		{ {0, 0, 0, 0}, { 0,0,0,0 }, { 0,2,2,0 }, { 0,0,2,2 } },// Z미노
		{ {0, 0, 0, 0}, { 0,0,0,0 }, { 0,2,0,0 }, { 0,2,2,2 } },// J미노
		{ {0, 0, 0, 2}, { 0,0,0,2 }, { 0,0,0,2 }, { 0,0,0,2 } },// I미노
		{ {0, 0, 0, 0}, { 0,0,0,0 }, { 0,0,2,0 }, { 0,2,2,2 } } // T미노
	};
	int next = 1;
	int result = 0;
	int win = 0;
	int next_block;
	srand((unsigned)time(NULL));
	while (1) {
		next_block = rand() % 7;
		set_block(blocks, &block[next_block]);
		next = 1;
		while (next) {
			show_blocks(blocks);
			move_block(blocks);
			next = proceed_game(blocks);
			win = bomb(blocks);
			result = detect_result(blocks);

			if (result) {
				return 0;
			}
			else if (win) {
				return 1;
			}


		}


	}
}

int show_blocks(char blocks[][ROW]) {		//블럭들을 보여준다 메인게임화면
	int i, j;
	for (i = 0; i < COLUMN; i++) {
		for (j = 0; j < ROW; j++) {
			if (blocks[i][j])
				printf("■");
			else
				printf("□");
		}
		printf("\n");
	}
	gotoxy(0, 0 + 4);
}
int show_nowBlock(char block[][4]) {		//해당 블럭 모양을 모여준다.
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (block[i][j])
				printf("■");
			else
				printf("  ");
		}
		printf("\n");
	}
}
int set_block(char blocks[][ROW], char block[][4]) {	//새로운 블록이 나타나게 한다
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			blocks[i][3 + j] = block[i][j];
		}
	}
}
int collision_down(char blocks[][ROW]) {		//블록 밑에 블록이 있으면 충돌
	int i, j;
	for (i = 0; i < COLUMN; i++) {
		for (j = 0; j < ROW; j++) {
			if (blocks[i][j] == 2) {
				blocks[i][j] = 1;
			}
		}
	}

}
int proceed_game(char blocks[][ROW]) {		//블록을 한칸씩 내리면서 충돌하면 멈춘다.
	int i, j;
	for (i = COLUMN - 1; i >= 0; i--) {				//블록의 아래쪽 부터 충돌하는지 검사한다.
		for (j = 0; j < ROW; j++) {

			if ((blocks[i][j] == 2) && ((i == COLUMN - 1) || (blocks[i + 1][j] == 1))) {	//충돌한다.
				collision_down(blocks);
				return 0;
			}
		}
	}
	for (i = COLUMN - 1; i >= 0; i--) {				//충돌하지 않았다. 블럭을 한칸씩 밑으로 내린다.
		for (j = 0; j < ROW; j++) {
			if (blocks[i][j] == 2) {
				blocks[i + 1][j] = 2;
				blocks[i][j] = 0;
			}
		}
	}
	return 1;

}
int detect_result(char blocks[][ROW]) {		//천장에 블록이 닿아 패배함을 탐지
	int i;
	for (i = 0; i < COLUMN; i++) {
		if (blocks[2][i] == 1) {
			return 1;
		}
	}
	return 0;
}
/*void gotoxy(int x, int y) {		//화면이 깜빡거리지 않도록 커서이동을 통해 화면을 다시 쓰기위함
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}*/
///////////블럭을 움직이기//////////////
int move_left(char blocks[][ROW]) {
	int i, j;
	for (i = 0; i < COLUMN; i++) {
		if (blocks[i][0] == 2) {	//먼저 블록이 가장 왼쪽에 있다면 왼쪽으로 움직이지 못하도록 한다
			return 0;
		}
	}


	for (i = 0; i < COLUMN; i++) {
		for (j = 0; j < ROW - 1; j++) {	 //가장 왼쪽엔 블록이 없으므로 0번쨰 열을 제외하고 왼쪽에 블록이 있는지 검사한다.
			if ((blocks[i][j] == 1) && (blocks[i][j + 1] == 2)) {
				return 0;
			}
		}
	}
	for (i = 0; i < COLUMN; i++) {		//블록을 이동시킴	
		for (j = 1; j < ROW; j++) {
			if (blocks[i][j] == 2) {
				blocks[i][j - 1] = 2;
				blocks[i][j] = 0;
			}
		}
	}
	return 0;




}
int move_right(char blocks[][ROW]) {
	int i, j;
	for (i = 0; i < COLUMN; i++) {
		if (blocks[i][ROW - 1] == 2) {
			return 0;
		}
	}
	for (i = 0; i < COLUMN; i++) {
		for (j = ROW - 1; j > 0; j--) {			//오른쪽부터 검사한다.
			if (blocks[i][j] == 2 && blocks[i][j - 1] == 1) {
				return 0;
			}
		}
	}
	for (i = 0; i < COLUMN; i++) {
		for (j = ROW - 1; j >= 0; j--) {
			if (blocks[i][j] == 2) {
				blocks[i][j + 1] = 2;
				blocks[i][j] = 0;
			}

		}
	}

}


int move_block(char blocks[][ROW]) {	//키보드를 입력받아 아래,왼쪽,오른쪽,회전을 정함
	int key;
	unsigned int start_time = time(NULL);
	unsigned int present_time = start_time;

	while ((present_time - start_time) < 1) {
		if (kbhit()) {
			key = getch();
			if (key == KEY) {
				key = getch();
				if (key == RIGHT) {
					move_right(blocks);
				}
				else if (key == LEFT) {
					move_left(blocks);
				}
				else if (key == UP) {
					return 0; //회전 미구현
				}
				else if (key == DOWN) {
					return 0;
				}
				show_blocks(blocks);
			}
		}
		present_time = time(NULL);
	}
}
int bomb(char blocks[][ROW]) {
	int line = 0;
	int i, j;
	int n, m;
	for (i = 0; i < COLUMN; i++) {
		for (j = 0; j < ROW; j++) {
			if (blocks[i][j] == 1) {
				line++;
			}

		}
		if (line >= 10) {
			gotoxy(0, i + 4);
			for (m = 0; m < ROW; m++) {
				blocks[i][m] = 0;
				printf("※");


			}
			gotoxy(0, 0 + 4);
			Sleep(1000);
			return 1;
			/*							1번만 성공해도 클리어로 설정하므로 더이상진행하지 않는다.
			for (n = i - 1; n > 0; n--) {
				for (m = 0; m < ROW; m++) {

				}
			}*/
		}
		line = 0;
	}
	return 0;
}
/*
int get_key() {
	int k;

	if (_kbhit()) {
		k = _getch();
		if (k == KEY) {
			k = _getch();
			return k;

		}
	}
	return 0;
}*/
