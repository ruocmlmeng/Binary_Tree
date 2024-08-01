
#include "SqQueue.h"

SqQueue * InitQueue(void)
{
	SqQueue * q = malloc(sizeof(*q));
	q->elem = malloc(sizeof(QElemType) * MAX_SqQUEUE_NUM );
	q->front = 0;
	q->rear = 0;
	q->num = 0;
	return q;

}

/*
	DestoryQueue: 销毁一个队列
	@q:将要操作的队列的指针
	返回值:无
*/
void DestoryQueue(SqQueue *q)
{
	if(q == NULL)
	{
		return ;
	}
	if(q->elem)
	{
		free(q->elem);
	}
	free(q);

}
/*
	ClearQueue: 销毁一个队列
	@q:将要操作的队列的指针
	返回值:无
*/
void ClearQueue(SqQueue *q)
{
	if(QueueIsEmpty(q))
	{
		return ;
	}
	q->rear =q->front = 0;
	q->num = 0;
}

/*
	QueueIsEmpty: 判断一个队列是否为空
	@q:将要操作的队列的指针
	返回值:
		1 空
		0 非空
*/
int  QueueIsEmpty(SqQueue *q)
{
	if(q==NULL || q->elem == NULL ||q->num == 0)
	{
		return 1;
	}
	return 0;

}
/*
	QueueLength: 队列元素个数
	@q:将要操作的队列的指针
	返回值:

*/
int  QueueLength(SqQueue *q)
{
	if(QueueIsEmpty(q))
	{
		return 0;
	}
	return q->num;

}

/*
	GetHead: 获取对头元素,但不出队
	@q:将要操作的队列的指针
	@d:用来指向保存对头元素值的空间
	返回值:
		1   成功
		0	失败
*/
int  GetHead(SqQueue *q,QElemType * d)
{
	if(QueueIsEmpty(q))
	{
		return 0;
	}
	*d = q->elem[q->front];
	return 1;

}
/*
	DeQueue: 出队
	@q:将要操作的队列的指针
	@d:用来指向保存对头元素值的空间
	返回值:
		1   成功
		0	失败
*/
int  DeQueue(SqQueue *q,QElemType * d)
{
	if(QueueIsEmpty(q))
	{
		return 0;
	}
	*d = q->elem[q->front];
	q->front++;
	if(q->front == MAX_SqQUEUE_NUM)
	{
		q->front = 0;
	}
	q->num--;
	return 1;

}
/*
	EnQueue: 入队
	@q:将要操作的队列的指针
	@d:用来指向保存对头元素值
	返回值:
		1   成功
		0	失败
*/
int  EnQueue(SqQueue *q,QElemType d)
{
	if(q== NULL || q->elem == NULL || q->num == MAX_SqQUEUE_NUM)
	{
		return 0;
	}

	q->elem[q->rear] = d;
	q->rear++;
	if(q->rear == MAX_SqQUEUE_NUM )
	{
		q->rear = 0;
	}
	q->num++;
	return 1;

}



