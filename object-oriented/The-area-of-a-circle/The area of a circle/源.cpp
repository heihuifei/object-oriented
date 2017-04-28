#include<iostream>
#include"Circle-Area.h"
#define Pie 3.1415926

using namespace std;

int main()
{
	Circle cir1;
	cir1.radius = 0;
	cout << "Please input your data :";
	while(cir1.radius != EOF)		//用户需要的测量数据量不定到输入结束标志时停止输入；
	{
		cin >> cir1.radius;
		if (cir1.radius < 0)
		{
			cout << "Sorry , your input is undesirable , please input again ." << endl;		//用户输入数据的简单检测不能为负数；
		}
		else
		{
			cir1.area = cir1.calculate( cir1.radius);
			cir1.display();
		}
	}
	return 0;
}
