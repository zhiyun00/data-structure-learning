//#include "btree.h"
//#include <iostream>
//using namespace std;
//
//bool isOperator(char ch)
//{
//	if (ch == '+' || ch == '-' || ch == '*' || ch == '/'|| ch == '(' || ch == ')')
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int Priority(char ch)
//{
//	if (ch == '+' || ch == '-')
//	{
//		return 1;
//	}
//	else
//	{
//		return 2;
//	}
//}
//
//void getPost(Elemtype* exp,Elemtype* post)
//{
//	SqStack<Elemtype>* s;
//	InitStack(s);
//	int i = 0;
//	Elemtype ch;
//	for (; *exp != '\0'; exp++)
//	{
//		if (isOperator(*exp))
//		{
//			if (*exp == '(')
//			{
//				Push(s, *exp);
//			}
//			else if (*exp == ')')
//			{
//				while (!StackEmpty(s))
//				{
//					Pop(s, ch);
//					if (ch == '(')
//					{
//						break;
//					}
//					else
//					{
//						post[i++] = ch;
//					}
//				}
//			}
//			else
//			{
//				while (!StackEmpty(s))
//				{
//					GetTop(s, ch);
//					if (ch == '(')
//					{
//						Push(s, *exp);
//						break;
//					}
//					else if (Priority(ch) >= Priority(*exp))
//					{
//						Pop(s, ch);
//						post[i++] = ch;
//					}
//					else if (Priority(ch) < Priority(*exp))
//					{
//						Push(s, *exp);
//						break;
//					}
//				}
//				if (StackEmpty(s))
//				{
//					Push(s, *exp);
//				}
//			}
//		}
//		else
//		{
//			post[i++] = *exp;
//		}
//	}
//	while (!StackEmpty(s))
//	{
//		Pop(s, ch);
//		post[i++] = ch;
//	}
//}
//
//void CBTree(BTNode*& p, Elemtype* post)
//{
//	BTNode* nodeArray[Max], * b;
//	b = NULL;
//	int top = -1;
//	for (int j = 0; post[j] != '\0'; j++)
//	{
//		if (isOperator(post[j]))
//		{
//			b = (BTNode*)malloc(sizeof(BTNode));
//			b->data = post[j];
//			b->rchild = nodeArray[top];
//			top--;
//			b->lchild = nodeArray[top];
//			nodeArray[top] = b;
//		}
//		else
//		{
//			b = (BTNode*)malloc(sizeof(BTNode));
//			b->data = post[j];
//			b->lchild = b->rchild = NULL;
//			top++;
//			nodeArray[top] = b;
//		}
//	}
//	p = nodeArray[top];
//}
//
//int main()
//{
//	char exp[Max];
//	char temp[Max];
//	cout << "请输入算术表达式:";
//	cin >> exp;
//	BTNode* b;
//	char post[Max];
//	getPost(exp, post);
//	CBTree(b, post);
//	cout << "对应的二叉树:";
//	DispBTree(b);
//	cout << endl;
//	cout << "前序:";
//	PreOrder(b, temp);
//	cout << "中序:";
//	InOrder(b, temp);
//	cout << "后序:";
//	PostOrder(b);
//	DestroyBTree(b);
//	system("pause");
//	return 0;
//}