do
{
    若当前位置可通，
    则{将当前位置插入栈顶；             // 纳入路径
           若该位置是出口位置，则结束； // 求得路径存放在栈中
               否则切换当前位置的东邻方块为新的当前位置；} 否则，
        若栈不空且栈顶位置尚有其他方向未经探索，
            则设定新的当前位置为沿顺时针方向旋转找到的栈顶位置的下一相邻块；
                若栈不空但栈顶位置的四周均不可通， 则
    {
        删去栈顶位置； // 从路径中删去该通道块
            若栈不空，则重新测试新的栈顶位置， 直至找到一个可通的相邻块或出栈至栈空；
    }
} while (栈不空)；

    typedef struct
{
    int ord;      // 通道块在路径上的"序号"
    PosType seat; // 通道块在迷宫中的"坐标位置"
    int di;       // 从此通道块走向下一通道块的"方向"
} SElemType;      // 栈的元素类型

Status MazePath(MazeType maze, PosType start, PosType end)
{
    // 若迷宫maze中存在从入口start到出口end的通道,则求得一条存放在栈中(从栈底到栈顶),并返回TRUE;否则返回FALSE
    InitStack(S);
    curpos = start; // 设定"当前位置"为"入口位置"
    curstep = 1;    // 探索第一步
    do
    {
        if (Pass(curpos))
        {                      // 当前位置可以通过,即是未曾走到过的通道块
            FootPrint(curpos); // 留下足迹
            e = (curstep, curpos, 1);
            Push(S, e); // 加入路径
            if (curpos == end)
                return (TRUE);           // 到达终点(出口)
            curpos = NextPos(curpos, 1); // 下一位置是当前位置的东邻
            curstep++;                   // 探索下一步
        } // if
        else
        { // 当前位置不能通过
            if (!StackEmpty(S))
            {
                Pop(S, e);
                while (e.di == 4 && !StackEmpty(S))
                {
                    MarkPrint(e.seat);
                    Pop(S, e); // 留下不能通过的标记,并退回一步
                } // while
                if (e.di < 4)
                {
                    e.di++;
                    Push(S, e);                    // 换下一个方向探索
                    curpos = NextPos(e.seat e.di); // 设定当前位置是该新方向上的相邻块
                } // if
            } // if
        } // else
    } while (!StackEmpty(S));
    return (FALSE);
} // MazePath