

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

int Get_Tree_Height(biNode * root);

biNode * Insert_Node(biNode * root ,biNode * p);

biNode* Delete_X(biNode * root, TElemType x);

void Levle_Order(biNode * root);

/*
	Pre_Stack_Order: 用栈的方式,实现先序遍历
	@root:根节点的指针
*/
void Pre_Stack_Order(biNode * root);

/*
	mid_Stack_Order:使用非递归的方法实现，中序遍历(栈)
   	约定任何元素出栈栈的时候先打印
   	@root:根节点的指针
*/
void mid_Stack_Order(biNode * root);

//作业5 6 7 8
void Pre_Order_Fei(biNode * root);

void Mid_Order_Fei(biNode * root);

void Back_Order_Fei(biNode * root);

//作业重写
void Pre_Order_Feidigui(biNode * root);
void Mid_Order_Feidigui(biNode * root);
void Last_Order_Feidigui(biNode * root);
int Is_WanquanTree(biNode *root);

#endif