#pragma once
/**************************************************************************
文件名： ExtendFunction.h
作者：HXP  润色修改：ZC  日期：2017/02/15
描述: 其他的外部函数。
主要功能包括：语言选择、输入检测、题目生成以及显示、答案判定

作者：ZC   日期：2017/03/09
更新：用资源文件管理多语言版本，把语言写到资源中而不是代码中，故对原有代码进行重构

删除：中英文选择函数。
修改：输入检测、答案判定的中英文版本，改成单纯函数模块，不包含不同的语言版本

迭代者：HXP   日期：2017/05/10
更新：将输入输出以文件形式实现，输出功能函数化；

注：关于Resource[i]中的内容请注意头文件LanguageResource.h内的注释说明
***************************************************************************/

#include "Expression.h"
#include "LanguageResource.h"


/*通过文件的形式读入用户所要的题目数量*/
int readFile(char* filename)
{
	int filein;
	fstream f1;
	f1.open(filename, ios::in);
	f1 >> filein;
	f1.close();
	return filein;
}


/*在每次出题时将题目输出到out.txt文件中*/
void writeQuestionFile(int i, int answer, Expression & ex, char* filename)
{
	fstream f;
	f.open(filename, ios::ate | ios::app);
	f << "No." << i << "\t" << ex << endl;
	f << "\t" << Resource[8];
	f << answer << endl;
	f.close();

}

/*在输出答案的时候把答案输出到out.txt文件中*/
void writeAnswerFile(char* filename, int numRight, int numWrong, double accuracy)//待修改
{
	fstream f;
	f.open(filename, ios::ate | ios::app);
	f << Resource[9] << endl << endl;
	f << Resource[10] << numRight << endl;
	f << Resource[11] << numWrong << endl;
	f << Resource[12] << accuracy << "%" << endl;
	f << endl << Resource[0] << endl;
	f.close();
}

/*输入检测*/
int GetInt(char* filename)
{
	int input;
	input = readFile(filename);
	//	char ch;

	cout << Resource[1];

	//while (scanf_s("%d", &input) != 1)//输入的不是%d
	//{
	//	cout << Resource[2];
	//	while ((ch = getchar()) != '\n')
	//		putchar(ch);//如果用户输入了字符串，就显示这个字符串，并且在显示“不符合要求”
	//	cout << Resource[3] << endl;

	//	cout << Resource[1];
	//}
	while (input <= 0 || input > 100)
	{
		if (input < 0)
		{
			cout << Resource[4] << endl;
			input = GetInt(filename);
		}
		if (input > 100)
		{
			cout << Resource[5] << endl;
			input = GetInt(filename);
		}
		if (input == 0)
		{
			return 0;
		}
	}
	return input;
}


/*返回值是一个表达式类，里面的内容是题目*/
Expression CreateProblems()
{
	int val = FALSE;//正确答案
	Expression expression;

	expression.CreateInfixExpression();
	expression.ReversePolishNotation();
	val = expression.ExpressionValue();

	while (val == FALSE)//确保不会出现答案为非整数的题目
	{
		Expression expression;

		expression.CreateInfixExpression();
		expression.ReversePolishNotation();
		val = expression.ExpressionValue();
	}
	return expression;
}

/*答案判定*/
bool Judge(int answer, Expression & e)
{
	int val = e.ExpressionValue();//正确答案

	if (answer == val)
	{
		cout << Resource[6] << endl << endl;
		return true;
	}
	else
	{
		cout << Resource[7] << val << endl << endl;
		return false;
	}
}

void Print(int numRight, int numWrong, double accuracy)
{

	cout << Resource[9] << endl << endl;
	cout << Resource[10] << numRight << endl;
	cout << Resource[11] << numWrong << endl;
	cout << Resource[12] << accuracy << "%" << endl;
	cout << endl << Resource[0] << endl;

}