//表达式求值
#include "SqStack.h"
#include <string>
#include <iostream>
using namespace std;

//判断表达式是否合法
template<typename T>
bool ifValid_01(T* exp)//连续两个运算符
{
    bool flag=false;
    if (*exp == '+' || *exp == '*' || *exp == '/' || *exp == ')')
    {
        return false;
        exp++;
    }
    while (*exp != '\0')
    {
        if (*exp == '(')
        {
            if (*(exp - 1) != '+' && *(exp - 1) != '-' && *(exp - 1) != '*' && *(exp - 1) != '/' && *(exp - 1) != '\0' && *(exp - 1) != '(')
            {
                return false;
            }
        }
        if (*exp == '+' || *exp == '-' || *exp == '*' || *exp == '/'||*exp=='(')
        {
            if (*(exp + 1) == '+' || *(exp + 1) == '-' || *(exp + 1) == '*' || *(exp + 1) == '/' || *(exp + 1) == '\0'||*(exp+1)==')')
            {
                return false;
            }
        }
        if (*exp == '+' || *exp == '-' || *exp == '*' || *exp == '/' || *exp == ')')
        {
            if (*(exp - 1) == '+' || *(exp - 1) == '-' || *(exp - 1) == '*' || *(exp - 1) == '/' || *(exp - 1) == '\0' || *(exp - 1) == '(')
            {
                return false;
            }
        }
        if (*exp == '+' || *exp == '-' || *exp == '*' || *exp == '/')
        {
            flag = true;
        }
        exp++;
    }
    return flag;
}
template<typename T>
bool ifValid_02(T* exp)//括号不匹配
{
    SqStack<T>* s;
    InitStack(s);
    T t;
    while (*exp != '\0')
    {
        if (*exp == '(')//左括号进栈
        {
            Push(s,*exp);
        }
        else if (*exp == ')')//遇到右括号得跟栈顶元素比较
        {
            if (GetTop(s,t))
            {
                if (t != '(')
                {
                    return false;
                }
                else
                {
                    Pop(s,t);
                }
            }
            else//取不到栈顶元素
            {
                return false;
            }
        }
        exp++;
    }
    if (!StackEmpty(s))//最后栈不为空
    {
        return false;
    }
    return true;
}

template<typename T>
void trans(T* exp, T postexp[])
{
    char e;
    SqStack<T>* Optr;
    InitStack(Optr);
    int i = 0;
    while (*exp != '\0')
    {
        switch (*exp)
        {
        case '(':
            Push(Optr,'(');//左括号进栈
            exp++;//继续扫描
            break;
        case ')':
            Pop(Optr,e);//出栈e
            while (e != '(')//非右括号循环
            {
                postexp[i++] = e;//e存在postexp中
                Pop(Optr,e);//继续出栈3=e
            }
            exp++;//继续扫描
            break;
        case '+':
        case '-':
            while (!StackEmpty(Optr))//栈不空循环
            {
                GetTop(Optr,e);//取栈顶元素e
                if (e != '(')
                {
                    postexp[i++] = e;
                    Pop(Optr,e);
                }
                else
                {
                    break;
                }
            }
            Push(Optr ,*exp);//运算符进栈
            exp++;
            break;
        case '*':
        case '/':
            while (!StackEmpty(Optr))
            {
                GetTop(Optr,e);
                if (e == '*' || e == '/')
                {
                    postexp[i++] = e;
                    Pop(Optr,e);
                }
                else
                {
                    break;
                }
            }
            Push(Optr ,*exp);
            exp++;
            break;
        default:
            while (*exp >= '0' && *exp <= '9')//处理数字字符
            {
                postexp[i++] = *exp;
                exp++;
            }
            postexp[i++] = '#';//标志数字串结束
        }
    }
    while (!StackEmpty(Optr))//exp扫描完毕，栈不空时循环
    {
        Pop(Optr,e);
        postexp[i++] = e;
    }
    postexp[i] = '\0';//结束标志
    DestroyStack(Optr);
}

template <typename T1,typename T2>
T1 compvalue(T2* postexp)//计算后缀表达式的值
{
    T1 d, a, b, c, e;
    SqStack<T1>* Opnd;//定义操作数栈
    InitStack(Opnd);
    while (*postexp != '\0')
    {
        switch (*postexp)
        {
        case '+':
            Pop(Opnd,a);//出栈a和b
            Pop(Opnd,b);
            c = b + a;
            Push(Opnd,c);//计算结果c进栈
            break;
        case '-':
            Pop(Opnd,a);
            Pop(Opnd,b);
            c = b - a;
            Push(Opnd,c);
            break;
        case '*':
            Pop(Opnd,a);
            Pop(Opnd,b);
            c = b * a;
            Push(Opnd,c);
            break;
        case '/':
            Pop(Opnd,a);
            Pop(Opnd,b);
            if (a != 0)
            {
                c = b / a;
                Push(Opnd,c);
                break;
            }
            else//异常退出
            {
                cout << endl << "除零错误" << endl;
                exit(0);
            }
            break;
        default://处理数字字符
            d = 0;
            while (*postexp >= '0' && *postexp <= '9')
            {
                d = 10 * d + *postexp - '0';
                postexp++;
            }
            Push(Opnd,d);
            break;
        }
        postexp++;
    }
    GetTop(Opnd,e);
    DestroyStack(Opnd);
    return e;
}

int main()
{
    bool exit=true;
    while (exit)
    {
        cout << "请输入表达式:" << endl;
        char exp[20];
        cin >> exp;
        if (ifValid_01<char>(exp)&&ifValid_02<char>(exp))
        {
            char postexp[MaxSize];
            trans<char>(exp, postexp);
            cout << "中缀表达式:" << exp << endl;
            cout << "后缀表达式:" << postexp << endl;
            cout << "表达式的值:" << compvalue<double,char>(postexp) << endl;
            exit = false;
        }
        else
        {
            cout << "表达式有误" << endl;
            exit = true;
            cout << endl;
        }
    }
    system("pause");
    return 0;
}