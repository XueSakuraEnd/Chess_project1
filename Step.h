#pragma once
class Step
{
public:
    //移动的棋子
    int _moveid;
    //杀掉的棋子
    int _killid;
    //上一步
    int _rowFrom;
    int _colFrom;
    //下一步
    int _rowTo;
    int _colTo;
};

