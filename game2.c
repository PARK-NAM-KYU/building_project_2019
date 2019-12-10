#include "basic.h"

//�δ������
void randomXY(int*, int*, int*);
void game2_start();
void game2_view(int*);
void show_mole(char arr[][4], int*, int*);
void step1(char[][4], int*); //1�ܰ�
void step2(char[][4], int*); //2�ܰ�

void game2(Player* player, int* floor) {

	int score = 0;
	int i, j, t;
	int x, y;
	char mole[4][4] = {
		{'l','u','u','r'},
		{'s','e','e','s'},
		{'s',' ',' ','s'},
		{'s',' ',' ','s'}
	};//�δ��� ��� (�������� e ������ d)

	game2_start();	//���� �Ұ� 5�� + 5�� COUNT
	step1(mole, &score);
	step2(mole, &score);

	//���� ���
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
	printf("[ �� �� �� �� �� ]");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	gotoxy(38, 15);
	printf("�¸����� : 3000�� �̻�");
	gotoxy(43, 16);
	printf("��������������������");
	gotoxy(43, 17);
	printf("�� ���� ��");
	gotoxy(43, 18);
	printf("�� ���� ��");
	gotoxy(43, 19);
	printf("�� ���� ��");
	gotoxy(43, 20);
	printf("��������������������");
	gotoxy(32, 21);
	printf("���ڸ� �Է��ؼ� �δ����� �������� !");
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

void game2_view(int *score) {

	int i;
	gotoxy(34, 5);
	for (i = 0; i < 34; i++) {
		if (i == 0) printf("��");
		else if (i == 33) printf("��");
		else printf("��");
	}
	for (i = 0; i < 18; i++) {
		gotoxy(34, 6 + i);
		printf("��");
		gotoxy(67, 6 + i);
		printf("��");
	}
	gotoxy(34, 24);
	for (i = 0; i < 34; i++) {
		if (i == 0) printf("��");
		else if (i == 33) printf("��");
		else printf("��");
	}
	gotoxy(20, 20);
	printf("SCORE : %d", *score);
}

void show_mole(char arr[][4], int *x, int *y) {

	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			gotoxy(*x + 2 * j, *y + i);
			if (arr[i][j] == 'u') printf("��");
			else if (arr[i][j] == 's') printf("��");
			else if (arr[i][j] == 'e') printf("��");
			else if (arr[i][j] == 'd') printf("��");
			else if (arr[i][j] == 'l') printf("��");
			else if (arr[i][j] == 'r') printf("��");
		}
	}
}

void step1(char arr[][4], int *score) {
	int i, t, x, y, num;
	char ch;

	for (i = 0; i < 10; i++) {//1�ܰ� 3��
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

	for (i = 0; i < 15; i++) {	//2�ܰ� 2��
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