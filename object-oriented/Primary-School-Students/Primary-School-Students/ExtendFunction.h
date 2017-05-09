#pragma once
/**************************************************************************
�ļ����� ExtendFunction.h
���ߣ�HXP  ��ɫ�޸ģ�ZC  ���ڣ�2017/02/15
����: �������ⲿ������
��Ҫ���ܰ���������ѡ�������⡢��Ŀ�����Լ���ʾ�����ж�

���ߣ�ZC   ���ڣ�2017/03/09
���£�����Դ�ļ���������԰汾��������д����Դ�ж����Ǵ����У��ʶ�ԭ�д�������ع�

ɾ������Ӣ��ѡ������
�޸ģ������⡢���ж�����Ӣ�İ汾���ĳɵ�������ģ�飬��������ͬ�����԰汾

ע������Resource[i]�е�������ע��ͷ�ļ�LanguageResource.h�ڵ�ע��˵��
***************************************************************************/

#include "Expression.h"
#include "LanguageResource.h"

int readFile(char* filename)
{
	int filein;
	fstream f1;
	f1.open(filename, ios::in);
	f1 >> filein;
	f1.close();
	return filein;
}

/*������*/
int GetInt(char* filename)
{
	int input;
	input = readFile(filename);
	//	char ch;

	cout << Resource[1];

	//while (scanf_s("%d", &input) != 1)//����Ĳ���%d
	//{
	//	cout << Resource[2];
	//	while ((ch = getchar()) != '\n')
	//		putchar(ch);//����û��������ַ���������ʾ����ַ�������������ʾ��������Ҫ��
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


/*����ֵ��һ�����ʽ�࣬�������������Ŀ*/
Expression CreateProblems()
{
	int val = FALSE;//��ȷ��
	Expression expression;

	expression.CreateInfixExpression();
	expression.ReversePolishNotation();
	val = expression.ExpressionValue();

	while (val == FALSE)//ȷ��������ִ�Ϊ����������Ŀ
	{
		Expression expression;

		expression.CreateInfixExpression();
		expression.ReversePolishNotation();
		val = expression.ExpressionValue();
	}
	return expression;
}

/*���ж�*/
bool Judge(int answer, Expression & e)
{
	int val = e.ExpressionValue();//��ȷ��

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