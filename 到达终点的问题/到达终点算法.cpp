#include<stdio.h>
//��������
bool reachingPoints(int sx, int sy, int tx, int ty);
int main()
{
    int sx, sy, tx, ty;

    scanf_s("%d%d%d%d", &sx, &sy, &tx, &ty);
    //���ú���
    bool ans = reachingPoints(sx, sy, tx, ty);
    if (ans)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
//ʵ���ж��Ƿ��ܾ����ض�ת�����㵽�յ�ĺ���
bool reachingPoints(int sx, int sy, int tx, int ty) {
 /*ֻ����һ�ֲ��������ǽ�tx��ty�нϴ�ֵ��ȥ��Сֵ����Ϊ˳�Ƶ�ʱ����(x, y)
 ����ת���� (x, x+y) ���� (x+y, y)�������Ƶ�ʱ��ֻ�ܽ��ϴ��߼�ȥ��С�ߣ�*/
    while (tx > sx && ty > sy && tx != ty) {
        if (tx > ty) {
            tx %= ty;
        }
        else {
            ty %= tx;
        }
    }
    if (tx == sx && ty == sy) {
        return true;
    }
    else if (tx == sx) {
        return ty > sy && (ty - sy) % tx == 0;
    }
    else if (ty == sy) {
        return tx > sx && (tx - sx) % ty == 0;
    }
    else {
        return false;
    }
}