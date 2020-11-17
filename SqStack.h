#pragma once
#include <iostream>
#include <malloc.h>
#define MaxSize 100
using namespace std;

template <typename T>
class SqStack
{
public:
	T data[MaxSize];
	int top;
};
//����ջ
template <typename T>
void DestroyStack(SqStack<T>*& s)
{
	free(s);
}
//��ʼ��
template <typename T>
void InitStack(SqStack<T>*& s)
{
	s = (SqStack<T>*)malloc(sizeof(SqStack<T>));
	s->top = -1;
}
//�ж�ջ�Ƿ�Ϊ��
template <typename T>
bool StackEmpty(SqStack<T>* s)
{
	return(s->top == -1);
}
//��ջ
template <typename T>
bool Push(SqStack<T>*& s,T t)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = t;
	return true;
}
//��ջ
template <typename T>
bool Pop(SqStack<T>*& s,T& t)
{
	if (s->top == -1)
	{
		return false;
	}
	t = s->data[s->top];
	s->top--;
	return true;
}
//ȡջ��Ԫ��
template <typename T>
bool GetTop(SqStack<T>* s,T& t)
{
	if (s->top == -1)
	{
		return false;
	}
	t = s->data[s->top];
	return true;
}