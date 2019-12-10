#pragma once
#include "basic.h"

int quiz1();
int quiz2();
int quiz3();
int GetSpaceIdx(char[]);
int CompStr(char[], char[]);

void game1(Player* player, int* floor)
{
	int randomQuiz = 0;
	int result, temp;

	system("cls");
	basic_view1("C��� ����");
	basic_view2(player);
	gotoxy(0, 7);

	printf("�� �� ������ Ǫ�ðڽ��ϱ�? (1~3) ");
	while (1) {
		scanf("%d", &temp);
		if (temp >= 1 && temp <= 3) break;
		printf("1���� 3���� ���ڸ� �ٽ� �Է����ּ���.\n");
	}
	printf("\n");

	switch (temp)
	{
	case 1: result = quiz1(); break;
	case 2: result = quiz2(); break;
	case 3: result = quiz3(); break;
	}

	system("cls");
	basic_view1("C��� ����");
	basic_view2(player);
	gotoxy(48, 15);

	if (result) {
		printf("win");
		Sleep(2000);
		(*floor)++;
	}
	else {
		printf("lose!");
		Sleep(2000);
	}
	system("cls");
}

int quiz1() {

	char answer1[6] = "fopen";
	char answer2[7] = "fclose";
	char temp[20] = { 0 };
	printf("int main(void) { \n");
	printf("	FILE* fp1 = NULL;\n");
	printf("	fp1 = 1._______(\". / data.txt\", \"w\"); \n");
	printf("	fscanf(fp1, \"��������Ʈ\");\n");
	printf("	2._______(fp1); \n");
	printf("	return 0;\n");
	printf("}\n\n");

	printf("1���� �� �˸��� �ܾ�� ? ");
	scanf("%s", temp);

	printf("2���� �� �˸��� �ܾ�� ? ");
	scanf("%s", temp);

	if (CompStr(temp, answer2)) return 0;

	printf("������~");
	Sleep(2000);
	return 1;
}

int quiz2() {

	char answer1[7] = "double";
	char answer2[3] = "10";
	char temp[20] = { 0 };

	printf("�� �Ǽ�(8bytes)�� �޾Ƽ� � ���� �ϴ� add�Լ��� �ִ�.\n");
	printf("int main(void) { \n");
	printf("	int(*pf)(_____,_____);\n");
	printf("	double x = 3.14;\n");
	printf("	double y = 7.83;\n");
	printf("	double result = 0;\n");
	printf("	pf = add;\n");
	printf("	result = (*pf)(x, y);\n");
	printf("	printf(\"%%d\",result);\n");
	printf("	return 0;\n");
	printf("}\n\n");

	printf("��ĭ�� �� �˸��� �ܾ�� ? ");
	scanf("%s", temp);

	if (CompStr(temp, answer1)) return 0;

	printf("�ڵ� ������ ��µǴ� ���ڴ� ? ");
	scanf("%s", temp);
	if (CompStr(temp, answer2)) return 0;

	printf("������~");
	Sleep(2000);
	return 1;
}

int quiz3() {

	char answer[3] = "20";
	char temp[20] = { 0 };

	printf("�迭�� �޸� �����Ҵ��� �ϴ� �ڵ��Դϴ�.\n");
	printf("int main(void) { \n");
	printf("	int size = 5;\n");
	printf("	int *arr;\n\n");
	printf("	arr = (int*)malloc(sizeof(int)*size);\n");
	printf("	memset(arr,0x0,sizeof(int)*size);\n");
	printf("	printf(\"�迭�� �Ҵ�� ������ %%d\ bytes �Դϴ�.\",_msize(arr));\n");
	printf("	free(arr);\n");
	printf("	arr = NULL;\n");
	printf("	return 0;\n");
	printf("}\n\n");

	printf("��µ� ���� ? ");
	scanf("%s", temp);

	if (CompStr(temp, answer)) return 0;

	printf("������~");
	Sleep(2000);
	return 1;

}

int GetSpaceIdx(char str[]) {

	int len, i;

	len = strlen(str);

	for (i = 0;i < len;i++) {
		if (str[i] == ' ') return i;
	}
	return -1; //���鹮�ڰ� �������� ���� ���
}

int CompStr(char str1[], char str2[]) {

	int idx1 = GetSpaceIdx(str1);
	int idx2 = GetSpaceIdx(str2);

	if (idx1 != idx2) return 1;

	else return strcmp(str1, str2);
}
