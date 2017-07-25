#include<iostream>
#include<stack>
using namespace std;

/*
��������������� A,B,C,D,E,@,F,@,@,G,H,#
����@��ʾ�գ�#��ʾ����������
*/
#define maxsize 10
#define NULL 0

typedef struct node{
	char data;
	struct node *lchild, *rchild;
}Bitree;

Bitree *Q[maxsize]; //����QΪָ������

//���������������ظ�ָ��
Bitree *creatree()
{
	char ch;
	int front, rear;
	Bitree *T, *s;   
    T = NULL;    //�ն�����
	front = 1;
	rear = 0;
	ch = getchar();
	while (ch != '#')
	{
		s = NULL; //������������ڵ㣬������Ϊ��ڵ�����ռ�
		//������ڵ㣬�����½��
		if (ch != '@')
		{
			s = (Bitree *)malloc(sizeof(Bitree));
			s->data = ch;
			s->lchild = s->rchild = NULL;
		}
		rear++;
		//����ڵ�ָ��NULL���½���ַ���
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
�ݹ�ʵ�ַ�����
*/

//ǰ��
void pre_order(Bitree *T)
{
	if (T)
	{
		cout << T->data;
		pre_order(T->lchild);
		pre_order(T->rchild);
	}
}

//����
void in_order(Bitree *T)
{
	if (T)
	{
		in_order(T->lchild);
		cout << T->data;
		in_order(T->rchild);
	}
}

//����
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
	ѭ��ʵ��
*/

//ǰ��
void preorder(Bitree *T)
{
	Bitree *Cur = T;
	stack <Bitree *> s;
	
	//ֱ����ǰ���ΪNULL��ջ�գ�����ѭ��
	while (Cur != NULL || !s.empty())
	{
		//������Ӳ�Ϊ�գ�
		if (Cur != NULL)
		{
			//�������ջ���ж�����
			cout << Cur->data;
			s.push(Cur);
			Cur = Cur->lchild;
		}
		//������Ϊ�գ���ջ���ж��Һ���
		else
		{
			Cur = s.top();
			s.pop();
			Cur = Cur->rchild;
		}
	}
}

//����

void inorder(Bitree *T)
{
	Bitree *Cur=T;
	stack <Bitree *> s;
	//ֱ����ǰ���ΪNULL��ջ�գ�����ѭ��
	while (Cur != NULL || !s.empty())
	{
		//�����Ӳ�Ϊ�գ���ջ
		if (Cur != NULL)
		{
			s.push(Cur);
			Cur = Cur->lchild;
		}
		//������Ϊ�գ��������ջ���ж��Һ���
		else
		{
			Cur = s.top();
			cout << Cur->data;
			s.pop();
			Cur = Cur->rchild;
		}
	}
}
//����
void behorder(Bitree *T)
{
	stack<Bitree *> s;
	Bitree *Cur;
	Bitree *Pre = NULL;
	//�Ƚ����������ջ
	s.push(T);

	//ֱ��ջ�գ�����ѭ��
	while (!s.empty())
	{
		//��ǰ���ʼ��ָ��ջ��
		Cur = s.top();
		//�����ǰ��������Һ��ӣ��������ӻ��Һ������Ѿ��������ӡ����ջ����Pre��Ϊ��ǰ���
		if ((Cur->lchild == NULL && Cur->rchild == NULL) || (Pre != NULL && (Pre == Cur->lchild || Pre == Cur->rchild)))
		{
			cout << Cur->data;
			s.pop();
			Pre = Cur;
		}
		//�������Һ��ӣ������Һ���->����˳����ջ
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
	cout << "ǰ�������";
	//pre_order(T);
	preorder(T);
	cout << '\n' << "���������";
	//in_order(T);
	inorder(T);
	cout << '\n' << "���������";
	//beh_order(T);
	behorder(T);
	cout << endl;
	return 0;
}








