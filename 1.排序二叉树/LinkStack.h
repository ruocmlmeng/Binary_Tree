
#ifndef __LinkStack_H__
#define __LinkStack_H__

#include<stdio.h>
#include<stdlib.h>
#include "bitree.h"
typedef biNode* LElemType; //栈中元素的类型

//链式栈，数据结点 
typedef struct lnode
{
    //数据域，来保存栈中元素
    LElemType  data;
    
    //指针域
    struct lnode * next; //指向下一个数据结点
    struct lnode * prev; //指向上一个数据结点
}LNode;

//栈的类型 
typedef struct lstack
{
    LNode * top; //指向栈顶的指针
    LNode * bottom; //指向栈底的指针 
    int num; //记录栈中元素个数
    // ......
}LStack;


LStack * InitStack(void);
void DestroyStack(LStack * l);
void ClearStack(LStack * l);
int StackIsEmpty(LStack * l);
int StackLength(LStack * l);
int GetTop(LStack * l, LElemType * d);
int Pop(LStack * l, LElemType * d);
int Push(LStack * l, LElemType d);



#endif 




