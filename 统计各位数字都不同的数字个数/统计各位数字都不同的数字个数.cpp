//����һ������ n ��ͳ�Ʋ����ظ�λ���ֶ���ͬ������ x �ĸ��������� 0 <= x < 10^n
#include<stdio.h>
//��������
int countNumbersWithUniqueDigits(int n);
int main()
{
	//����һ����������Ӽ����������10��ָ����
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