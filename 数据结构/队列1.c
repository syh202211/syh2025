// ===== ADT Queue 的表示与实现 =====
// ----- 单链队列——队列的链式存储结构 -----
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front; // 队头指针
    QueuePtr rear;  // 队尾指针
} LinkQueue;

// ----- 基本操作的函数原型说明 -----
Status InitQueue(LinkQueue &Q)
    // 构造一个空队列Q
    Status DestroyQueue(LinkQueue &Q)
    // 销毁队列Q，Q不再存在
    Status ClearQueue(LinkQueue &Q)
    // 将Q清为空队列
    Status QueueEmpty(LinkQueue Q)
    // 若队列Q为空队列，则返回TRUE，否则返回FALSE
    int QueueLength(LinkQueue Q)
    // 返回Q的元素个数，即为队列的长度
    Status GetHead(LinkQueue Q, QElemType &e)
    // 若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
    Status EnQueue(LinkQueue &Q, QElemType e)
    // 插入元素e为Q的新的队尾元素
    Status DeQueue(LinkQueue &Q, QElemType &e)
    // 若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；
    // 否则返回ERROR
    Status QueueTraverse(LinkQueue Q, visit())
    // 从队头到队尾依次对队列Q中每个元素调用函数visit()。一旦visit失败,则操作失败。

    // ----- 基本操作的算法描述(部分) -----
    Status InitQueue(LinkQueue &Q)
{
    // 构造一个空队列Q
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(OVERFLOW); // 存储分配失败
    Q.front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue &Q)
{
    // 销毁队列Q
    while (Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e)
{
    // 插入元素e为Q的新的队尾元素
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW); // 存储分配失败
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
    // 若队列不空,则删除Q的队头元素,用e返回其值,并返回OK;
    // 否则返回ERROR
    if (Q.front == Q.rear)
        return ERROR;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return OK;
}