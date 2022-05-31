#include "Board.h"
#include<iostream>
using namespace std;

bool Board::canMove(int moveId, int row, int col, int killId) {
    ///同色
    //如果移动的棋子和被吃的棋子颜色相同不可以move
    if (_list[moveId]._red == _list[killId]._red && killId != -1) {
        //换选择
        _selectchess = killId;
        return false;
    }
    //不同色
    //复杂的情况,对每一个棋子进行判断
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

//移动车
bool Board::canMoveChe(int moveId, int row, int col, int killId) {
    //看看是不是之间没有棋子
    if (getChessNumWithTwoChess(moveId, row, col) == 0)
        return true;
    return false;
}
//移动马
bool Board::canMoveMa(int moveId, int row, int col, int killId) {
    //获取当前棋子的横纵坐标
    int row1, col1;
    getRowCol(moveId, row1, col1);
    //判断特征值，马的特征值是12或21
    int r = relationNum(row, row1, col, col1);
    if (r != 12 && r != 21)
        return false;
    //看看有没有棋子蹩马腿
    //12代表列相差2
    if (r == 12) {
        if (selectChecked(row1, (col + col1) / 2) != -1)
            return false;
    }
    else {
        //代表行相差2
        if (selectChecked((row + row1) / 2, col1) != -1)
            return false;
    }
    return true;
}
//移动象
bool Board::canMoveXiang(int moveId, int row, int col, int killId) {
    int row1, col1;
    //获取象的原先地址
    getRowCol(moveId, row1, col1);
    //计算移动前后的值
    int d = relationNum(row, row1, col, col1);
    //象的特征值是22
    if (d != 22) return false;
    //计算象眼的位置
    int rEye = (row + row1) / 2;
    int cEye = (col + col1) / 2;
    //看看象眼上有没有棋子
    if (selectChecked(rEye, cEye) != -1) {
        return false;
    }

    //现在再去限制象不可以过河
    if (_list[moveId]._red) {
        if (row < 5) return false;
    }
    else {
        if (row > 5) return false;
    }
    return true;
}
//移动士
bool Board::canMoveShi(int moveId, int row, int col, int killId) {
    //与将一样
    if (!_list[moveId]._red) {
        if (row > 2) return false;
    }
    else {
        if (row < 7) return false;
    }
    //列相等，看是否在一个范围内
    if (col < 3) return false;
    if (col > 5) return false;

    //判断移动步长
    //行间距
    int dr = _list[moveId]._row - row;
    //列间距
    int dc = _list[moveId]._col - col;
    //移动以后横纵都进行了1个单位的位移，所以相加为11
    int d = abs(dr) * 10 + abs(dc);
    if (d == 11)
        return true;
    //满足移动条件
    return false;
}
//移动将
bool Board::canMoveJiang(int moveId, int row, int col, int killId) {
    /*
        1.目标在九宫内
        2.移动的步长是一个格子
    */
    //对不同颜色的行进行判断
    if (!_list[moveId]._red) {
        if (row > 2) return false;
    }
    else {
        if (row < 7) return false;
    }
    //列相等，看是否在一个范围内
    if (col < 3) return false;
    if (col > 5) return false;

    //判断移动步长
    //行间距
    int dr = _list[moveId]._row - row;
    //列间距
    int dc = _list[moveId]._col - col;
    //牛逼的方法，把一个×10相加，如果满足的话，就有一个1就好了
    int d = abs(dr) * 10 + abs(dc);
    if (d == 10 || d == 1)
        return true;
    //如果老将碰老将可以直接跳过去

    //满足移动条件
    return false;
}
//移动炮
bool Board::canMovePao(int moveId, int row, int col, int killId) {
    //计算炮与要移动的地方距离几个棋子
    int num = getChessNumWithTwoChess(moveId, row, col);
    //如果要吃子且中间有一个棋子那么符合规则
    if (killId != -1) {
        if (num == 1) return true;
    }
    else {
        //如果不再吃棋子的状态而且中间没有任何棋子
        if (num == 0) return true;
    }
    return false;
}
//移动兵
bool Board::canMoveBing(int moveId, int row, int col, int killId) {
    //计算位置
    int row1, col1;
    getRowCol(moveId, row1, col1);
    //计算特征值，兵的特征值为1与10
    int r = relationNum(row, row1, col, col1);
    if (r != 1 && r != 10) return false;

    //如果是红棋
    if (_list[moveId]._red) {
        //目标行需要小于原来的行
        if (row > row1) return false;
        //如果没有过河还想平着走，拒绝
        if (row1 >= 5 && row == row1) return false;
    }
    else {
        //红棋，同理
        if (row < row1) return false;
        if (row1 <= 4 && row == row1) return false;
    }
    return true;
}

//计算棋子的特征值,同行为1,同列为1
int Board::relationNum(int row, int row1, int col, int col1) {
    return abs(row - row1) * 10 + abs(col - col1);
}

//获取选中棋子的编号
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
//通过棋子的id获取该棋子的横纵坐标
void Board::getRowCol(int chessId, int& row, int& col) {
    row = _list[chessId]._row;
    col = _list[chessId]._col;
}

//计算2个棋子之间的棋子数量
int Board::getChessNumWithTwoChess(int moveId, int row, int col) {
    int row1, col1;
    getRowCol(moveId, row1, col1);
    return getChessNumWithTwoChess(row, row1, col, col1);
}

int Board::getChessNumWithTwoChess(int row, int row1, int col, int col1) {
    int ret = 0;
    //不在同一条直线上
    if (row1 != row && col != col1) return -1;
    //同一个棋子
    if (row == row1 && col == col1) return -1;
    //如果在一条横线上
    if (row == row1) {
        //找最左边的棋子，开始遍历
        int min = col1 < col ? col1 : col;
        int max = col1 > col ? col1 : col;
        //开始遍历
        for (int c = min + 1; c < max; ++c) {
            //如果有棋子，那么ret++
            if (selectChecked(row, c) != -1) ++ret;
        }
    }
    else {
        //如果是在一条纵线上
        int min = row < row1 ? row : row1;
        int max = row > row1 ? row : row1;
        //遍历
        for (int r = min + 1; r < max; ++r) {
            if (selectChecked(r, col) != -1) ++ret;
        }
    }
    return ret;
}

//人机对战
//记录所有可能移动的棋子
void Board::getAllPossibleMove(vector<Step*>& steps) {
    //在不同的人玩的时候计算的分数不一样
    //红走
    int min = 16, max = 32;
    //黑走
    if (!this->_redTime) {
        min = 0;
        max = 16;
    }
    for (int i = min; i < max; ++i) {
        //死棋不可移动
        if (_list[i]._die) continue;
        //对于每一个棋子来说，都去看一下对应的剩余棋盘地方能不能移动
        for (int row = 0; row <= 9; ++row) {
            for (int col = 0; col <= 8; ++col) {
                //看看目标行列上有没有棋子
                int killId = this->selectChecked(row, col);
                if (killId != -1) {
                    //如果颜色相同
                    if (_list[i]._red == _list[killId]._red) {
                        //那就con'tintue
                        continue;
                    }
                }
                //如果可以移动
                if (canMove(i, row, col, killId)) {
                    //存起来                    
                    saveStep(i, killId, row, col, steps);
                }
            }
        }
    }
}

//存储步骤
void Board::saveStep(int moveId, int killId, int row, int col, vector<Step*>& steps) {
    int row1, col1;
    //获取当前棋子的坐标
    this->getRowCol(moveId, row1, col1);
    Step* step = new Step;
    step->_colFrom = col1;
    step->_rowFrom = row1;
    step->_colTo = col;
    step->_rowTo = row;
    step->_moveid = moveId;
    step->_killid = killId;
    //添加进队列当中
    steps.push_back(step);
}

Step* Board::getBestMove() {
    //使用最大最小值算法计算
    /*
        原理：
            先计算机自己走，算出来自己所有棋子里面的最大值，再去计算人走，最好的那一步
    */
    return getBestMoveByMaxMin();
}


//内部走一步
void Board::fakeMove(Step* step) {
    //杀死该杀死的棋子
    killChess(step->_killid);
    //移动该移动的棋子
    moveChess(step->_moveid, step->_rowTo, step->_colTo);
}
//内部返回
void Board::unfakeMove(Step* step) {
    reliveChess(step->_killid);
    moveChess(step->_moveid, step->_rowFrom, step->_colFrom);
}
//计算当前局面得分
int Board::calcScore() {//评估函数,最高分:2040,最低分:-2040
    int redScore = 0;
    int blackScore = 0;
    /*按照棋子的种类来分类*/
    //enum TYPE{ JIANG, CHE, PAO, MA, BING, SHI, XIANG};
    static int chessScore[] = { 1500,100,50,50,20,10,10 };
    //黑棋分的总数减去红棋分的总数
    //红棋的分数
    for (int i = 16; i < 32; i++) {
        if (_list[i]._die) continue;
        redScore += chessScore[_list->_type];
    }
    //黑棋的分数
    for (int i = 0; i < 16; i++) {
        if (_list[i]._die) continue;
        blackScore += chessScore[_list->_type];
    }
    //得分(红方)
    if (this->times==1 || this->times % 2 != 0)
        return redScore - blackScore;
    //得分(黑方)
    return blackScore - redScore;
}

//杀死棋子
void Board::killChess(int killId) {
    if (killId == -1) return;
    _list[killId]._die = true;
}
//复活棋子
void Board::reliveChess(int reliveId) {
    if (reliveId == -1) return;
    _list[reliveId]._die = false;
}

//移动棋子
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


//让电脑开始走棋
void Board::computerMove() {
    //该电脑走
    Step* step = getBestMove();
    moveChess(step->_moveid, step->_killid, step->_rowTo, step->_colTo);
    cout  << times++ << ": " << step->_rowFrom << " " << step->_colFrom << " " << step->_rowTo << " " << step->_colTo << endl;
    delete step;
}

