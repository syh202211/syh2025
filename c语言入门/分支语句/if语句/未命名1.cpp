#include <stdio.h>

int main() {
    int x = 123;
    // 取个位
    int ones_digit = x % 10;
    // 取十位
    int tens_digit = (x / 10) % 10;

    printf("个位数字是: %d\n", ones_digit);
    printf("十位数字是: %d\n", tens_digit);

    return 0;
}
