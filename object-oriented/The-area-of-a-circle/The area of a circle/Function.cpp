#include<iostream>
#include"Circle-Area.h"
#define Pie 3.1415926

using namespace std;

void Circle::display()
{
		cout << "The area of the circle whose radius is " << radius << " is: " << endl;
		cout << area << endl;
}

double Circle::calculate(double radius)
{
	double area= (double)Pie*radius*radius;
	return area;
}