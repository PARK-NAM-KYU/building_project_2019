#include "basic.h"
#include "function.h"
#include <Windows.h>

int main() {

	Player me = { "�÷��̾�",50,{0,0}};
	Building** building;
	int floor = 1; //�÷��̾��� ���� ��
	int choice = 0; //�� ������ ������� �� ����
	
	//�ܼ�â ����
	system("mode con cols=100 lines=30");

	//�÷��̾��� ������ ������ִ� �ϴ�ȭ��
	basic_view2(me);

	//1.����ȭ�� ����ϱ�
	start_view();
	//2. �ϴ� �� �������� ���̵� ����
	//3. �ǹ� ����� �����ֱ�
	
	//building = make_building();
	
	//building_info(&building); // ���� ���� �־��ֱ�
	
	building_view(); //� Ű�� ������ �������� �Ѿ�� �Լ� ����
	/*
	while (floor <= 5) {
		floor_view(floor); //�� �� �����ֱ�
		choice = floor_logic(); //�� ����
		building[floor - 1][choice - 1].func(&me, &floor);
	}
	*/
	
	
	//����ȭ��
	result_view(); // �׳� ����Ű ������ �����ִ� ������ ���� ����
	//free(building);//�ٸ������� free�������!!
	
	
}