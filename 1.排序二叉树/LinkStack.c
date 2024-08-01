

#include "LinkStack.h"


#include <stdio.h>
#include <stdlib.h>

LStack * InitStack(void)
{
	LStack * l = malloc(sizeof(*l));
	l->bottom = l->top = NULL;
	l->num = 0;
	return l;
}
void DestroyStack(LStack * l)
{
	if(l == NULL)
	{
		return ;
	}
	ClearStack(l);
	free(l);
}
void ClearStack(LStack * l)
{
	if(StackIsEmpty(l))
	{
		return ;
	}

	while(l->top)
	{
		LNode * px = l->top;

		l->top = px->next;
		px->next = NULL;
		
		if(l->top)
			l->top->prev = NULL;
		else 
			l->bottom = NULL;

		free(px);
	}

	l->num = 0; 
}

int StackIsEmpty(LStack * l)
{
	if(l == NULL || l->top == NULL)
	{
		return 1;
	}
	return 0;
}


int GetTop(LStack * l, LElemType * d)
{
	if(StackIsEmpty(l) )
	{
		return 0;
	}

	*d = l->top->data;
	
	return 1;
}
int Pop(LStack * l, LElemType * d)
{
	if(StackIsEmpty(l) )
	{
		return 0;
	}

	//备份数据
	*d = l->top->data;

	//干掉栈顶元素
	LNode * p = l->top;
	l->top = l->top->next;
	p->next = NULL;
	if(l->top)
		l->top->prev = NULL;
	else 
		l->bottom = NULL;
	free(p);

	l->num--;
	return 1;
}	
int Push(LStack * l, LElemType d)
{
	if(l == NULL)
	{
		return 0;
	}

	LNode * p = malloc(sizeof(*p));
	p->data = d;
	p->next = NULL;
	p->prev = NULL;

	if(StackIsEmpty(l))
	{
		l->top = p;
		l->bottom = p;
	}
	else 
	{
		//头插法
		l->top->prev = p;
		p->next = l->top;
		l->top = p;		
	}
	l->num ++;

	return 1;
}


int StackLength(LStack * l)
{
	if(StackIsEmpty(l))
	{
		return 0;
	}
	return l->num;
}






