#include <stdio.h>

int main() {
    int count = 0;
    // ���� 1 �� 100 ����������
    for (int i = 1; i <= 100; i++) {
        int num = i;
        // ����λ�Ƿ�Ϊ 9
        if (num % 10 == 9) {
            count++;
        }
        // ���ʮλ�Ƿ�Ϊ 9
        if (num / 10 == 9) {
            count++;
        }
    }
    printf("1 �� 100 ���������������� 9 ���ֵĴ���Ϊ: %d\n", count);
    return 0;
}
