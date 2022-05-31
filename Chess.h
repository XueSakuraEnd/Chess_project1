#pragma once
class Chess
{
public:
    enum TYPE { JIANG, CHE, PAO, MA, BING, SHI, XIANG };

    int _row;//��
    int _col;//��
    int _id;//���
    bool _die;//�Ƿ�����
    bool _red;//����ɫ�����Ǻ�ɫ��
    TYPE _type;//����
    void init(int id) {

        //һ�����̵�ͼ����������ɫ����ÿһ�������������ж�Ӧ��λ��
        struct {
            int row, col;
            Chess::TYPE type;
        }pos[16] = {
            {0,0,Chess::CHE},
            {0,1,Chess::MA},
            {0,2,Chess::XIANG},
            {0,3,Chess::SHI},
            {0,4,Chess::JIANG},
            {0,5,Chess::SHI},
            {0,6,Chess::XIANG},
            {0,7,Chess::MA},
            {0,8,Chess::CHE},
            {2,1,Chess::PAO},
            {2,7,Chess::PAO},
            {3,0,Chess::BING},
            {3,2,Chess::BING},
            {3,4,Chess::BING},
            {3,6,Chess::BING},
            {3,8,Chess::BING},
        };

        _id = id;
        _die = false;
        _red = 15 < id;
        //���С��16Ϊ��ɫ��������
        if (_id < 16) {
            _row = pos[id].row;
            _col = pos[id].col;
            _type = pos[id].type;
        }
        else {
            _row = 9 - pos[id - 16].row;
            _col = 8 - pos[id - 16].col;
            _type = pos[id - 16].type;
        }
    }
};

