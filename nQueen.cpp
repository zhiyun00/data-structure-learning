//#include "SqStack.h"
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//using namespace std;
//
//template<typename T>
//void showSolution(SqStack<T> ss)
//{
//	static int count = 0;	//��̬��������ͳ�ƽ����
//	cout << "��" << ++count << "���⣺";
//	for (int i = 1; i <= ss.top; i++)
//	{
//		cout << "(" << i << "," << ss.data[i] << ")" << ends;
//	}
//	cout << endl;
//}
//
//template<typename T>
//bool notConflict(SqStack<T> ss, int k, int j)//��ǰ��k-1���ʺ��Ƿ��ͻ
//{
//	int i = 1;
//	if (k == 1)
//	{
//		return true;
//	}
//	while (i <= k - 1)
//	{
//		if ((ss.data[i] == j) || (abs(j - ss.data[i]) == abs(i - k)))//���ظ���Խ���
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
//	ss.top++;	//�ʺ�ӵ�1�п�ʼ
//	ss.data[ss.top] = 0;	//��һ���ʺ��ʼ�к�Ϊ0
//	int k;
//	bool flag;
//	while (ss.top != 0)
//	{
//		k = ss.top;	//��̽ջ���ĵ�k���ʺ�
//		flag = false;	//��δ�ҵ���k���ʺ��λ��
//		for (int i = ss.data[k] + 1; i <= n; i++)	//Ϊ��k���ʺ���һ�����ʵ��к�
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
//			if (k == n)	//���лʺ���ź�
//			{
//				showSolution<T>(ss);
//			}
//			else//�лʺ�δ��ջʱ
//			{
//				ss.top++;
//				ss.data[ss.top] = 0;	//�½�ջ�Ļʺ�ӵ�0�п�ʼ
//			}
//		}
//		else	//��k���ʺ�û�к���λ�ã�����
//		{
//			ss.top--;
//		}
//	}
//}
//
//int main()
//{
//	int n;
//	cout << "n�ʺ����� n=";
//	scanf_s("%d", &n);
//	queen<int>(n);
//	system("pause");
//	return 0;
//}