
#include"BalanceTree.h"
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
	biNode * root = Create_BalanceTree();
	Print_Tree(root);
	return 0;
}

