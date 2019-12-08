#include "struct.h"
#include "Windows.h"
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

//현재 화면
void basic_view1(char * title) {
	int i;
	gotoxy(0, 0);
	printf("윗창입니다\n");
	printf("현재화면 : %s\n\n",title);
	for (i = 0; i < 50;i++)printf("★");
}
//플레이어 개인정보
void basic_view2(Player player) {
	int i;
	gotoxy(0, 26);
	for (i = 0; i < 50; i++)printf("★");
	printf("\n<플레이어의 정보>\n");
	printf("hp : %d\n",player.hp);
	if (player.equipment.weapon == 0)printf("무기 없음, ");
	else printf("무기 있음, ");
	if (player.equipment.potionList.effect == 0)printf("아이템 없음");
	else printf("현재 포션의 효과 : %d",player.equipment.potionList.effect);
}


/*
// 안전한 문자열 받는 함수
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
// 안전한 숫자 받는 함수
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
// 안전한 문자 받는 함수
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
