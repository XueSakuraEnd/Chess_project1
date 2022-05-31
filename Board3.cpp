#include "Board3.h"
//查找路径算法优化
void Board3::che_find(int i, vector<Step*>& steps) {
    for (int j = 0; j <= 18; j++)
    {
        int killId = 0;
        int row = 0;
        int col = 0;
        if (j <= 8) {
            row = _list[i]._row;
            col = j;
        }
        else {
            row = 18 - j;
            col = _list[i]._col;
        }
        killId = this->selectChecked(row, col);
        if (killId != -1) {
            //如果颜色相同
            if (_list[i]._red == _list[killId]._red) {
                //那就contintue
                continue;
            }
        }
        //如果可以移动
        if (canMove(i, row,col, killId)) {
            //存起来                    
            saveStep(i, killId, row, col, steps);
        }
    }
}
void Board3::pao_find(int i, vector<Step*>& steps) {//炮与车的逻辑一致
    che_find(i,steps);
}
void Board3::ma_find(int i, vector<Step*>& steps) {
    for (int j = 1; j <= 8; j++) {
        int killId = 0;
        int row = 0;
        int col = 0;
        if (j <= 4)
        {
            if (_list[i]._row + 2 * pow(-1, j) < 0 || _list[i]._row + 2 * pow(-1, j) > 9 || _list[i]._col + pow(-1, 2 < j) < 0 || _list[i]._col + pow(-1, 2 < j) > 8)
                continue;
            row = _list[i]._row + 2 * pow(-1, j);
            col = _list[i]._col + pow(-1, 2 < j);
        }
        else
        {
            if (_list[i]._row + pow(-1, j) < 0 || _list[i]._row + pow(-1, j) > 9 || _list[i]._col + 2 * pow(-1, 6 < j) < 0 || _list[i]._col + 2 * pow(-1, 6 < j) > 8)
                continue;
            row = _list[i]._row + pow(-1, j);
            col = _list[i]._col + 2 * pow(-1, 6 < j);
        }
        killId = this->selectChecked(row,col);
        if (killId != -1) {
            //如果颜色相同
            if (_list[i]._red == _list[killId]._red) {
                //那就con'tintue
                continue;
            }
        }
        //如果可以移动
        if (canMove(i, row,col, killId)) {
            //存起来                    
            saveStep(i, killId,row, col, steps);
        }
    }
}
void Board3::xiang_find(int i, vector<Step*>& steps) {
    for (int j = 1; j <= 4; j++) {
        int killId = 0;
        int row = 0;
        int col = 0;
        if (_list[i]._row + 2 * pow(-1, j) < 0 || _list[i]._row + 2 * pow(-1, j) > 9 || _list[i]._col + 2 * pow(-1, 2 < j) < 0 || _list[i]._col + 2 * pow(-1, 2 < j) > 8)
                continue;
        row = _list[i]._row + 2 * pow(-1, j);
        col = _list[i]._col + 2 * pow(-1, 2 < j);
        killId = this->selectChecked(row, col);
        if (killId != -1) {
            //如果颜色相同
            if (_list[i]._red == _list[killId]._red) {
                //那就con'tintue
                continue;
            }
        }
        //如果可以移动
        if (canMove(i,row, col, killId)) {
            //存起来                    
            saveStep(i, killId, row,col, steps);
        }
    }
}
void Board3::shi_find(int i, vector<Step*>& steps) {
    for (int j = 1; j <= 5; j++)
    {
        int killId = 0;
        int row = 0;
        int col = 0;
        if (j == 3) {
            row = _list[i]._red != true ? 1 : 8;
            col = 4;
        }
        else {
            row = _list[i]._red != true ? 1 + pow(-1, 3 > j) : 8 + pow(-1, 3 > j);
            col = 4 + pow(-1, abs(j - 3) == 1);
        }
        killId = this->selectChecked(row, col);
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
void Board3::jiang_find(int i, vector<Step*>& steps) {
    int black_arr[5][2] = { {0,4},{1,3},{1,4},{1,5},{2,4} };
    int red_arr[5][2] = { {9,4},{8,3},{8,4},{8,5},{7,4} };
    for (int j = 0; j < 5; j++) {
        int killId = 0;
        int row = 0;
        int col = 0;
        row = _list[i]._red != true ? black_arr[j][0] : red_arr[j][0];
        col = _list[i]._red != true ? black_arr[j][1] : red_arr[j][1];
        killId = this->selectChecked(row, col);
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
            saveStep(i, killId, row,col, steps);
        }
    }
}
void Board3::bin_find(int i, vector<Step*>& steps) {
    for (int j = 1; j <= 4; j++)
    {
        int killId = 0;
        int row = 0;
        int col = 0;
        row = j <= 2 ? _list[i]._row + pow(-1, j) : _list[i]._row;
        col = j <= 2 ? _list[i]._col : _list[i]._col + pow(-1, j);
        killId = this->selectChecked(row,col);
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
void Board3::getAllPossibleMove(vector<Step*>& steps) {
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
        switch (_list[i]._type)
        {
        case Chess::CHE:
            this->che_find(i,steps);
            break;
        case Chess::PAO:
            this->pao_find(i, steps);
            break;
        case Chess::MA:
            this->ma_find(i, steps);
            break;
        case Chess::XIANG:
            this->xiang_find(i, steps);
            break;
        case Chess::JIANG:
            this->jiang_find(i, steps);
            break;
        case Chess::SHI:
            this->shi_find(i, steps);
            break;
        case Chess::BING:
            this->bin_find(i, steps);
            break;
        }
    }
}

//最大最小值
Step* Board3::getBestMoveByMaxMin() {
    //看看有哪些步骤可以走
    vector<Step*> steps;
    getAllPossibleMove(steps);
    //试着走一下
    //初始化一个最大的得分
    int maxScore = -1000000;
    //记录当前得分最高的步骤
    Step* good = nullptr;
    while (steps.size())
    {
        //防止内存溢出
        Step* step = steps.back();
        steps.pop_back();
        //程序走一步看看局面
        fakeMove(step);
        //计算局面分
        int score = getMinScore(_level, maxScore);
        //把棋子移动回来
        unfakeMove(step);

        //把分数记录下来,并且记录步骤
        if (maxScore < score) {
            maxScore = score;
            if (good) delete good;
            good = step;
        }
        else
            delete step;
    }

    //评估一下走的结果
    //区最好的结果
    return good;
}
//
int Board3::getMinScore(int level, int curMaxScore) {
    //如果不需要计算机了，那就直接计算当前局面分

    if (level == 0) return calcScore();
    //看看可以走哪一些步骤
    vector<Step*> steps;
    getAllPossibleMove(steps);
    int minScore = 1000000;
    while (steps.size()) {
        Step* step = steps.back();
        steps.pop_back();
        //程序走一步看看局面
        fakeMove(step);
        //计算局面分
        int score = getMaxScore(level - 1, minScore);
        //把棋子移动回来
        unfakeMove(step);
        //把分数记录下来,并且记录步骤
        if (score < minScore) {
            minScore = score;
        }
        //剪枝优化
        if (score <= curMaxScore) {
            while (steps.size()) {
                delete step;
                step = steps.back();
                steps.pop_back();
            }
            return score;
        }

        delete step;
    }
    return minScore;

}

int Board3::getMaxScore(int level, int curMinScore) {
    //如果不需要计算了，那就直接计算当前局面分
    //qDebug() << level;
    if (level == 0) return calcScore();
    //看看可以走哪一些步骤
    vector<Step*> steps;
    getAllPossibleMove(steps);
    int maxScore = -1000000;
    while (steps.size()) {
        Step* step = steps.back();
        steps.pop_back();
        //程序走一步看看局面
        fakeMove(step);
        //计算局面分
        int score = getMinScore(level - 1, maxScore);
        //把棋子移动回来
        unfakeMove(step);
        //把分数记录下来,并且记录步骤
        if (score > maxScore) {
            maxScore = score;
        }
        //剪枝优化
        if (score >= curMinScore) {
            while (steps.size()) {
                delete step;
                step = steps.back();
                steps.pop_back();
            }
            return score;
        }


        
        delete step;
    }
    return maxScore;
}