#pragma once
#include <stdio.h>

<<<<<<< Updated upstream
void basic_view1();//���� ȭ�鱸�� ���� �⺻ â
void basic_view2();//���� ȭ�鱸�� �Ʒ��� �⺻ â
void gotoxy(Position position);
=======
void basic_view1(char * title);//���� ȭ�鱸�� ���� �⺻ â
void basic_view2(Player* player);//���� ȭ�鱸�� �Ʒ��� �⺻ â
void clean_view();
>>>>>>> Stashed changes

char * intput_text();
int input_number();
char input_char();