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
//销毁栈
template <typename T>
void DestroyStack(SqStack<T>*& s)
{
	free(s);
}
//初始化
template <typename T>
void InitStack(SqStack<T>*& s)
{
	s = (SqStack<T>*)malloc(sizeof(SqStack<T>));
	s->top = -1;
}
//判断栈是否为空
template <typename T>
bool StackEmpty(SqStack<T>* s)
{
	return(s->top == -1);
}
//进栈
template <typename T>
bool Push(SqStack<T>*& s,T t)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = t;
	return true;
}
//出栈
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
//取栈顶元素
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