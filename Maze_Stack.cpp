//#include "SqStack.h"
//#include <stdio.h>
//#include <iostream>
//#define M 8
//#define N 8
//using namespace std;
//
////地图
//int mg[M + 2][N + 2]
//{
//	{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
//	{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
//	{1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
//	{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
//	{1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
//};
//
////方块类型
//class BOX
//{
//public:
//	int i;//行
//	int j;//列
//	int di;//下一相邻可走方位的方位号
//};
//
//bool mgpath(int xi, int yi, int xe, int ye)//求解路径为(xi,yi)->(xe,ye)
//{
//	BOX path[MaxSize], e;
//	int i, j, di, i1, j1, k;
//	bool find;
//	SqStack<BOX>* ss = new SqStack<BOX>();
//	e.i = xi; e.j = yi; e.di = -1;//e为入口
//	Push(ss,e);
//	mg[xi][yi] = -1;//入口值置为1，避免重复走到该方块
//	while (!StackEmpty(ss))
//	{
//		GetTop(ss,e);//取栈顶方块e
//		i = e.i; j = e.j;di = e.di;
//		if (i == xe && j == ye)//找到了出口，输出路径
//		{
//			cout << "一条迷宫路径如下：" << endl;
//			k = 0;
//			while (!StackEmpty(ss))
//			{
//				Pop(ss,e);//出栈方块e
//				path[k++] = e;//将e添加到path数组中
//			}
//			while (k >= 1)//打印路径
//			{
//				k--;
//				printf("\t(%d,%d)", path[k].i, path[k].j);
//				if ((k + 2) % 5 == 0)//每5个方块换行
//					cout << endl;
//			}
//			cout << endl;
//			DestroyStack(ss);
//			return true;
//		}
//		find = false;
//		while (di < 4 && !find)//找下一个相邻可走方块
//		{
//			di++;
//			switch (di)
//			{//四个方向
//			case 0:
//				i1 = i - 1; j1 = j; break;
//			case 1:
//				i1 = i; j1 = j + 1; break;
//			case 2:
//				i1 = i + 1; j1 = j; break;
//			case 3:
//				i1 = i; j1 = j - 1; break;
//			}
//			if (mg[i1][j1] == 0) find = true;//找到可走的
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
//		cout << "该迷宫问题没有解" << endl;
//	system("pause");
//	return 0;
//}