//#include "btree.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "��������ʽ:";
//	char exp[Max]; //= "a(b(c,d),e)";
//	cin >> exp;
//	if (Judge(exp))
//	{
//		BTNode* b1;
//		CreateBTree(b1, exp);
//		cout << "ǰ��:";
//		char exp1[Max];
//		PreOrder(b1,exp1);
//		cout << "����:";
//		char exp2[Max];
//		InOrder(b1,exp2);
//		cout << "����:";
//		PostOrder(b1);
//		BTNode* b2;
//		b2 = CreateBT(exp1, exp2, strlen(exp1));
//		cout << "���ű�ʾ�����:";
//		DispBTree(b2);
//		cout << endl;
//		DestroyBTree(b1);
//	}
//	else
//	{
//		cout << "���ʽ����" << endl;
//	}
//	system("pause");
//	return 0;
//}