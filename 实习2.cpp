//#include "btree.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "请输入表达式:";
//	char exp[Max]; //= "a(b(c,d),e)";
//	cin >> exp;
//	if (Judge(exp))
//	{
//		BTNode* b1;
//		CreateBTree(b1, exp);
//		cout << "前序:";
//		char exp1[Max];
//		PreOrder(b1,exp1);
//		cout << "中序:";
//		char exp2[Max];
//		InOrder(b1,exp2);
//		cout << "后序:";
//		PostOrder(b1);
//		BTNode* b2;
//		b2 = CreateBT(exp1, exp2, strlen(exp1));
//		cout << "括号表示法输出:";
//		DispBTree(b2);
//		cout << endl;
//		DestroyBTree(b1);
//	}
//	else
//	{
//		cout << "表达式有误" << endl;
//	}
//	system("pause");
//	return 0;
//}