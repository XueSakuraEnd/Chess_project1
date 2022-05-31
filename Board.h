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
	//��������
	int times;//����
	bool _redTime;
	//��ѡ�е�����
	int _selectchess;
	//�����Ե�����
	Chess _list[32];
	//��ȡѡ�����ӵı��
	int selectChecked(int row, int col);
	//�������
	bool canMove(int moveId, int row, int col, int killId);
	bool canMoveChe(int moveId, int row, int col, int killId);
	bool canMoveMa(int moveId, int row, int col, int killId);
	bool canMoveXiang(int moveId, int row, int col, int killId);
	bool canMoveShi(int moveId, int row, int col, int killId);
	bool canMoveJiang(int moveId, int row, int col, int killId);
	bool canMovePao(int moveId, int row, int col, int killId);
	bool canMoveBing(int moveId, int row, int col, int killId);
	//���2������֮����������
	int getChessNumWithTwoChess(int moveId, int row, int col);
	int getChessNumWithTwoChess(int row, int row1, int col, int col1);
	//���һ�����ӵĺ�������
	void getRowCol(int chessId, int& row, int& col);
	//���������ƶ���ʱ�����Ӻ������������ֵ
	int relationNum(int row, int row1, int col, int col1);
	
	//�˻���ս����
	//������
	int _level;
	//ɱ������
	void killChess(int killId);
	//��������
	void reliveChess(int reliveId);
	//�ƶ�����
	void moveChess(int moveId, int row, int col);
	void moveChess(int moveid, int killid, int row, int col);
	//�㷨1(��ͨ�������Сֵ�㷨)
	//ʵ�ֵ�����
	Step* getBestMove();
	//���п����ߵĲ���
	virtual void getAllPossibleMove(vector<Step*>& steps);
	//��ָ���������д洢ָ���Ĳ���
	void saveStep(int moveId, int killId, int row, int col, vector<Step*>& steps);
	//�ڲ���һ��
	void fakeMove(Step* step);
	//�ڲ�����
	void unfakeMove(Step* step);
	//���㵱ǰ����÷�
	int calcScore();
	//�����Сֵ�㷨
	virtual Step* getBestMoveByMaxMin() = 0;
	virtual int getMinScore(int level, int curMaxScore) = 0;
	virtual int getMaxScore(int level, int curMinSocer) = 0;
	void computerMove();
	virtual ~Board() {}
};

