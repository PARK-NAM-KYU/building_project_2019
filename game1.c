#include "basic.h"

#define GREEN 10
#define BLUE 11
#define RED 13

//��������
// ������ �ȵǴ°Ŷ� Ű�Է� ���� �� �ִµ� ȭ���� ������ ���ĺ����� �Ф�..

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

	game1_start(); //���� ���� ȭ��
	for (i = 0; i < 50; i++) {
		blocks[i] = make_block(&blocks[i]);
		if (i == 49) blocks[i].click == 5; // �������� 5�� 
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
		if (blocks[0].click == 0) { // �μ����� 
			if (blocks[1].click == -1) break; // ���� �� �νø� break
		}
		gameTime = (int)time(NULL) - t;
		if (gameTime > 30) break; //30�ʸ� time over
	}
	//���� ���

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(50, 15);
	if (gameTime <= 30) {
		printf("WIn !! �ɸ� �ð� : %d�� \n", gameTime);
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
	printf("[ �� �� �� �� ]");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	gotoxy(42, 15);
	printf("���ѽð� : 1��");
	gotoxy(37, 17);
	printf("������ ��� �ı��ϼ��� !");
	Sleep(5000);

	clean_view();
	//5�� �ڿ� ����
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

	//Ŭ��Ƚ��
	temp = (rand() % 2) + 1;
	b.click = temp;
	//��������
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
		if (b.click == 1) printf("��");
		if (b.click == 2) printf("��");
	}
}

void game1_view(Block b[50]) {

	int i;
	int x = 20, y = 18;

	gotoxy(24, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
	printf("��");
	gotoxy(28, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
	printf("��");
	gotoxy(32, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	printf("��");

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
	//�ϴ� Ű�� asd�� �߾��
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
		printf("�� !!");
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
