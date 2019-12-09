#include "basic.h"

#define GREEN 10
#define BLUE 11
#define RED 13

//벽돌깨기
// 랜덤이 안되는거랑 키입력 오류 좀 있는데 화요일 전까지 고쳐볼께요 ㅠㅠ..

typedef struct block {
	int click;
	int color;
}Block;

void game1_start();
Block make_block();
void show_block(Block);
void game1_view(Block[]);
void check_input(char, Block*);
void reblock(Block*[]);

void game1(Player* player, int* floor) {

	int t, i, gameTime;
	char ch;
	Block blocks[50];
	Block block;

	game1_start(); //게임 시작 화면
	for (i = 0; i < 50; i++) {
		blocks[i] = make_block(&blocks[i]);
		if (i == 49) blocks[i].click == 5; // 마지막은 5번 
	}

	t = (int)time(NULL);
	while (1) {
		game1_view(&blocks);

		if (kbhit()) {
			ch = getch();
			check_input(ch, &blocks[0]);
			if (blocks[0].click == 0) {
				reblock(blocks);
			}
		}
		if (blocks[0].click == 0) { // 부셨을때 
			if (blocks[1].click == -1) break; // 벽돌 다 부시면 break
		}
		gameTime = (int)time(NULL) - t;
		if (gameTime > 30) break; //30초면 time over
	}
	//게임 결과

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(50, 15);
	if (gameTime <= 30) {
		printf("WIn !! 걸린 시간 : %d초 \n", gameTime);
		Sleep(3000);
	}
	else {
		printf("Lose !!\n");
		Sleep(3000);
	}
}

void game1_start() {

	int t;
	clean_view();
	gotoxy(42, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("[ 벽 돌 깨 기 ]");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	gotoxy(42, 15);
	printf("제한시간 : 1분");
	gotoxy(37, 17);
	printf("벽돌을 모두 파괴하세요 !");
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

Block make_block() {
	int i;
	int temp;
	Block b;
	srand(time(NULL));

	//클릭횟수
	temp = (rand() % 2) + 1;
	b.click = temp;
	//벽돌색깔
	temp = rand() % 3;
	if (temp == 0) b.color = GREEN;
	if (temp == 1) b.color = BLUE;
	if (temp == 2) b.color = RED;

	return b;
}

void show_block(Block b) {
	int i;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), b.color);
	for (i = 0; i < 15; i++) {
		if (b.click == 1) printf("□");
		if (b.click == 2) printf("■");
	}
}

void game1_view(Block b[50]) {

	int i;
	int x = 20, y = 18;

	gotoxy(24, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
	printf("●");
	gotoxy(28, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
	printf("●");
	gotoxy(32, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	printf("●");

	for (i = 0; i < 5; i++) {
		gotoxy(x, y);
		show_block(b[i]);
		y--;
		gotoxy(x, y);
		show_block(b[i]);
		y -= 2;
	}
}

void check_input(char c, Block *b) {

	int temp;
	//일단 키를 asd로 했어욤
	if (c == 75) temp = GREEN;
	if (c == 72) temp = BLUE;
	if (c == 77) temp = RED;
	else temp = 0;

	if (temp == b->color) {
		b->click--;
	}
	else {
		gotoxy(10, 20);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("땡 !!");
		Sleep(1000);
		clean_view();
	}
}

void reblock(Block* b[50]) {

	int i;

	for (i = 0; i < 50; i++) {
		*b[i] = *b[i + 1];
		if (b[i + 1]->click == 5) {
			b[i + 1]->click = -1;
			break;
		}
	}
}
