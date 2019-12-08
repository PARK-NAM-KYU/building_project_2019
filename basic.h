#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include "struct.h"
#define _CRT_SECURE_NO_WARNINGS

void basic_view1(char * title);//실제 화면구현 위쪽 기본 창
void basic_view2(Player player);//실제 화면구현 아래쪽 기본 창

void gotoxy(int x, int y);
void game1(Player* player, int* floor);
void game2(Player* player, int* floor);
void game3(Player* player, int* floor);
void game4(Player* player, int* floor);

void setcursortype();
/*
char * input_text();
int input_number();
char input_char();
*/