#pragma once
#include"Board.h"
//剪枝算法
class Board2:public Board
{
public:
	Board2() {
		//初始化棋子
		for (int i = 0; i < 32; i++)
		{
			this->_list[i].init(i);
		}
		this->_redTime = true;
		this->_selectchess = -1;
		this->_level = 4;
		this->times = 1;
	}
	//剪枝算法
	Step* getBestMoveByMaxMin();
	int getMinScore(int level, int curMaxScore);
	int getMaxScore(int level, int curMinSocer);
};

