#include<iostream>
#include<Windows.h>
#include"Board.h"
#include"Board1.h"
#include"Board2.h"
#include "Board3.h"
using namespace std;
int main() {
	Board* Bacction = nullptr;
	while (true) {
		int times = 1;
		int modle = 1;
		cout << "��ѡ��ģʽ: " << endl;
		cout << "0.�˳�" << endl;
		cout << "1.�����Сֵ�㷨" << endl;
		cout << "2.��֦�㷨" << endl;
		cout << "3.��֦�㷨(����·���Ż�)" << endl;
		cin >> modle;
		switch (modle)
		{
		case 0:
			exit(0);
			break;
		case 1:
			Bacction = new Board1();
			cout << "��ǰѡ�������Сֵ�㷨" << endl;
			break;
		case 2:
			Bacction = new Board2();
			cout << "��ǰѡ���֦�㷨" << endl;
			break;
		case 3:
			Bacction = new Board3();
			cout << "��ǰѡ���֦�㷨(����·���Ż�)" << endl;
			break;
		default:
			break;
		}
		cout << "��������Դ���: ";
		cin >> times;
		times += 1;
		cout << "��ѡ���������(Ĭ��Ϊ4): " << endl;
		cin >> Bacction->_level;
		DWORD alltime = 0;
		int i = 0;
		while (times -= 1)
		{
			DWORD _start_time = GetTickCount();
			Bacction->computerMove();
			DWORD _end_time = GetTickCount();
			Bacction->_redTime != Bacction->_redTime;
			alltime += (_end_time - _start_time);
			cout << "��" << (i += 1) << "��:" << (_end_time - _start_time) << endl;
		}
		cout << "�������!" << endl;
		cout << "��ǰ�������Ϊ: " << Bacction->_level << " ������:" << i << "��" << " ��ʱ��Ϊ:" << alltime << " ƽ��ʱ��Ϊ:" << (double)alltime / i << endl;
	}
	return 0;
}
