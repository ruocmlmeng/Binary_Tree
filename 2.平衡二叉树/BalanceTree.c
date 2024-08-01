
#include "BalanceTree.h"

int Get_Height(biNode * root)
{
	if(root == NULL)
	{
		return 0;
	}
	return root->height;

}
/*
	单项左旋
*/
static biNode* SingleRotateWithLeft(biNode * k2)
{
	biNode * k1 = k2->rchild;
	k2->rchild = k1->lchild;
	k1->lchild = k2;
	//重新计算k2,k1的高度
	k2->height = MAX(Get_Height(k2->lchild), Get_Height(k2->rchild)) +1;
	k1->height = MAX(Get_Height(k1->lchild), Get_Height(k1->rchild)) +1;
	return k1;
}
/*
	单项右旋
*/
static biNode* SingleRotateWithRight(biNode * k2)
{
	biNode * k1 = k2->lchild;
	k2->lchild = k1->rchild;
	k1->rchild = k2;
	//重新计算k2,k1的高度
	k2->height = MAX(Get_Height(k2->lchild), Get_Height(k2->rchild)) +1;
	k1->height = MAX(Get_Height(k1->lchild), Get_Height(k1->rchild)) +1;
	return k1;
}

/*
	Create_BalanceTree:根据用户输入创建一棵平衡二叉排序树
	返回值：
		返回创建的平衡二叉树的根节点的指针
*/

biNode * Create_BalanceTree(void)
{


	biNode * root = NULL;
	TElemType d;
	while(1)
	{
		scanf("%c",&d);
		if(d == '#')
		{
			break;
		}

		biNode * p = malloc(sizeof(biNode));
		p->data = d;
		p->lchild = NULL;
		p->rchild = NULL;
		p->height = 1;
		//将p插入到平衡二叉树root中，使其插入 后任然平衡有序
		root = Insert(root, p);
	}
	return root;
}

/*
	Insert : 将p插入到root指向的平衡二叉树中去
	返回值：
		返回插入之后平衡二叉树的根节点的指针
*/
biNode * Insert(biNode * root ,biNode * p)
{
	if(root == NULL)
	{
		return p;
	}
	if(p == NULL)
	{
		return root;
	}
	if(p->data > root->data)
	{
		//插入右子树
		root->rchild = Insert(root->rchild,p);
		//重新计算每一个接待你的高度
		root->height = MAX(Get_Height(root->lchild),Get_Height( root->rchild)) + 1;

		//判断这棵树是否平衡
		if(abs(Get_Height(root->lchild) -Get_Height( root->rchild) ) > 1)
		{
			//不平衡了,需要对root进行平衡处理

			//怎么不平衡
			if(p->data > root->rchild->data)
			{
				//往不平衡结点的右子节点的右边插入 导致 不平衡
				// => "单向左旋"
				//root不平衡
				root = SingleRotateWithLeft(root);

			}
			else
			{
				//往不平衡结点的右子节点的左边插入 导致 不平衡
				//双向旋转 先右后左
				//先对不平衡结点的右子节(root->rchild)点进行 单向右旋
				root->rchild = SingleRotateWithRight(root->rchild);
				//再对不平衡的
				root = SingleRotateWithLeft(root);

			}
		}
		return root;
	}
	else if(p->data < root->data)
	{
		//插入左子树
		root->lchild = Insert(root->lchild,  p);
		//重新计算每一个接待你的高度
		root->height = MAX(Get_Height(root->lchild),Get_Height( root->rchild)) + 1;
		//判断这棵树是否平衡
		if(abs(Get_Height(root->lchild) - Get_Height(root->rchild)) > 1)
		{
			//不平衡了 ,需要对root进行平衡处理
			//怎么不平衡了,又要进行判断
			if(p->data > root->lchild->data)
			{
				//往不平衡结点的左子结点的左边插入 导致不平衡
				//=> 单向右旋
				root = SingleRotateWithRight(root);
			}
			else
			{
				//往不平衡节点的左子结点的右边插入 导致 不平衡
				//双向旋转 先左后右
				//先左旋转
				root->lchild = SingleRotateWithLeft(root->lchild);
				//再右旋
				root = SingleRotateWithRight(root);
			}

		}
		return root;
	}
	else
	{
		//相等
		return root;
	}
}

/*
	先序遍历
*/
void Pre_Order(biNode * root)
{
	if(root == NULL)
	{
		return ;
	}
	//1.打印根节点
	printf("%c ",root->data);

	//2.以先序遍历的规则,去遍历根的左子树
	Pre_Order(root->lchild);

	//3.以先序遍历的规则,去遍历根的右子树
	Pre_Order(root->rchild);

}
/*
	中序遍历
*/
void Mid_Order(biNode * root)
{
	if(root == NULL)
	{
		return ;
	}
	//1.以先序遍历的规则,去遍历根的左子树
	Mid_Order(root->lchild);
	
	//2.打印根节点
	printf("%c ",root->data);


	//3.以先序遍历的规则,去遍历根的右子树
	Mid_Order(root->rchild);

}
/*
	后序遍历
*/
void last_Order(biNode * root)
{
	if(root == NULL)
	{
		return ;
	}
	//1.以先序遍历的规则,去遍历根的左子树
	last_Order(root->lchild);

	

	//2.以先序遍历的规则,去遍历根的右子树
	last_Order(root->rchild);
	
	//3.打印根节点
	printf("%c ",root->data);


}


