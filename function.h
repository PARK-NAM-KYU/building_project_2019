#pragma once
void start_view();
Building ** make_building();

void building_view();
void building_info(Building*** building);
void floor_view(int);
int floor_logic(int floor);
void result_view();

void event(Player* player, int* floor);
void game1(Player* player, int* floor);
void game2(Player* player, int* floor);
void game3(Player* player, int* floor);
void game4(Player* player, int* floor);

