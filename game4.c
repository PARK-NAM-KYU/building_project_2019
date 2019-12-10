#include "basic.h"

#define COLUMN 15
#define ROW 10
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define KEY 224

int show_blocks(char blocks[][ROW]);			//���� ��ϵ� ���̱�
int set_block(char blocks[][ROW], char block[][4]);// ���ο� ��� ��Ÿ����
int show_nowBlock(char block[][4]);			//���ο� ��� �����ֱ�
int proceed_game(char blocks[][ROW]);		//����� �����ų� �浹 �����ϱ�
int collision_down(char blocks[][ROW]);		//���� 1�϶� ��� 2�� 1�� �ٲ�
int detect_result(char blocks[][ROW]);// �й�� 1�� ����

int move_block(char blocks[][ROW]);
int move_left(char blocks[][ROW]);
int move_right(char blocks[][ROW]);
int bomb(char blocks[][ROW]);
//int get_key();
void game4(Player* player, int* floor) {
	system("cls");
	basic_view1("��Ʈ���� ����");
	basic_view2(&player);
	gotoxy(0, 4);
	int result = game4_view();
	if (result == 1)
		(*floor)++;
	system("cls");
}
int game4_view() {
	char blocks[COLUMN][ROW] = { 0 };		//1�� ������ ���, 2�� ���� �����̴� ����� ��Ÿ����.
	//int i, j; //�׽�Ʈ��
	char block[7][4][4] = {
		{ {0, 0, 0, 0}, { 0,0,0,0 }, { 0,0,2,2 }, { 0,0,2,2 } },// O�̳�
		{ {0, 0, 0, 0}, { 0,0,0,0 }, { 0,0,0,2 }, { 0,2,2,2 } },// L�̳�
		{ {0, 0, 0, 0}, { 0,0,0,0 }, { 0,0,2,2 }, { 0,2,2,0 } },// S�̳�
		{ {0, 0, 0, 0}, { 0,0,0,0 }, { 0,2,2,0 }, { 0,0,2,2 } },// Z�̳�
		{ {0, 0, 0, 0}, { 0,0,0,0 }, { 0,2,0,0 }, { 0,2,2,2 } },// J�̳�
		{ {0, 0, 0, 2}, { 0,0,0,2 }, { 0,0,0,2 }, { 0,0,0,2 } },// I�̳�
		{ {0, 0, 0, 0}, { 0,0,0,0 }, { 0,0,2,0 }, { 0,2,2,2 } } // T�̳�
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

int show_blocks(char blocks[][ROW]) {		//������ �����ش� ���ΰ���ȭ��
	int i, j;
	for (i = 0; i < COLUMN; i++) {
		for (j = 0; j < ROW; j++) {
			if (blocks[i][j])
				printf("��");
			else
				printf("��");
		}
		printf("\n");
	}
	gotoxy(0, 0 + 4);
}
int show_nowBlock(char block[][4]) {		//�ش� �� ����� ���ش�.
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (block[i][j])
				printf("��");
			else
				printf("  ");
		}
		printf("\n");
	}
}
int set_block(char blocks[][ROW], char block[][4]) {	//���ο� ����� ��Ÿ���� �Ѵ�
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			blocks[i][3 + j] = block[i][j];
		}
	}
}
int collision_down(char blocks[][ROW]) {		//��� �ؿ� ����� ������ �浹
	int i, j;
	for (i = 0; i < COLUMN; i++) {
		for (j = 0; j < ROW; j++) {
			if (blocks[i][j] == 2) {
				blocks[i][j] = 1;
			}
		}
	}

}
int proceed_game(char blocks[][ROW]) {		//����� ��ĭ�� �����鼭 �浹�ϸ� �����.
	int i, j;
	for (i = COLUMN - 1; i >= 0; i--) {				//����� �Ʒ��� ���� �浹�ϴ��� �˻��Ѵ�.
		for (j = 0; j < ROW; j++) {

			if ((blocks[i][j] == 2) && ((i == COLUMN - 1) || (blocks[i + 1][j] == 1))) {	//�浹�Ѵ�.
				collision_down(blocks);
				return 0;
			}
		}
	}
	for (i = COLUMN - 1; i >= 0; i--) {				//�浹���� �ʾҴ�. ���� ��ĭ�� ������ ������.
		for (j = 0; j < ROW; j++) {
			if (blocks[i][j] == 2) {
				blocks[i + 1][j] = 2;
				blocks[i][j] = 0;
			}
		}
	}
	return 1;

}
int detect_result(char blocks[][ROW]) {		//õ�忡 ����� ��� �й����� Ž��
	int i;
	for (i = 0; i < COLUMN; i++) {
		if (blocks[2][i] == 1) {
			return 1;
		}
	}
	return 0;
}
/*void gotoxy(int x, int y) {		//ȭ���� �����Ÿ��� �ʵ��� Ŀ���̵��� ���� ȭ���� �ٽ� ��������
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}*/
///////////���� �����̱�//////////////
int move_left(char blocks[][ROW]) {
	int i, j;
	for (i = 0; i < COLUMN; i++) {
		if (blocks[i][0] == 2) {	//���� ����� ���� ���ʿ� �ִٸ� �������� �������� ���ϵ��� �Ѵ�
			return 0;
		}
	}


	for (i = 0; i < COLUMN; i++) {
		for (j = 0; j < ROW - 1; j++) {	 //���� ���ʿ� ����� �����Ƿ� 0���� ���� �����ϰ� ���ʿ� ����� �ִ��� �˻��Ѵ�.
			if ((blocks[i][j] == 1) && (blocks[i][j + 1] == 2)) {
				return 0;
			}
		}
	}
	for (i = 0; i < COLUMN; i++) {		//����� �̵���Ŵ	
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
		for (j = ROW - 1; j > 0; j--) {			//�����ʺ��� �˻��Ѵ�.
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


int move_block(char blocks[][ROW]) {	//Ű���带 �Է¹޾� �Ʒ�,����,������,ȸ���� ����
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
					return 0; //ȸ�� �̱���
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
				printf("��");


			}
			gotoxy(0, 0 + 4);
			Sleep(1000);
			return 1;
			/*							1���� �����ص� Ŭ����� �����ϹǷ� ���̻��������� �ʴ´�.
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
