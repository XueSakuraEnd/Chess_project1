#pragma once
#include "Board.h"
#include <cmath>
class Board3:public Board
{
public:
	Board3() {
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
	void che_find(int i, vector<Step*>& steps);
	void pao_find(int i, vector<Step*>& steps);
	void ma_find(int i, vector<Step*>& steps);
	void xiang_find(int i, vector<Step*>& steps);
	void shi_find(int i, vector<Step*>& steps);
	void jiang_find(int i, vector<Step*>& steps);
	void bin_find(int i, vector<Step*>& steps);
	void getAllPossibleMove(vector<Step*>& steps);
	//剪枝算法
	Step* getBestMoveByMaxMin();
	int getMinScore(int level, int curMaxScore);
	int getMaxScore(int level, int curMinSocer);
};

