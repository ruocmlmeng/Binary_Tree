
#ifndef __BalanceTree_H__
#define __BalanceTree_H__
#define MAX(a,b) (a) > (b) ? (a) : (b)

#include<stdio.h>
#include<stdlib.h>

typedef char TElemType;

typedef struct biNode
{
	TElemType data;
	
	struct biNode * lchild;
	struct biNode * rchild;	

	//保存以当前结点为根的这棵树的高度
	int height;
}biNode;


int Get_Height(biNode * root);

biNode * Create_BalanceTree(void);

biNode * Insert(biNode * root ,biNode * p);

void Pre_Order(biNode * root);

void Mid_Order(biNode * root);

void last_Order(biNode * root);
#endif