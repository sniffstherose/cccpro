//给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10^n
#include<stdio.h>
//函数声明
int countNumbersWithUniqueDigits(int n);
int main()
{
	//定义一个数，储存从键盘上输入的10的指数；
	int n;

	scanf_s("%d", &n);
	int ans = countNumbersWithUniqueDigits(n);
	printf("%d", ans);

	return 0;
}
int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 10;
    }
    int ans = 10, cur = 9;
    for (int i = 0; i < n - 1; ++i) {
        cur *= 9 - i;
        ans += cur;
    }
    return ans;
}