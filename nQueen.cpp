//#include "SqStack.h"
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//using namespace std;
//
//template<typename T>
//void showSolution(SqStack<T> ss)
//{
//	static int count = 0;	//静态变量用于统计解个数
//	cout << "第" << ++count << "个解：";
//	for (int i = 1; i <= ss.top; i++)
//	{
//		cout << "(" << i << "," << ss.data[i] << ")" << ends;
//	}
//	cout << endl;
//}
//
//template<typename T>
//bool notConflict(SqStack<T> ss, int k, int j)//与前面k-1个皇后是否冲突
//{
//	int i = 1;
//	if (k == 1)
//	{
//		return true;
//	}
//	while (i <= k - 1)
//	{
//		if ((ss.data[i] == j) || (abs(j - ss.data[i]) == abs(i - k)))//列重复或对角线
//		{
//			return false;
//		}
//		i++;
//	}
//	return true;
//}
//
//template<typename T>
//void queen(int n)
//{
//	SqStack<T> ss;
//	ss.top = 0;
//	ss.top++;	//皇后从第1行开始
//	ss.data[ss.top] = 0;	//第一个皇后初始列号为0
//	int k;
//	bool flag;
//	while (ss.top != 0)
//	{
//		k = ss.top;	//试探栈顶的第k个皇后
//		flag = false;	//尚未找到第k个皇后的位置
//		for (int i = ss.data[k] + 1; i <= n; i++)	//为第k个皇后找一个合适的列号
//		{
//			if (notConflict<T>(ss, k, i))
//			{
//				ss.data[ss.top] = i;
//				flag = true;
//				break;
//			}
//		}
//		if (flag)
//		{
//			if (k == n)	//所有皇后均放好
//			{
//				showSolution<T>(ss);
//			}
//			else//有皇后未进栈时
//			{
//				ss.top++;
//				ss.data[ss.top] = 0;	//新进栈的皇后从第0列开始
//			}
//		}
//		else	//第k个皇后没有合适位置，回溯
//		{
//			ss.top--;
//		}
//	}
//}
//
//int main()
//{
//	int n;
//	cout << "n皇后问题 n=";
//	scanf_s("%d", &n);
//	queen<int>(n);
//	system("pause");
//	return 0;
//}