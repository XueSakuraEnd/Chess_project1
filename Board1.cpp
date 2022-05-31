#include "Board1.h"
//�����Сֵ
Step* Board1::getBestMoveByMaxMin() {//����ֵ���
    //��������Щ���������
    vector<Step*> steps;
    getAllPossibleMove(steps);

    //������һ��
    //��ʼ��һ�����ĵ÷�
    int maxScore = -1000000;//ѡһ����С��ֵ��Ϊ��ʼֵ,Ҫ�ȼ�Сֵ���ķ���������
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
        if (maxScore < score) {//ȡ���ݼ���������ߵĽڵ�
            maxScore = score;
            if (good) delete good;//��������good
            good = step;
        }
        else {
            delete step;
        }
    }

    //����һ���ߵĽ��
    //����õĽ��
    return good;
}
//
int Board1::getMinScore(int level, int curMaxScore) {
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

        //��֦�Ż�
        /*if (score <= curMaxScore) {
            while (steps.size()) {
                delete step;
                step = steps.back();
                steps.pop_back();
            }
            return score;
        }*/
        //�ѷ�����¼����,���Ҽ�¼����
        if (score < minScore) {//ȡ��������������С�ĵ�
            minScore = score;
        }
        delete step;
    }
    return minScore;

}

int Board1::getMaxScore(int level, int curMinScore) {
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


        //��֦�Ż�
        /*if (score >= curMinScore) {
            while (steps.size()) {
                delete step;
                step = steps.back();
                steps.pop_back();
            }
            return score;
        }*/


        //�ѷ�����¼����,���Ҽ�¼����
        if (score > maxScore) {//ȡ��������������ߵĵ�
            maxScore = score;
        }
        delete step;
    }
    return maxScore;
}