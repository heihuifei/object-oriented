#pragma once

class Circle
{
public:
	double radius ;		//圆的半径
	double area ;		//圆的面积
	void display();			//打印输出的函数声明；
	double calculate(double radius);		//通过用户所输入的半径数据计算面积的函数声明；
};