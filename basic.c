#include "struct.h"
#define SIZE 100

void basic_view1() {}
void basic_view2() {}
void gotoxy(Position position) {}
// ������ ���ڿ� �޴� �Լ�
char* input_text(void)
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
int input_number() 
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