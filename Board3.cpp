#include "Board3.h"
//����·���㷨�Ż�
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
            //�����ɫ��ͬ
            if (_list[i]._red == _list[killId]._red) {
                //�Ǿ�contintue
                continue;
            }
        }
        //��������ƶ�
        if (canMove(i, row,col, killId)) {
            //������                    
            saveStep(i, killId, row, col, steps);
        }
    }
}
void Board3::pao_find(int i, vector<Step*>& steps) {//���복���߼�һ��
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
            //�����ɫ��ͬ
            if (_list[i]._red == _list[killId]._red) {
                //�Ǿ�con'tintue
                continue;
            }
        }
        //��������ƶ�
        if (canMove(i, row,col, killId)) {
            //������                    
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
            //�����ɫ��ͬ
            if (_list[i]._red == _list[killId]._red) {
                //�Ǿ�con'tintue
                continue;
            }
        }
        //��������ƶ�
        if (canMove(i,row, col, killId)) {
            //������                    
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
            //�����ɫ��ͬ
            if (_list[i]._red == _list[killId]._red) {
                //�Ǿ�con'tintue
                continue;
            }
        }
        //��������ƶ�
        if (canMove(i, row, col, killId)) {
            //������                    
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
void Board3::getAllPossibleMove(vector<Step*>& steps) {
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

//�����Сֵ
Step* Board3::getBestMoveByMaxMin() {
    //��������Щ���������
    vector<Step*> steps;
    getAllPossibleMove(steps);
    //������һ��
    //��ʼ��һ�����ĵ÷�
    int maxScore = -1000000;
    //��¼��ǰ�÷���ߵĲ���
    Step* good = nullptr;
    while (steps.size())
    {
        //��ֹ�ڴ����
        Step* step = steps.back();
        steps.pop_back();
        //������һ����������
        fakeMove(step);
        //��������
        int score = getMinScore(_level, maxScore);
        //�������ƶ�����
        unfakeMove(step);

        //�ѷ�����¼����,���Ҽ�¼����
        if (maxScore < score) {
            maxScore = score;
            if (good) delete good;
            good = step;
        }
        else
            delete step;
    }

    //����һ���ߵĽ��
    //����õĽ��
    return good;
}
//
int Board3::getMinScore(int level, int curMaxScore) {
    //�������Ҫ������ˣ��Ǿ�ֱ�Ӽ��㵱ǰ�����

    if (level == 0) return calcScore();
    //������������һЩ����
    vector<Step*> steps;
    getAllPossibleMove(steps);
    int minScore = 1000000;
    while (steps.size()) {
        Step* step = steps.back();
        steps.pop_back();
        //������һ����������
        fakeMove(step);
        //��������
        int score = getMaxScore(level - 1, minScore);
        //�������ƶ�����
        unfakeMove(step);
        //�ѷ�����¼����,���Ҽ�¼����
        if (score < minScore) {
            minScore = score;
        }
        //��֦�Ż�
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
    //�������Ҫ�����ˣ��Ǿ�ֱ�Ӽ��㵱ǰ�����
    //qDebug() << level;
    if (level == 0) return calcScore();
    //������������һЩ����
    vector<Step*> steps;
    getAllPossibleMove(steps);
    int maxScore = -1000000;
    while (steps.size()) {
        Step* step = steps.back();
        steps.pop_back();
        //������һ����������
        fakeMove(step);
        //��������
        int score = getMinScore(level - 1, maxScore);
        //�������ƶ�����
        unfakeMove(step);
        //�ѷ�����¼����,���Ҽ�¼����
        if (score > maxScore) {
            maxScore = score;
        }
        //��֦�Ż�
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