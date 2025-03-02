#include <stdio.h>

// 定义函数，用于打印 x 的个位和十位
void print_ones_and_tens(int x) {
    // 取个位
    int ones_digit = x % 10;
    // 取十位
    int tens_digit = (x / 10) % 10;
    printf("数字 %d 的个位数字是: %d，十位数字是: %d\n", x, ones_digit, tens_digit);
}

int main() {
    int x = 456;
    // 调用函数
    print_ones_and_tens(x);

    return 0;
}
