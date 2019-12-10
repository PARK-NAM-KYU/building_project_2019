#include "struct.h"
#include "windows.h"

#define SIZE 100

void setcursortype()
{
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}


void gotoxy(int x, int y) {
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Potion * addPotion(int eff) {
	Potion * p = (Potion *)malloc(sizeof(Potion));
	memset(p, 0x0, sizeof(Potion));
	p->effect = eff;
	return p;
}
int cnt_potion(Potion * potion) {
	int cnt = 1;
	Potion * current = potion;
	while (current->link != NULL) {
		cnt++;
		current = current->link;
	}
	return cnt;
}
//���� ȭ��
void basic_view1(char * title) {
	int i;
	gotoxy(0, 0);
	printf("��â�Դϴ�\n");
	printf("����ȭ�� : %s\n\n",title);
	for (i = 0; i < 50;i++)printf("��");
}
//�÷��̾� ��������
void basic_view2(Player* player) {
	int i;
	gotoxy(0, 26);
	for (i = 0; i < 50; i++)printf("��");
	printf("\n<�÷��̾��� ����>\n");
	printf("hp : %d\n", player->hp);
	if (player->potionList->effect == 0)printf("������ ����");
	else {
		printf("������ ���� ���� : %d    ", cnt_potion(player->potionList));
		printf("���� ������ ȿ�� : %d", player->potionList->effect);
	}
}
void clean_view()
{
	int i, j;

	for (i = 0; i < 50; i++)
	{
		gotoxy(0, 100);
		for (j = 0; j < 100; j++)
			printf(" ");
	}
}

/*
// ������ ���ڿ� �޴� �Լ�
char* input_text()
{
	char c;
	int i = 0;
	char* text = (char*)malloc(sizeof(char) * SIZE);
	while (1)
	{
		scanf("%c", &c);
		if (c == '\n') break;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			text[i] = c;
			i++;
		}
		text[i] = '\0';
	}
	return text;
}
// ������ ���� �޴� �Լ�
char* input_number()
{
	char* num = (int*)malloc(sizeof(int) * SIZE);
	char c;
	int i = 0;
	while (1) {
		scanf("%c", &c);
		if (c == '\n') break;
		if ((c - '0' >= 0) && (c - '0' <= 9)) {
			num[i] = c;
			i++;
		}
	}
	num[i] = '\0';
	return num;
}
// ������ ���� �޴� �Լ�
char input_char()
{
	char c;
	int i = 0;
	while (1)
	{
		scanf("%c", &c);
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			return c;
		}
		if (c == '\n') break;
	}
}
*/
