#include "basic.h"
#include "function.h"

int main() {

	Player me = { "�÷��̾�", 100, 20, {0, 0} };
	Player boss = { "����", 200, 20, {0, 0} };
	Building** building;
	int floor = 1; //�÷��̾��� ���� ��
	int choice = 0; //�� ������ ������� �� ����

	system("mode con cols=100 lines=30");//�ܼ�â ����
	setcursortype(); //Ŀ�� �����ֱ�

					 
	//1.����ȭ�� ����ϱ�
	basic_view2(me);
	start_view();
	//2. �ϴ� �� �������� ���̵� ����
	//3. �ǹ� ����� �����ֱ�
	
	building = make_building();
	
	building_info(&building); // ���� ���� �־��ֱ�
	
	basic_view2(me);
	building_view(); //� Ű�� ������ �������� �Ѿ�� �Լ� ����
	
	while (floor <= 5) {
		basic_view2(me);

		floor_view(floor); //�� �� �����ֱ�
		choice = floor_logic(); //�� ����
		system("cls");
		basic_view2(me);
		building[floor - 1][choice].func(&me, &floor);
	}
	
	//����ȭ��
	basic_view2(me);
	result_view(); // �׳� ����Ű ������ �����ִ� ������ ���� ����
	free(building);//�ٸ������� free�������!!
}