//#include <iostream>
//#include "btree.h"
//using namespace std;
//void Output(BTNode* p)
//{
//	if (p != NULL)
//	{
//		printf("%c", p->data);
//		Output(p->lchild);
//		Output(p->rchild);
//	}
//}
//void Child(BTNode* b, char x)
//{
//	if (b != NULL)
//	{
//		if (b->data == x)
//		{
//			if (b->lchild != NULL)
//			{
//				Output(b->lchild);
//			}
//			if (b->rchild != NULL)
//			{
//				Output(b->rchild);
//			}
//			return;
//		}
//		Child(b->lchild, x);
//		Child(b->rchild, x);
//	}
//}
//
//
//int main()
//{
//	char c[Max];
//	cout << "请输入表达式:";
//	cin >> c;
//	if (Judge(c))
//	{
//		BTNode* b;
//		CreateBTree(b, c);
//		char x;
//		cout << "请输入值:";
//		cin >> x;
//		Child(b, x);
//		DestroyBTree(b);
//	}
//	else
//	{
//		cout << "表达式有误" << endl;
//	}
//	system("pause");
//	return 0;
//}