#include<iostream>
#include<stack>
using namespace std;

/*
构造二叉树，输入 A,B,C,D,E,@,F,@,@,G,H,#
其中@表示空，#表示二叉树结束
*/
#define maxsize 10
#define NULL 0

typedef struct node{
	char data;
	struct node *lchild, *rchild;
}Bitree;

Bitree *Q[maxsize]; //队列Q为指针类型

//建立二叉树，返回根指针
Bitree *creatree()
{
	char ch;
	int front, rear;
	Bitree *T, *s;   
    T = NULL;    //空二叉树
	front = 1;
	rear = 0;
	ch = getchar();
	while (ch != '#')
	{
		s = NULL; //如果输入的是虚节点，则无需为虚节点申请空间
		//不是虚节点，建立新结点
		if (ch != '@')
		{
			s = (Bitree *)malloc(sizeof(Bitree));
			s->data = ch;
			s->lchild = s->rchild = NULL;
		}
		rear++;
		//将虚节点指针NULL或新结点地址入队
		Q[rear] = s;
		if (rear == 1)
			T = s;
		else
		{
			if (s != NULL && Q[front] != NULL)
			{
				if (rear % 2 == 0)
					Q[front]->lchild = s;
				else
					Q[front]->rchild = s;	
			}
			if (rear % 2 == 1)
				front++;
		}
		ch = getchar();
	}
	return T;
}

/*
递归实现方法：
*/

//前序
void pre_order(Bitree *T)
{
	if (T)
	{
		cout << T->data;
		pre_order(T->lchild);
		pre_order(T->rchild);
	}
}

//中序
void in_order(Bitree *T)
{
	if (T)
	{
		in_order(T->lchild);
		cout << T->data;
		in_order(T->rchild);
	}
}

//后序
void beh_order(Bitree *T)
{
	if (T)
	{
		beh_order(T->lchild);
		beh_order(T->rchild);
		cout << T->data;
	}
}

/*
	循环实现
*/

//前序
void preorder(Bitree *T)
{
	Bitree *Cur = T;
	stack <Bitree *> s;
	
	//直到当前结点为NULL且栈空，结束循环
	while (Cur != NULL || !s.empty())
	{
		//如果左孩子不为空；
		if (Cur != NULL)
		{
			//输出，入栈，判断左孩子
			cout << Cur->data;
			s.push(Cur);
			Cur = Cur->lchild;
		}
		//若左海子为空，出栈，判断右孩子
		else
		{
			Cur = s.top();
			s.pop();
			Cur = Cur->rchild;
		}
	}
}

//中序

void inorder(Bitree *T)
{
	Bitree *Cur=T;
	stack <Bitree *> s;
	//直到当前结点为NULL且栈空，结束循环
	while (Cur != NULL || !s.empty())
	{
		//若左孩子不为空，入栈
		if (Cur != NULL)
		{
			s.push(Cur);
			Cur = Cur->lchild;
		}
		//若左孩子为空，输出，出栈，判断右孩子
		else
		{
			Cur = s.top();
			cout << Cur->data;
			s.pop();
			Cur = Cur->rchild;
		}
	}
}
//后序
void behorder(Bitree *T)
{
	stack<Bitree *> s;
	Bitree *Cur;
	Bitree *Pre = NULL;
	//先将树根结点入栈
	s.push(T);

	//直到栈空，结束循环
	while (!s.empty())
	{
		//当前结点始终指向栈顶
		Cur = s.top();
		//如果当前结点无左右孩子，或有左孩子或右孩子且已经输出，打印，出栈，将Pre设为当前结点
		if ((Cur->lchild == NULL && Cur->rchild == NULL) || (Pre != NULL && (Pre == Cur->lchild || Pre == Cur->rchild)))
		{
			cout << Cur->data;
			s.pop();
			Pre = Cur;
		}
		//若有左右孩子，则按照右孩子->左孩子顺序入栈
		else
		{
			if (Cur->rchild!=NULL)
				s.push(Cur->rchild);
			if (Cur->lchild != NULL)
				s.push(Cur->lchild);
		}
	}
}





int main(){
	Bitree *T;
	T=creatree();
	cout << "前序遍历：";
	//pre_order(T);
	preorder(T);
	cout << '\n' << "中序遍历：";
	//in_order(T);
	inorder(T);
	cout << '\n' << "后序遍历：";
	//beh_order(T);
	behorder(T);
	cout << endl;
	return 0;
}








