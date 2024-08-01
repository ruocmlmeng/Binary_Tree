
#include"bitree.h"
#include"SqQueue.h"
#include "LinkStack.h"

void Print_Tree(biNode * root)
{
	printf("先序遍历:");
	Pre_Order_Feidigui(root);
	printf("\n");
	printf("中序遍历:");
	Mid_Order_Feidigui(root);
	printf("\n");
	printf("后序遍历:");
	Last_Order_Feidigui(root);
	printf("\n");
	printf("层次遍历:");
	Levle_Order(root);
	printf("\n");

}
int main()
{
	biNode * root = Create_Tree();

	//int hight = Get_Tree_Hight(root);
	//printf("树的高度为:%d\n",hight);
	int res = Is_WanquanTree(root);
	if(res == 1)
	{
		printf("是完全二叉树!\n");
	}
	else if(res == 0)
	{
		printf("不是完全二叉树!\n");
	}
	else if(res == -1)
	{
		printf("是空树!\n");
	}

	Print_Tree(root);
	//getchar();
	//TElemType d;
	//scanf("%c",&d);
	//root = Delete_X(root, d);
	
	//Print_Tree(root);

	return 0;
}
