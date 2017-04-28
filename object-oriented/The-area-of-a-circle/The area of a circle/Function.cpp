#include<iostream>
#include"Circle-Area.h"
#define Pie 3.1415926

using namespace std;

//打印输出函数定义
void Circle::display()
{
		cout << "The area of the circle whose radius is " << radius << " is: " << endl;
		cout << area << endl;
}

//计算面积函数
double Circle::calculate(double radius)
{
	double area= (double)Pie*radius*radius;
	return area;
}