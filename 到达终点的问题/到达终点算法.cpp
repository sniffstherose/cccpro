#include<stdio.h>
//函数声明
bool reachingPoints(int sx, int sy, int tx, int ty);
int main()
{
    int sx, sy, tx, ty;

    scanf_s("%d%d%d%d", &sx, &sy, &tx, &ty);
    //调用函数
    bool ans = reachingPoints(sx, sy, tx, ty);
    if (ans)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
//实现判断是否能经过特定转变从起点到终点的函数
bool reachingPoints(int sx, int sy, int tx, int ty) {
 /*只能有一种操作，就是将tx、ty中较大值减去较小值（因为顺推的时候是(x, y)
 可以转换到 (x, x+y) 或者 (x+y, y)，则逆推的时候只能将较大者减去较小者）*/
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