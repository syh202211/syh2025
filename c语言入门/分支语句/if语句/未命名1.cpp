#include <stdio.h>

int main() {
    int x = 123;
    // ȡ��λ
    int ones_digit = x % 10;
    // ȡʮλ
    int tens_digit = (x / 10) % 10;

    printf("��λ������: %d\n", ones_digit);
    printf("ʮλ������: %d\n", tens_digit);

    return 0;
}
