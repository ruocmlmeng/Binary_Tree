

#ifndef __SqQueue_H__
#define __SqQueue_H__
#include<stdio.h>
#include<stdlib.h>
#include"bitree.h"
typedef biNode* QElemType;
#define MAX_SqQUEUE_NUM 20
typedef struct SqQueue
{
	QElemType * elem;
	int rear;
	int front;
	int num;
}SqQueue;

SqQueue * InitQueue(void);

void DestoryQueue(SqQueue *q);

void ClearQueue(SqQueue *q);

int  QueueIsEmpty(SqQueue *q);

int  QueueLength(SqQueue *q);

int  GetHead(SqQueue *q,QElemType * d);

int  DeQueue(SqQueue *q,QElemType * d);

int  EnQueue(SqQueue *q,QElemType   d);


#endif
