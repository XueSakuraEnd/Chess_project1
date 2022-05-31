#include "Board1.h"
//最大最小值
Step* Board1::getBestMoveByMaxMin() {//极大值结点
    //看看有哪些步骤可以走
    vector<Step*> steps;
    getAllPossibleMove(steps);

    //试着走一下
    //初始化一个最大的得分
    int maxScore = -1000000;//选一个极小的值作为初始值,要比极小值结点的分数尽量少
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
        if (maxScore < score) {//取回溯计算后分数最高的节点
            maxScore = score;
            if (good) delete good;//清除缓存的good
            good = step;
        }
        else {
            delete step;
        }
    }

    //评估一下走的结果
    //区最好的结果
    return good;
}
//
int Board1::getMinScore(int level, int curMaxScore) {
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

        //剪枝优化
        /*if (score <= curMaxScore) {
            while (steps.size()) {
                delete step;
                step = steps.back();
                steps.pop_back();
            }
            return score;
        }*/
        //把分数记录下来,并且记录步骤
        if (score < minScore) {//取回溯运算后分数最小的点
            minScore = score;
        }
        delete step;
    }
    return minScore;

}

int Board1::getMaxScore(int level, int curMinScore) {
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


        //剪枝优化
        /*if (score >= curMinScore) {
            while (steps.size()) {
                delete step;
                step = steps.back();
                steps.pop_back();
            }
            return score;
        }*/


        //把分数记录下来,并且记录步骤
        if (score > maxScore) {//取回溯运算后分数最高的点
            maxScore = score;
        }
        delete step;
    }
    return maxScore;
}