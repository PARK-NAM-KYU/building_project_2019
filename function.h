#pragma once
#include "struct.h"
void start_view();
Building ** make_building();
void building_view();
void building_info(Building*** building);
void event(Player* player, int* floor);
void game1(Player* player, int* floor);
void game2(Player* player, int* floor);
void game3(Player* player, int* floor);
void game4(Player* player, int* floor);
void battle(Player* me, Player* boss);

void floor_view(int);
int floor_logic(int floor);
void result_view();

