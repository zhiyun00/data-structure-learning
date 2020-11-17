#pragma once
#define Elemtype char
#define Max 10000
#include <cstddef>
#include <malloc.h>
#include <stdio.h>
#include "E:\C++\StackExperiment\SqStack.h"

typedef struct node
{
	Elemtype data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

bool Judge(Elemtype* str)
{
	SqStack<Elemtype>* s;
	InitStack(s);
	Elemtype e;
	char ch;
	int k = 0;
	ch = str[k];
	if (ch == '(' || ch == ',' || ch == ')')
	{
		return false;
	}
	ch = str[++k];
	while (ch != '\0')
	{
		if (ch == '(')
		{
			if (str[k - 1] == '(' || str[k - 1] == ',' || str[k - 1] == ')')
			{
				return false;
			}
			else
			{
				Push(s, ch);
			}
		}
		else if (ch == ',')
		{
			if (GetTop(s, e))
			{
				if (e != '(')
				{
					return false;
				}
				else
				{
					Push(s, ch);
				}
			}
			else//取不到栈顶元素
			{
				return false;
			}
		}
		else if (ch == ')')
		{
			if (GetTop(s, e))
			{
				if (e != ',')
				{
					return false;
				}
				else
				{
					Pop(s, e);
					Pop(s, e);
				}
			}
			else
			{
				return false;
			}
		}
		ch=str[++k];
	}
	if (!StackEmpty(s))//最后栈不为空
	{
		return false;
	}

	for (int i = 1; str[i] != '\0'; i++)
	{
		if (str[i] != '(' && str[i] != ',' && str[i] != ')')
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (str[i] == str[j])
				{
					return false;
				}
			}
		}
	}

	return true;
}

void CreateBTree(BTNode*& b, Elemtype* str)
{
	BTNode* St[MaxSize], * p;
	int top = -1, k, j = 0;
	Elemtype ch;
	b = NULL;
	p = NULL;
	ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':
			top++;
			St[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
			{
				b = p;
			}
			else
			{
				switch (k)
				{
				case 1:
					St[top]->lchild = p;
					break;
				case 2:
					St[top]->rchild = p;
					break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

void DestroyBTree(BTNode*& b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

BTNode* FindNode(BTNode* b, Elemtype x)
{
	BTNode* p;
	if (b == NULL)
	{
		return NULL;
	}
	else if (b->data == x)
	{
		return b;
	}
	else
	{
		p = FindNode(b->lchild, x);
		if (p != NULL)
		{
			return p;
		}
		else
		{
			return FindNode(b->rchild, x);
		}
	}
}

BTNode* LchildNode(BTNode* p)
{
	return p->lchild;
}
BTNode* RchildNode(BTNode* p)
{
	return p->rchild;
}

int BTHeight(BTNode* b)
{
	int lchildh, rchildh;
	if (b == NULL)
	{
		return 0;
	}
	else
	{
		lchildh = BTHeight(b->lchild);
		rchildh = BTHeight(b->rchild);
		return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}

void DispBTree(BTNode* b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			DispBTree(b->lchild);
			if (b->rchild != NULL)
			{
				printf(",");
			}
			DispBTree(b->rchild);
			printf(")");
		}
	}
}

void PreOrder(BTNode* b,char *ch)
{
	BTNode* p;
	SqStack<BTNode*>* st;
	InitStack(st);
	p = b;
	int i = 0;
	while (!StackEmpty(st) || p != NULL)
	{
		while (p != NULL)
		{
			printf("%c", p->data);
			ch[i++] = p->data;
			Push(st, p);
			p = p->lchild;
		}
		if (!StackEmpty(st))
		{
			Pop(st, p);
			p = p->rchild;
		}
	}
	printf("\n");
	DestroyStack(st);
}

void InOrder(BTNode* b,char* ch)
{
	BTNode* p;
	SqStack<BTNode*>* st;
	InitStack(st);
	p = b;
	int i = 0;
	while (!StackEmpty(st) || p != NULL)
	{
		while (p != NULL)
		{
			Push(st, p);
			p = p->lchild;
		}
		if (!StackEmpty(st))
		{
			Pop(st, p);
			printf("%c", p->data);
			ch[i++] = p->data;
			p = p->rchild;
		}
	}
	printf("\n");
	DestroyStack(st);
}

void PostOrder(BTNode* b)
{
	BTNode* p, * r;
	bool flag;
	SqStack<BTNode*>* st;
	InitStack(st);
	p = b;
	do
	{
		while (p != NULL)
		{
			Push(st, p);
			p = p->lchild;
		}
		r = NULL;
		flag = true;
		while (!StackEmpty(st) && flag)
		{
			GetTop(st, p);
			if (p->rchild == r)
			{
				printf("%c", p->data);
				Pop(st, p);
				r = p;
			}
			else
			{
				p = p->rchild;
				flag = false;
			}
		}
	} while (!StackEmpty(st));
	printf("\n");
	DestroyStack(st);
}

BTNode* CreateBT(Elemtype* pre, Elemtype* in, int n)
{
	BTNode* b;
	Elemtype* p;
	int k;
	if (n <= 0)
	{
		return NULL;
	}
	b = (BTNode*)malloc(sizeof(BTNode));
	b->data = *pre;
	for (p = in; p < in + n; p++)
	{
		if (*p == *pre)
		{
			break;
		}
	}
	k = p - in;
	b->lchild = CreateBT(pre + 1, in, k);
	b->rchild = CreateBT(pre + k + 1, p + 1, n - k - 1);
	return b;
}

BTNode* CreateBT2(Elemtype* post, Elemtype* in, int n)
{
	BTNode* b;
	Elemtype r, * p;
	int k;
	if (n <= 0)
	{
		return NULL;
	}
	r = *(post + n - 1);
	b = (BTNode*)malloc(sizeof(BTNode));
	b->data = r;
	for (p = in; p < in + n; p++)
	{
		if (*p == r)
		{
			break;
		}
	}
	k = p - in;
	b->lchild = CreateBT2(post, in, k);
	b->rchild = CreateBT2(post + k, p + 1, n - k - 1);
	return b;
}