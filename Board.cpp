#include "Board.h"
#include<iostream>
using namespace std;

bool Board::canMove(int moveId, int row, int col, int killId) {
    ///ͬɫ
    //����ƶ������Ӻͱ��Ե�������ɫ��ͬ������move
    if (_list[moveId]._red == _list[killId]._red && killId != -1) {
        //��ѡ��
        _selectchess = killId;
        return false;
    }
    //��ͬɫ
    //���ӵ����,��ÿһ�����ӽ����ж�
    switch (_list[moveId]._type) {
    case Chess::CHE:
        return canMoveChe(moveId, row, col, killId);
    case Chess::MA:
        return canMoveMa(moveId, row, col, killId);
    case Chess::XIANG:
        return canMoveXiang(moveId, row, col, killId);
    case Chess::SHI:
        return canMoveShi(moveId, row, col, killId);
    case Chess::JIANG:
        return canMoveJiang(moveId, row, col, killId);
    case Chess::PAO:
        return canMovePao(moveId, row, col, killId);
    case Chess::BING:
        return canMoveBing(moveId, row, col, killId);
    }

    return true;
}

//�ƶ���
bool Board::canMoveChe(int moveId, int row, int col, int killId) {
    //�����ǲ���֮��û������
    if (getChessNumWithTwoChess(moveId, row, col) == 0)
        return true;
    return false;
}
//�ƶ���
bool Board::canMoveMa(int moveId, int row, int col, int killId) {
    //��ȡ��ǰ���ӵĺ�������
    int row1, col1;
    getRowCol(moveId, row1, col1);
    //�ж�����ֵ���������ֵ��12��21
    int r = relationNum(row, row1, col, col1);
    if (r != 12 && r != 21)
        return false;
    //������û������������
    //12���������2
    if (r == 12) {
        if (selectChecked(row1, (col + col1) / 2) != -1)
            return false;
    }
    else {
        //���������2
        if (selectChecked((row + row1) / 2, col1) != -1)
            return false;
    }
    return true;
}
//�ƶ���
bool Board::canMoveXiang(int moveId, int row, int col, int killId) {
    int row1, col1;
    //��ȡ���ԭ�ȵ�ַ
    getRowCol(moveId, row1, col1);
    //�����ƶ�ǰ���ֵ
    int d = relationNum(row, row1, col, col1);
    //�������ֵ��22
    if (d != 22) return false;
    //�������۵�λ��
    int rEye = (row + row1) / 2;
    int cEye = (col + col1) / 2;
    //������������û������
    if (selectChecked(rEye, cEye) != -1) {
        return false;
    }

    //������ȥ�����󲻿��Թ���
    if (_list[moveId]._red) {
        if (row < 5) return false;
    }
    else {
        if (row > 5) return false;
    }
    return true;
}
//�ƶ�ʿ
bool Board::canMoveShi(int moveId, int row, int col, int killId) {
    //�뽫һ��
    if (!_list[moveId]._red) {
        if (row > 2) return false;
    }
    else {
        if (row < 7) return false;
    }
    //����ȣ����Ƿ���һ����Χ��
    if (col < 3) return false;
    if (col > 5) return false;

    //�ж��ƶ�����
    //�м��
    int dr = _list[moveId]._row - row;
    //�м��
    int dc = _list[moveId]._col - col;
    //�ƶ��Ժ���ݶ�������1����λ��λ�ƣ��������Ϊ11
    int d = abs(dr) * 10 + abs(dc);
    if (d == 11)
        return true;
    //�����ƶ�����
    return false;
}
//�ƶ���
bool Board::canMoveJiang(int moveId, int row, int col, int killId) {
    /*
        1.Ŀ���ھŹ���
        2.�ƶ��Ĳ�����һ������
    */
    //�Բ�ͬ��ɫ���н����ж�
    if (!_list[moveId]._red) {
        if (row > 2) return false;
    }
    else {
        if (row < 7) return false;
    }
    //����ȣ����Ƿ���һ����Χ��
    if (col < 3) return false;
    if (col > 5) return false;

    //�ж��ƶ�����
    //�м��
    int dr = _list[moveId]._row - row;
    //�м��
    int dc = _list[moveId]._col - col;
    //ţ�Ƶķ�������һ����10��ӣ��������Ļ�������һ��1�ͺ���
    int d = abs(dr) * 10 + abs(dc);
    if (d == 10 || d == 1)
        return true;
    //����Ͻ����Ͻ�����ֱ������ȥ

    //�����ƶ�����
    return false;
}
//�ƶ���
bool Board::canMovePao(int moveId, int row, int col, int killId) {
    //��������Ҫ�ƶ��ĵط����뼸������
    int num = getChessNumWithTwoChess(moveId, row, col);
    //���Ҫ�������м���һ��������ô���Ϲ���
    if (killId != -1) {
        if (num == 1) return true;
    }
    else {
        //������ٳ����ӵ�״̬�����м�û���κ�����
        if (num == 0) return true;
    }
    return false;
}
//�ƶ���
bool Board::canMoveBing(int moveId, int row, int col, int killId) {
    //����λ��
    int row1, col1;
    getRowCol(moveId, row1, col1);
    //��������ֵ����������ֵΪ1��10
    int r = relationNum(row, row1, col, col1);
    if (r != 1 && r != 10) return false;

    //����Ǻ���
    if (_list[moveId]._red) {
        //Ŀ������ҪС��ԭ������
        if (row > row1) return false;
        //���û�й��ӻ���ƽ���ߣ��ܾ�
        if (row1 >= 5 && row == row1) return false;
    }
    else {
        //���壬ͬ��
        if (row < row1) return false;
        if (row1 <= 4 && row == row1) return false;
    }
    return true;
}

//�������ӵ�����ֵ,ͬ��Ϊ1,ͬ��Ϊ1
int Board::relationNum(int row, int row1, int col, int col1) {
    return abs(row - row1) * 10 + abs(col - col1);
}

//��ȡѡ�����ӵı��
int Board::selectChecked(int row, int col)
{
    int i = 0;
    for (; i < 32; i++)
    {
        if (_list[i]._row == row && _list[i]._col == col && _list[i]._die == false)
            break;
    }
    if (i < 32)
        return i;
    return -1;
}
//ͨ�����ӵ�id��ȡ�����ӵĺ�������
void Board::getRowCol(int chessId, int& row, int& col) {
    row = _list[chessId]._row;
    col = _list[chessId]._col;
}

//����2������֮�����������
int Board::getChessNumWithTwoChess(int moveId, int row, int col) {
    int row1, col1;
    getRowCol(moveId, row1, col1);
    return getChessNumWithTwoChess(row, row1, col, col1);
}

int Board::getChessNumWithTwoChess(int row, int row1, int col, int col1) {
    int ret = 0;
    //����ͬһ��ֱ����
    if (row1 != row && col != col1) return -1;
    //ͬһ������
    if (row == row1 && col == col1) return -1;
    //�����һ��������
    if (row == row1) {
        //������ߵ����ӣ���ʼ����
        int min = col1 < col ? col1 : col;
        int max = col1 > col ? col1 : col;
        //��ʼ����
        for (int c = min + 1; c < max; ++c) {
            //��������ӣ���ôret++
            if (selectChecked(row, c) != -1) ++ret;
        }
    }
    else {
        //�������һ��������
        int min = row < row1 ? row : row1;
        int max = row > row1 ? row : row1;
        //����
        for (int r = min + 1; r < max; ++r) {
            if (selectChecked(r, col) != -1) ++ret;
        }
    }
    return ret;
}

//�˻���ս
//��¼���п����ƶ�������
void Board::getAllPossibleMove(vector<Step*>& steps) {
    //�ڲ�ͬ�������ʱ�����ķ�����һ��
    //����
    int min = 16, max = 32;
    //����
    if (!this->_redTime) {
        min = 0;
        max = 16;
    }
    for (int i = min; i < max; ++i) {
        //���岻���ƶ�
        if (_list[i]._die) continue;
        //����ÿһ��������˵����ȥ��һ�¶�Ӧ��ʣ�����̵ط��ܲ����ƶ�
        for (int row = 0; row <= 9; ++row) {
            for (int col = 0; col <= 8; ++col) {
                //����Ŀ����������û������
                int killId = this->selectChecked(row, col);
                if (killId != -1) {
                    //�����ɫ��ͬ
                    if (_list[i]._red == _list[killId]._red) {
                        //�Ǿ�con'tintue
                        continue;
                    }
                }
                //��������ƶ�
                if (canMove(i, row, col, killId)) {
                    //������                    
                    saveStep(i, killId, row, col, steps);
                }
            }
        }
    }
}

//�洢����
void Board::saveStep(int moveId, int killId, int row, int col, vector<Step*>& steps) {
    int row1, col1;
    //��ȡ��ǰ���ӵ�����
    this->getRowCol(moveId, row1, col1);
    Step* step = new Step;
    step->_colFrom = col1;
    step->_rowFrom = row1;
    step->_colTo = col;
    step->_rowTo = row;
    step->_moveid = moveId;
    step->_killid = killId;
    //��ӽ����е���
    steps.push_back(step);
}

Step* Board::getBestMove() {
    //ʹ�������Сֵ�㷨����
    /*
        ԭ��
            �ȼ�����Լ��ߣ�������Լ�����������������ֵ����ȥ�������ߣ���õ���һ��
    */
    return getBestMoveByMaxMin();
}


//�ڲ���һ��
void Board::fakeMove(Step* step) {
    //ɱ����ɱ��������
    killChess(step->_killid);
    //�ƶ����ƶ�������
    moveChess(step->_moveid, step->_rowTo, step->_colTo);
}
//�ڲ�����
void Board::unfakeMove(Step* step) {
    reliveChess(step->_killid);
    moveChess(step->_moveid, step->_rowFrom, step->_colFrom);
}
//���㵱ǰ����÷�
int Board::calcScore() {//��������,��߷�:2040,��ͷ�:-2040
    int redScore = 0;
    int blackScore = 0;
    /*�������ӵ�����������*/
    //enum TYPE{ JIANG, CHE, PAO, MA, BING, SHI, XIANG};
    static int chessScore[] = { 1500,100,50,50,20,10,10 };
    //����ֵ�������ȥ����ֵ�����
    //����ķ���
    for (int i = 16; i < 32; i++) {
        if (_list[i]._die) continue;
        redScore += chessScore[_list->_type];
    }
    //����ķ���
    for (int i = 0; i < 16; i++) {
        if (_list[i]._die) continue;
        blackScore += chessScore[_list->_type];
    }
    //�÷�(�췽)
    if (this->times==1 || this->times % 2 != 0)
        return redScore - blackScore;
    //�÷�(�ڷ�)
    return blackScore - redScore;
}

//ɱ������
void Board::killChess(int killId) {
    if (killId == -1) return;
    _list[killId]._die = true;
}
//��������
void Board::reliveChess(int reliveId) {
    if (reliveId == -1) return;
    _list[reliveId]._die = false;
}

//�ƶ�����
void Board::moveChess(int moveId, int row, int col)
{
    _list[moveId]._row = row;
    _list[moveId]._col = col;

    _redTime = !_redTime;
}
void Board::moveChess(int moveid, int killid, int row, int col) {
    killChess(killid);
    moveChess(moveid, row, col);

}


//�õ��Կ�ʼ����
void Board::computerMove() {
    //�õ�����
    Step* step = getBestMove();
    moveChess(step->_moveid, step->_killid, step->_rowTo, step->_colTo);
    cout  << times++ << ": " << step->_rowFrom << " " << step->_colFrom << " " << step->_rowTo << " " << step->_colTo << endl;
    delete step;
}

