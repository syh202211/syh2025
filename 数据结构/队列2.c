// ----- 循环队列——队列的顺序存储结构 -----
#define MAXQSIZE 100 // 最大队列长度
typedef struct
{
    QElemType *base; // 初始化的动态分配存储空间
    int front;       // 头指针,若队列不空,指向队列头元素
    int rear;        // 尾指针,若队列不空,指向队列尾元素的下一个位置
} SqQueue;

// ----- 循环队列的基本操作的算法描述 -----
Status InitQueue(SqQueue &Q)
{
    // 构造一个空队列Q
    Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base)
        exit(OVERFLOW); // 存储分配失败
    Q.front = Q.rear = 0;
    return OK;
}

int QueueLength(SqQueue Q)
{
    // 返回Q的元素个数,即队列的长度
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}