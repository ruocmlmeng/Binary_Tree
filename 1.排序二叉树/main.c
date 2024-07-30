
#include"bitree.h"

void Print_Tree(biNode * root)
{
	printf("先序遍历:");
	Pre_Order(root);
	printf("\n");
	printf("中序遍历:");
	Mid_Order(root);
	printf("\n");
	printf("后序遍历:");
	last_Order(root);
	printf("\n");

}
int main()
{
	biNode * root = Create_Tree();

	//int hight = Get_Tree_Hight(root);
	//printf("树的高度为:%d\n",hight);

	Print_Tree(root);
	getchar();
	TElemType d;
	scanf("%c",&d);
	root = Delete_X(root, d);
	
	Print_Tree(root);

	return 0;
}
