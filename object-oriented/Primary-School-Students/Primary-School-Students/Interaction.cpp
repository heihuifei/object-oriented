/**************

迭代者：HXP
时间：2017/05/23
迭代内容：将类的声明和定义以.h和.cpp形式分离

***************/

#include<iostream>
#include"Interaction.h"

using namespace std;

void User::WrongAgain()
{
	cout << "Sorry. Your input is wrong or software does not support your language. " << endl;

	ShowLanguageList();
}

void User::MakeResource()
{
	strcat_s(Langpath, "LangResourses\\");
	strcat_s(Langpath, language);
	strcat_s(Langpath, ".txt");

}

void User::Print(int numRight, int numWrong, double accuracy)
{
	cout << Resource[9] << endl << endl;
	cout << Resource[10] << numRight << endl;
	cout << Resource[11] << numWrong << endl;
	cout << Resource[12] << accuracy << "%" << endl;
	cout << endl << Resource[0] << endl;

}