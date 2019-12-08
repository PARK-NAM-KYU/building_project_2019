#pragma once
#include <stdio.h>

<<<<<<< Updated upstream
void basic_view1();//실제 화면구현 위쪽 기본 창
void basic_view2();//실제 화면구현 아래쪽 기본 창
void gotoxy(Position position);
=======
void basic_view1(char * title);//실제 화면구현 위쪽 기본 창
void basic_view2(Player* player);//실제 화면구현 아래쪽 기본 창
void clean_view();
>>>>>>> Stashed changes

char * intput_text();
int input_number();
char input_char();