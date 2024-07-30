
#include "bitree.h"

/*
	Create_Tree:根据用户输入创建一棵二叉排序树
	返回值：
		返回创建的排序二叉树的根节点的指针
*/

biNode * Create_Tree(void)
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
		//将p插入到二叉排序树root中，使其插入 后任然有序
		root = Insert_Node(root, p);
	}
	return root;
}

/*
	Insert_biNode://将p插入到二叉排序树root中，使其插入 后任然有序
	@root:指向二叉排序树的根节点
	@p：待插入的结点
	返回值:
		返回二叉排序树的根节点指针
*/
biNode * Insert_biNode(biNode * root, biNode * p)
{
	if(root == NULL)
	{
		//此时p将作为根节点
		return p;
	}
	if(p == NULL )
	{
		return root;
	}

	//查找待插入的位置
	biNode * pk = root; //搜索路径上需要比较的结点
	biNode * pf = NULL; // 记录pk的父节点
	while(pk)
	{
		pf = pk;
		if(p->data > pk->data)
		{
			//往右走
			pk = pk->rchild;
			
		}
		else if(p->data < pk->data)
		{
			//往左走
			pk = pk->lchild;
		}
		else
		{
			//相等的情况,则直接退出
			return root;
		}
	}
	//当循环结束,则pf指向了待插入元素p的父节点
	
	//进行插入操作
	if(pf->data > p->data)
	{
		pf->lchild = p;
	}
	else if( pf->data < p->data)
	{
		pf->rchild = p;
	}

	return root;

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
/*
	Get_Tree_Hight:求二叉树的高度
	@root:二叉树的根节点
	返回值:
		树的高度
*/
int Get_Tree_Hight(biNode * root)
{
	if(root == NULL)
	{
		return 0;
	}
	int leftHight = Get_Tree_Hight(root->lchild);
	int rightHight = Get_Tree_Hight(root->rchild);

	return (leftHight > rightHight ? leftHight : rightHight ) + 1;
	

}

/*
	Insert_Node:用递归的方式,实现插入一个结点,保持二叉排序树的排序性
	@root:根结点指针
	@p:待插入的结点
	返回值:
		根结点指针
*/
biNode * Insert_Node(biNode * root ,biNode * p)
{
	if(root == NULL)
	{
		return p;
	}

	if(p->data < root->data)
	{
		root->lchild = Insert_Node(root->lchild,p);
	}
	else if(p->data > root->data)
	{
		root->rchild = Insert_Node(root->rchild,p);
	}
	return root;
}



/*
	Delete_X:删除一棵二叉排序树中的一个结点(数据域为X)
	@root:指向你要操作的那棵树
	@x:你要删除的那个结点的数据域
	返回值:
		返回删除之后的二叉排序树的根节点
*/

biNode* Delete_X(biNode * root, TElemType x)
{
	if(root == NULL)
	{
		return NULL;
	}
	//首先要先找到你要删除结点的位置在哪
	biNode * pf = NULL;//要删除结点的父结点
	biNode * px = root;//找到要删除结点的位置
	while(px)
	{
		//父结点紧紧跟着

		if( x > px->data )
		{
			pf = px;
			px = px->rchild;
		}
		else if(x < px->data )
		{
			pf = px;
			px = px->lchild;
		}
		else
		{
			//找到了
			break;
		}
	}

	//如果是没有找到退出了循环
	if(px == NULL)
	{
		return root;
	}
Delete_PX:

	//中途找到了要删除的结点,那么就要删除结点,分三种情况
	if(px->lchild == NULL && px->rchild == NULL)//删除叶子节点(度为0的结点)
	{
		//就只有一个根节点
		if(px == root)
		{
			root = NULL;
			free(px);
			return root;
		}
		//有其它的根结点
		if(px->data > pf->data)
		{
			//px为pf的右孩子
			pf->rchild = NULL;
			free(px);
		}
		else if(px->data < pf->data)
		{
			//px为pf的左孩子
			pf->lchild = NULL;
			free(px);
		}
		return root;
	}
	else if(px->lchild && px->rchild)//删除度为2的结点
	{
		printf("%d\n",__LINE__);
		//找"替罪羔羊"
		biNode * p = px;
		//先左转找左边的最大值
		pf = px;
		px = px->lchild;
		//再一直右转
		while(px->rchild)
		{
			printf("%d\n",__LINE__);
			pf = px;
			px = px->rchild;
		}
		//转出来之后就是找到了
		p->data = px->data;
		px->data = x;
		printf("%d\n",__LINE__);
		goto Delete_PX;


		//找右边的最小值
	}
	else//删除度为1的结点
	{
		//如果要删除的结点是根节点上的左右孩子,并且整个树只有这两个结点
		//就是要删除的是根节点
		if(px == root)
		{
			if(px->lchild->data < root->data)
			{
				root = px->lchild;
				px->lchild = NULL;
			}
			else if(px->rchild->data > root->data)
			{
				root = px->rchild;
				px->rchild = NULL;
			}
			free(px);
			return root;
		}
		
		if(px->data > pf->data)
		{
			//px为pf的右孩子
			if(x > px->lchild->data)
			{
				//px有左孩子
				pf->rchild = px->lchild;
			}
			else if(x < px->rchild->data)
			{
				//px有右孩子
				pf->rchild = px->rchild;
			}
			px->rchild = NULL;
			free(px);
		}
		else if(px->data < pf->data)
		{
			//px为pf的左孩子
			if(x > px->lchild->data)
			{
				//px有左孩子
				pf->lchild = px->lchild;
			}
			else if(x < px->rchild->data)
			{
				//px有右孩子
				pf->lchild = px->rchild;
			}
			px->lchild = NULL;
			free(px);
		}
		return root;
	}

	
}


