//#include "SqStack.h"
//#include <stdio.h>
//#include <iostream>
//#define M 8
//#define N 8
//using namespace std;
//
////��ͼ
//int mg[M + 2][N + 2]
//{
//	{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
//	{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
//	{1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
//	{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
//	{1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
//};
//
////��������
//class BOX
//{
//public:
//	int i;//��
//	int j;//��
//	int di;//��һ���ڿ��߷�λ�ķ�λ��
//};
//
//bool mgpath(int xi, int yi, int xe, int ye)//���·��Ϊ(xi,yi)->(xe,ye)
//{
//	BOX path[MaxSize], e;
//	int i, j, di, i1, j1, k;
//	bool find;
//	SqStack<BOX>* ss = new SqStack<BOX>();
//	e.i = xi; e.j = yi; e.di = -1;//eΪ���
//	Push(ss,e);
//	mg[xi][yi] = -1;//���ֵ��Ϊ1�������ظ��ߵ��÷���
//	while (!StackEmpty(ss))
//	{
//		GetTop(ss,e);//ȡջ������e
//		i = e.i; j = e.j;di = e.di;
//		if (i == xe && j == ye)//�ҵ��˳��ڣ����·��
//		{
//			cout << "һ���Թ�·�����£�" << endl;
//			k = 0;
//			while (!StackEmpty(ss))
//			{
//				Pop(ss,e);//��ջ����e
//				path[k++] = e;//��e��ӵ�path������
//			}
//			while (k >= 1)//��ӡ·��
//			{
//				k--;
//				printf("\t(%d,%d)", path[k].i, path[k].j);
//				if ((k + 2) % 5 == 0)//ÿ5�����黻��
//					cout << endl;
//			}
//			cout << endl;
//			DestroyStack(ss);
//			return true;
//		}
//		find = false;
//		while (di < 4 && !find)//����һ�����ڿ��߷���
//		{
//			di++;
//			switch (di)
//			{//�ĸ�����
//			case 0:
//				i1 = i - 1; j1 = j; break;
//			case 1:
//				i1 = i; j1 = j + 1; break;
//			case 2:
//				i1 = i + 1; j1 = j; break;
//			case 3:
//				i1 = i; j1 = j - 1; break;
//			}
//			if (mg[i1][j1] == 0) find = true;//�ҵ����ߵ�
//		}
//		if (find)
//		{
//			ss->data[ss->top].di = di;
//			e.i = i1; e.j = j1; e.di = -1;
//			Push(ss,e);
//			mg[i1][j1] = -1;
//		}
//		else
//		{
//			Pop(ss,e);
//			mg[e.i][e.j] = 0;
//		}
//	}
//	DestroyStack(ss);
//	return false;
//}
//
//int main()
//{
//	if (!mgpath(1, 1, M, N))
//		cout << "���Թ�����û�н�" << endl;
//	system("pause");
//	return 0;
//}