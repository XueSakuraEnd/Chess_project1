#pragma once
#include"Board.h"
//�����Сֵ�㷨
class Board1:public Board
{
public:
	Board1() {
		//��ʼ������
		for (int i = 0; i < 32; i++)
		{
			this->_list[i].init(i);
		}
		this->_redTime = true;
		this->_selectchess = -1;
		this->_level = 4;
		this->times = 1;
	}
	//�����Сֵ�㷨
	Step* getBestMoveByMaxMin();
	int getMinScore(int level, int curMaxScore);
	int getMaxScore(int level, int curMinSocer);
};

