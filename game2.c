#include "basic.h"

//두더지잡기
void randomXY(int*, int*, int*);
void game2_start();
void game2_view(int*);
void show_mole(char arr[][4], int*, int*);
void step1(char[][4], int*); //1단계
void step2(char[][4], int*); //2단계

void game2(Player* player, int* floor) {

	int score = 0;
	int i, j, t;
	int x, y;
	char mole[4][4] = {
		{'l','u','u','r'},
		{'s','e','e','s'},
		{'s',' ',' ','s'},
		{'s',' ',' ','s'}
	};//두더지 모양 (안잡히면 e 잡히면 d)

	game2_start();	//게임 소개 5초 + 5초 COUNT
	step1(mole, &score);
	step2(mole, &score);

	//게임 결과
	gotoxy(48, 15);
	if (score >= 3000) {
		printf("WIN!! SCORE: %d", score);
		//*floor++;
	}
	else {
		printf("LOSE!! SCORE: %d", score);
		//if (*floor != 1) *floor--;
	}
	Sleep(3000);
}
void randomXY(int *x, int *y, int *num) {
	srand(time(NULL));
	*x = 38 + 10 * (rand() % 3);
	*y = 6 * (rand() % 3 + 1);
	*num = 3 * (((*y) / 6) - 1) + (((*x) - 28) / 10);
}

void game2_start() {

	int t;
	clean_view();
	gotoxy(40, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("[ 두 더 지 잡 기 ]");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	gotoxy(38, 15);
	printf("승리조건 : 3000점 이상");
	gotoxy(43, 16);
	printf("┌────────┐");
	gotoxy(43, 17);
	printf("│ ①②③ │");
	gotoxy(43, 18);
	printf("│ ④⑤⑥ │");
	gotoxy(43, 19);
	printf("│ ⑦⑧⑨ │");
	gotoxy(43, 20);
	printf("└────────┘");
	gotoxy(32, 21);
	printf("숫자를 입력해서 두더지를 잡으세요 !");
	Sleep(5000);

	clean_view();
	//5초 뒤에 시작
	for (t = 5; t > 0; t--) {
		gotoxy(49, 15);
		printf("%d", t);
		Sleep(1000);
	}
	clean_view();
}

void game2_view(int *score) {

	int i;
	gotoxy(34, 5);
	for (i = 0; i < 34; i++) {
		if (i == 0) printf("┌");
		else if (i == 33) printf("┐");
		else printf("─");
	}
	for (i = 0; i < 18; i++) {
		gotoxy(34, 6 + i);
		printf("│");
		gotoxy(67, 6 + i);
		printf("│");
	}
	gotoxy(34, 24);
	for (i = 0; i < 34; i++) {
		if (i == 0) printf("└");
		else if (i == 33) printf("┘");
		else printf("─");
	}
	gotoxy(20, 20);
	printf("SCORE : %d", *score);
}

void show_mole(char arr[][4], int *x, int *y) {

	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			gotoxy(*x + 2 * j, *y + i);
			if (arr[i][j] == 'u') printf("─");
			else if (arr[i][j] == 's') printf("│");
			else if (arr[i][j] == 'e') printf("ⓞ");
			else if (arr[i][j] == 'd') printf("ⓧ");
			else if (arr[i][j] == 'l') printf("┌");
			else if (arr[i][j] == 'r') printf("┐");
		}
	}
}

void step1(char arr[][4], int *score) {
	int i, t, x, y, num;
	char ch;

	for (i = 0; i < 10; i++) {//1단계 3초
		game2_view(score);
		randomXY(&x, &y, &num);
		show_mole(arr, &x, &y);
		t = (int)time(NULL);
		while ((int)time(NULL) < t + 3) {
			if (kbhit()) {
				ch = getch();
				if ((ch - '0') == num) {
					arr[1][1] = 'd';
					arr[1][2] = 'd';
					*score += 200;
					show_mole(arr, &x, &y);
					Sleep(300);
				}
			}
		}
		arr[1][1] = 'e';
		arr[1][2] = 'e';
		clean_view();
	}
}
void step2(char arr[][4], int *score) {
	int i, t, x, y, num;
	char ch;

	for (i = 0; i < 15; i++) {	//2단계 2초
		game2_view(score);
		randomXY(&x, &y, &num);
		show_mole(arr, &x, &y);
		t = (int)time(NULL);
		while ((int)time(NULL) < t + 2) {
			if (kbhit()) {
				ch = getch();
				if ((ch - '0') == num) {
					arr[1][1] = 'd';
					arr[1][2] = 'd';
					*score += 200;
					show_mole(arr, &x, &y);
					Sleep(300);
				}
			}
		}
		arr[1][1] = 'e';
		arr[1][2] = 'e';
		clean_view();
	}
}