void conversion()
{
    // 对于输入的任意一个非负十进制整数，打印输出与其等值的八进制数
    InitStack(S); // 构造空栈
    scanf("% d", N);
    while (N)
    {
        Push(S, N % 8);
        N = N / 8;
    }
    while (!StackEmpty(s))
    {
        Pop(S, e);
        printf("% d", e);
    }
} // conversion