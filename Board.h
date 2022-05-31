#pragma once
#include"Chess.h"
#include"Step.h"
#include<iostream>
#include<vector>
using namespace std;
class Board
{
public:
	Board() {
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
	//基础属性
	int times;//次数
	bool _redTime;
	//被选中的棋子
	int _selectchess;
	//待测试的棋子
	Chess _list[32];
	//获取选中棋子的编号
	int selectChecked(int row, int col);
	//走棋规则
	bool canMove(int moveId, int row, int col, int killId);
	bool canMoveChe(int moveId, int row, int col, int killId);
	bool canMoveMa(int moveId, int row, int col, int killId);
	bool canMoveXiang(int moveId, int row, int col, int killId);
	bool canMoveShi(int moveId, int row, int col, int killId);
	bool canMoveJiang(int moveId, int row, int col, int killId);
	bool canMovePao(int moveId, int row, int col, int killId);
	bool canMoveBing(int moveId, int row, int col, int killId);
	//获得2个棋子之间的象棋个数
	int getChessNumWithTwoChess(int moveId, int row, int col);
	int getChessNumWithTwoChess(int row, int row1, int col, int col1);
	//获得一个棋子的横纵坐标
	void getRowCol(int chessId, int& row, int& col);
	//计算棋子移动的时候棋子横纵坐标的特征值
	int relationNum(int row, int row1, int col, int col1);
	
	//人机对战部分
	//计算层次
	int _level;
	//杀死棋子
	void killChess(int killId);
	//复活棋子
	void reliveChess(int reliveId);
	//移动棋子
	void moveChess(int moveId, int row, int col);
	void moveChess(int moveid, int killid, int row, int col);
	//算法1(普通的最大最小值算法)
	//实现电脑走
	Step* getBestMove();
	//所有可以走的步骤
	virtual void getAllPossibleMove(vector<Step*>& steps);
	//向指定的数组中存储指定的步骤
	void saveStep(int moveId, int killId, int row, int col, vector<Step*>& steps);
	//内部走一步
	void fakeMove(Step* step);
	//内部返回
	void unfakeMove(Step* step);
	//计算当前局面得分
	int calcScore();
	//最大最小值算法
	virtual Step* getBestMoveByMaxMin() = 0;
	virtual int getMinScore(int level, int curMaxScore) = 0;
	virtual int getMaxScore(int level, int curMinSocer) = 0;
	void computerMove();
	virtual ~Board() {}
};

