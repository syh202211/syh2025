#include <stdio.h>

int main() {
    int count = 0;
    // 遍历 1 到 100 的所有整数
    for (int i = 1; i <= 100; i++) {
        int num = i;
        // 检查个位是否为 9
        if (num % 10 == 9) {
            count++;
        }
        // 检查十位是否为 9
        if (num / 10 == 9) {
            count++;
        }
    }
    printf("1 到 100 的所有整数中数字 9 出现的次数为: %d\n", count);
    return 0;
}
