
#include "bitree.h"
#include "LinkStack.h"
#include "SqQueue.h"
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
	Get_Tree_Height:求二叉树的高度
	@root:二叉树的根节点
	返回值:
		树的高度
*/
int Get_Tree_Height(biNode * root)
{
	if(root == NULL)
	{
		return 0;
	}
	int leftHight = Get_Tree_Height(root->lchild);
	int rightHight = Get_Tree_Height(root->rchild);

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
		//px->data = x;
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

/*
	Levle_Order:层次遍历
*/
void Levle_Order(biNode * root)
{
	if(root == NULL)
	{
		return ;
	}
	//初始化一个队列
	SqQueue * q = InitQueue();
	//将根节点的指针入队
	EnQueue(q, root);

	while(!QueueIsEmpty(q))
	{
		QElemType d;
		DeQueue(q,&d);
		printf("%c ",d->data);
		//然后再看要出队的结点是否有左右孩子
		if(d->lchild)
		{
			EnQueue(q, d->lchild);
		}
		if(d->rchild)
		{
			EnQueue( q, d->rchild);
		}
	}
	DestoryQueue(q);
}

/*
	Pre_Stack_Order: 用栈的方式,实现先序遍历
	@root:根节点的指针
*/
void Pre_Stack_Order(biNode * root)
{
	if(root == NULL)
	{
		return ;
	}
	//初始化一个栈
	LStack * s = InitStack();
	//将根节点的指针入栈
	printf("%c ",root->data);
	Push(s, root);
	
	//判断栈是否为空
	while( !StackIsEmpty(s))
	{
        // 先处理左子树
        while ( root->lchild != NULL)
        {
            root = root->lchild;
            Push(s, root);  // 将左子节点入栈
            printf("%c ", root->data);  // 打印左子节点数据
        }
        
        // 处理右子树
		while(!StackIsEmpty(s))
        {    Pop(s, &root);
            if (root->rchild != NULL)
            {
                root = root->rchild; 
                Push(s, root);  // 将右子节点入栈
                printf("%c ", root->data);  // 打印右子节点数据
				break;
            }
		}
	}
	
}

/*
	mid_Stack_Order:使用非递归的方法实现，中序遍历(栈)
   	约定任何元素出栈栈的时候先打印
   	@root:根节点的指针
*/
void mid_Stack_Order(biNode * root)
{
	if(root == NULL)
	{
		return ;
	}

	//初始化一个栈
	LStack* s = InitStack();
	// 遍历过程
    while (root != NULL || !StackIsEmpty(s))
    {
        // 处理左子树，将所有左子节点压入栈
        while (root != NULL)
        {
            Push(s, root);
            root = root->lchild;
        }
        
        // 栈顶元素出栈并打印
        if (!StackIsEmpty(s))
        {
            Pop(s, &root);
            printf("%c ", root->data);  // 打印节点数据
            
            // 处理右子树
            root = root->rchild;
        }
    }

}
/*
void Pre_Order_Fei(biNode * root)
{
	if(root == NULL)
	{
		return ;
	}

	//初始化一个栈
	LStack * s =  InitStack();

	biNode * p = root;
	while(p || !StackIsEmpty(s))
	{
		while(p)
		{
			printf("%c ",p->data);
			//改数据的类型biNode*
			Push(s, p);
			p = p->lchild;
		}

		if(!StackIsEmpty(s))
		{
			Pop(s, &p);
			p = p->rchild;
		}

	}
	printf("\n");
	DestroyStack(s);
}

void Mid_Order_Fei(biNode * root)
{
	if(root == NULL)
	{
		return ;
	}

	//初始化一个栈
	LStack * s =  InitStack();

	biNode * p = root;
	while(p || !StackIsEmpty(s))
	{
		while(p)
		{

			//改数据的类型biNode*
			Push(s, p);
			p = p->lchild;
		}

		if(!StackIsEmpty(s))
		{
			Pop(s, &p);
			printf("%c ",p->data);
			p = p->rchild;
		}

	}
	printf("\n");
	DestroyStack(s);
}

void Back_Order_Fei(biNode * root)
{

	if(root == NULL)
	{
		return ;
	}
	LStack * s1 = InitStack();
	LStack * s2 = InitStack();
	
	//先让根节点的指针Push => s1
	biNode * p =root;
	Push(s1,p);
	while(!StackIsEmpty(s1))
	{
		Pop(s1,&p);
		//将s1的栈顶元素,加入到s2中去
		Push(s2, p);

		//依次将s1的栈顶元素的左孩子和右孩子,分别Push到s1
		if(p->lchild)
		{
			Push(s1,p->lchild);
		}
		if(p->rchild)
		{
			Push(s1,p->rchild);
		}
	}
	while(!StackIsEmpty(s2))
	{
		Pop(s2, &p);
		printf("%c ",p->data);
	}
	printf("\n");
	DestroyStack(s1);
	DestroyStack(s1);
}
*/
void Pre_Order_Feidigui(biNode * root)
{
	if(root == NULL)
	{
		return ;
	}

	//初始化一个栈
	LStack * s =InitStack();
	//初始化一个指向根节点的指针
	biNode * p = root;
	while(p || !StackIsEmpty(s))
	{
		while(p)
		{
			printf("%c ",p->data);
			Push(s, p);
			p = p->lchild;
		}

		if(!StackIsEmpty(s))
		{
			Pop(s, &p);
			p = p->rchild;
		}
	}
	printf("\n");
	DestroyStack(s);
	
}
void Mid_Order_Feidigui(biNode * root)
{
	if(root == NULL)
	{
		return ;
	}

	//初始化一个栈
	LStack * s =InitStack();
	//初始化一个指向根节点的指针
	biNode * p = root;
	while(p || !StackIsEmpty(s))
	{
		while(p)
		{

			Push(s, p);
			p = p->lchild;
		}

		if(!StackIsEmpty(s))
		{
			Pop(s, &p);
			printf("%c ",p->data);
			p = p->rchild;
		}
	}
	printf("\n");
	DestroyStack(s);
	
}

void Last_Order_Feidigui(biNode * root)
{
	if(root == NULL)
	{
		return ;
	}
	//初始化两个栈
	LStack * s1 = InitStack();
	LStack * s2 = InitStack();

	//定义一个指向根结点的指针
	biNode * p = root;
	Push(s1, p);
	while(!StackIsEmpty(s1))
	{
		Pop(s1, &p);
		Push(s2, p);
		if(p->lchild)
		{
			Push(s1, p->lchild);
		}
		if(p->rchild)
		{
			Push(s1, p->rchild);
		}

	}
	while(!StackIsEmpty(s2))
	{
		Pop(s2, &p);
		printf("%c ",p->data);
	}
	printf("\n");
	DestroyStack(s1);
	DestroyStack(s2);
}

/*
	Is_wanquanTree:判断一棵树是否为完全二叉树
	@root：二叉树的根结点的指针
	返回值:
		1 完全二叉树
		0 非完成二叉树
		-1 空树
*/


/*
	Is_WanquanTree : 判断一棵二叉树是否为完全二叉树
	@root:二叉树的根结点的指针
	返回值:
		1 是完全二叉树
		0 非完全二叉树
	   -1 二叉树不存在
*/
int Is_WanquanTree(biNode *root)
{
	if(root == NULL)
	{
		
		return -1;//二叉树不存在
	}

	//初始化一个队列
	SqQueue * q = InitQueue();

	//将根结点入队
	biNode * p = root;
	EnQueue(q, p);

	//定义一个标记
	int flag = 0 ; //0 没有找到第一个非满结点
				   //1 找到了第一个非满结点
	while(!QueueIsEmpty(q))
	{
		//出队
		DeQueue(q, &p);

		//进入if那就说明是第一个非满结点了
		if(flag)
		{
			//判断p是否为叶子结点
			if(p->lchild  || p->rchild)
			{
				//不是叶子结点
				DestoryQueue(q);
				return 0;//非完全二叉树
			}
			
		}
		else
		{
			//判断p是不是第一个非满结点
			if(p->lchild==NULL  || p->rchild==NULL)
			{
				flag = 1;
				if(p->rchild)
				{
					DestoryQueue(q);
					return 0;//非完全二叉树
				}
			}
		}
		//将出队元素左孩子入队
		if(p->lchild)
		{
			EnQueue(q, p->lchild);
		}
		//将出队元素右孩子入队
		if(p->rchild)
		{
			EnQueue(q, p->rchild);
		}


	}
	//销毁队列
	DestoryQueue(q);
	return 1;//完全二叉树

}


/*
int Is_WanquanTree(biNode *root)
{
	if(root == NULL)
	{
		printf("此二叉树不存在!\n");
		return -1;
	}

	int flag = 0;	
	//初始化一个队列
	SqQueue * q = InitQueue();

	//将根结点的指针入队
	biNode * p =root;
	EnQueue(q, p);
	while(!QueueIsEmpty(q))
	{
		//出队给p
		DeQueue(q, &p);
		if(flag)
		{
			//判断是否为叶子结点
			if(p->rchild || p->lchild)
			{
				//不是叶子结点则直接退出
				return 0;//非完全二叉树
			}
			
		}
		else
		{
			//判断p是不是第一个非满结点
			if(p->lchild == NULL || p->rchild == NULL)
			{
				flag = 1;
				if(p->rchild)
				{
					return 0;
				}
			}
		}

		if(p->lchild)
		{
			EnQueue( q, p->lchild);
		}
		if(p->rchild)
		{
			EnQueue(q, p->rchild);

		}
	}
	DestoryQueue(q);
	return 1;
}
*/