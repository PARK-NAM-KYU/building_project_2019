#pragma once
typedef struct {
	void(*fp)(); //�� ȭ���� ����(�� ������ ȭ�� �ȿ��ٰ� ����)
	char * reward; //���⳪ ġ���� �� �ϳ�
}Building;

typedef struct {
	int weapon;
	int item_count;
}Equipment;

typedef struct {
	int hp;
	Equipment equipment;
}Player;

typedef struct {
	int x;
	int y;
}Position;
