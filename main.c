#include "basic.h"
#include "function.h"

int main() {

	Player me = { "�÷��̾�",50,{0,0}};
	Building** building;
	int floor = 1; //�÷��̾��� ���� ��
	int choice = 0; //�� ������ ������� �� ����
	
	//�ܼ�â ����
	system("mode con cols=100 lines=30");

	//�÷��̾��� ������ ������ִ� �ϴ�ȭ��
	//1.����ȭ�� ����ϱ�
	basic_view2(me);
	start_view();
	//2. �ϴ� �� �������� ���̵� ����
	//3. �ǹ� ����� �����ֱ�
	
	//building = make_building();
	
	//building_info(&building); // ���� ���� �־��ֱ�
	basic_view2(me);
	building_view(); //� Ű�� ������ �������� �Ѿ�� �Լ� ����
	/*
	while (floor <= 5) {
		floor_view(floor); //�� �� �����ֱ�
		choice = floor_logic(); //�� ����
		building[floor - 1][choice - 1].func(&me, &floor);
	}
	*/
	
	
	//����ȭ��
	basic_view2(me);
	result_view(); // �׳� ����Ű ������ �����ִ� ������ ���� ����
	//free(building);//�ٸ������� free�������!!
	
	
}