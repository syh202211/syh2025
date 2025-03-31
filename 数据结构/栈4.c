void LineEdit()
{
    // 利用字符栈S,从终端接收一行并传送至调用过程的数据区。
    InitStack(S);   // 构造空栈S
    ch = getchar(); // 从终端接收第一个字符
    while (ch != EOF)
    { // EOF为全文结束符
        while (ch != EOF && ch != '\n')
        {
            switch (ch)
            {
            case '#':
                Pop(S, c);
                break; // 仅当栈非空时退栈
            case '@':
                ClearStack(S);
                break; // 重置S为空栈
            default:
                Push(S, ch);
                break; // 有效字符进栈,未考虑栈满情形
            }
            ch = getchar(); // 从终端接收下一个字符
        }
        // 将从栈底到栈顶的栈内字符传送至调用过程的数据区;
        ClearStack(S); // 重置S为空栈
        if (ch != EOF)
            ch = getchar();
    }
    DestroyStack(S);
} // LineEdit