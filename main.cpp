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
		cout << "请选择模式: " << endl;
		cout << "0.退出" << endl;
		cout << "1.最大最小值算法" << endl;
		cout << "2.剪枝算法" << endl;
		cout << "3.剪枝算法(搜索路径优化)" << endl;
		cin >> modle;
		switch (modle)
		{
		case 0:
			exit(0);
			break;
		case 1:
			Bacction = new Board1();
			cout << "当前选择最大最小值算法" << endl;
			break;
		case 2:
			Bacction = new Board2();
			cout << "当前选择剪枝算法" << endl;
			break;
		case 3:
			Bacction = new Board3();
			cout << "当前选择剪枝算法(搜索路径优化)" << endl;
			break;
		default:
			break;
		}
		cout << "请输入调试次数: ";
		cin >> times;
		times += 1;
		cout << "请选择运算深度(默认为4): " << endl;
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
			cout << "第" << (i += 1) << "次:" << (_end_time - _start_time) << endl;
		}
		cout << "运行完毕!" << endl;
		cout << "当前运算深度为: " << Bacction->_level << " 运行了:" << i << "次" << " 总时长为:" << alltime << " 平均时长为:" << (double)alltime / i << endl;
	}
	return 0;
}
