#include<iostream>
#include"Circle-Area.h"
#define Pie 3.1415926

using namespace std;

int main()
{
	Circle cir1;
	cir1.radius = 0;
	cout << "Please input your data :";
	while(cir1.radius != EOF)		//�û���Ҫ�Ĳ������������������������־ʱֹͣ���룻
	{
		cin >> cir1.radius;
		if (cir1.radius < 0)
		{
			cout << "Sorry , your input is undesirable , please input again ." << endl;		//�û��������ݵļ򵥼�ⲻ��Ϊ������
		}
		else
		{
			cir1.area = cir1.calculate( cir1.radius);
			cir1.display();
		}
	}
	return 0;
}
