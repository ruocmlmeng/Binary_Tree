

#ifndef __bitree_H__
#define __bitree_H__
#include<stdio.h>
#include<stdlib.h>

typedef char TElemType;

typedef struct biNode
{
	TElemType data;
	struct biNode * lchild;
	struct biNode * rchild;	
}biNode;

biNode * Create_Tree(void);

biNode * Insert_biNode(biNode * root, biNode * p);

void Pre_Order(biNode * root);

void Mid_Order(biNode * root);

void last_Order(biNode * root);

int Get_Tree_Hight(biNode * root);

biNode * Insert_Node(biNode * root ,biNode * p);

biNode* Delete_X(biNode * root, TElemType x);

#endif