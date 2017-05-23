/**************

迭代者：HXP
时间：2017/05/23
迭代内容：将类的声明和定义以.h和.cpp形式分离

***************/

#include"stack.h"


Stack::Stack()
{
	Data = new int[50];
}

Stack::~Stack()
{
	delete[] Data;
}
bool Stack::empty()const
{
	return posi == 0;
}

int Stack::top()const
{
	if (empty())
	{
		return false;
	}
	else
	{
		return Data[posi - 1];
	}
}

bool Stack::push(const int & item)
{
	if (posi < 50)
	{
		Data[posi++] = item;
		return true;
	}
	else
	{
		return false;
	}
}

bool Stack::pop()
{
	if (posi > 0)
	{
		int temp;
		temp = Data[--posi];
		return true;
	}
	else
	{
		return false;
	}
}

int Stack::size()
{
	return posi;
}