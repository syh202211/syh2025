#include <stdio.h>

// ���庯�������ڴ�ӡ x �ĸ�λ��ʮλ
void print_ones_and_tens(int x) {
    // ȡ��λ
    int ones_digit = x % 10;
    // ȡʮλ
    int tens_digit = (x / 10) % 10;
    printf("���� %d �ĸ�λ������: %d��ʮλ������: %d\n", x, ones_digit, tens_digit);
}

int main() {
    int x = 456;
    // ���ú���
    print_ones_and_tens(x);

    return 0;
}
