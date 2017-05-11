/******************************************************************************
�ļ����� main.cpp
���ߣ�ZC  ���ڣ�2017/02/15
����: ��������ʵ�����幦��

���ߣ�ZC  ���ڣ�2017/03/09
���£�����Դ�ļ���������԰汾��������д����Դ�ж����Ǵ����У��ʶ�ԭ�д�������ع�

ע������Resource[i]�е�������ע��ͷ�ļ�LanguageResource.h�ڵ�ע��˵��

�����ߣ�HXP  ���ڣ�2017/05/11
���£�ͨ�������������������в�����ʽ�Լ����������ͨ���ļ���ʽʵ��
*******************************************************************************/
#include "Expression.h"
#include "ExtendFunction.h"
#include "LanguageResource.h"
#include<fstream>

int main(int argc, char* argv[])
{
	int i;
	int n;//�û�������������Ŀ����
	int answer;//�û�������Ŀ��
	static int numRight = 0, numWrong = 0;//ͳ������������ȷ�ʹ�������
	double accuracy;//��ȷ��

	cout << "Arithmetic Test For Primary School Students" << endl << endl;
	ShowLanguageList();

	char language[200];//�û���������
	gets_s(language);

	while (CheckLanguageSupport(language) == false)//�������Լ��
	{
		if (strcmp("e", language) == 0)
		{
			cout << endl << "The program is going to be finished. Goodbye!~" << endl;
			getchar();
			return 0;
		}
		cout << "Sorry. Your input is wrong or software does not support your language. " << endl;

		ShowLanguageList();
		gets_s(language);
	}

	char Langpath[255] = "";//�����û�������ȥ�γ�һ��·��
	strcat_s(Langpath, "LangResourses\\");
	strcat_s(Langpath, language);
	strcat_s(Langpath, ".txt");

	/*��������

	GetResource("LangResourses\\�ձ���.txt");
	for (i = 0; i < 13; i++)
	{
	cout << Resource[i] << endl;
	}
	*/

	GetResource(Langpath);
	n = GetInt(argv[1]);//������
	if (n == 0)
	{
		cout << Resource[0] << endl;
		getchar();
		getchar();
		return 0;
	}

	fstream fileout;
	fileout.open(argv[2], ios::ate | ios::app);
	fileout << "���������Ŀ����Ϊ��" << n << endl;
	fileout.close();

	for (i = 1; i <= n; i++)
	{
		Expression expression; //��Ŀ
		expression = CreateProblems();

		cout << "No." << i << "\t" << expression << endl;
		//		fileout << "No." << i << "\t" << expression << endl;

		cout << "\t" << Resource[8];
		//		fileout << "\t" << Resource[8];

		cin >> answer;
		//		fileout << answer << endl;

		bool result = Judge(answer, expression);
		if (result == true)
		{
			numRight++;
		}
		else if (result == false)
		{
			numWrong++;
		}
		writeQuestionFile(i, answer, expression, argv[2]);	//��ÿ�ε���Ŀ�����out.txt�ļ��У�
		expression.~Expression();
	}

	accuracy = numRight*1.0 / n * 100;

	Print(numRight, numWrong, accuracy);	//����û��������������

	writeAnswerFile(argv[2], numRight, numWrong, accuracy);		//���ж������ȷ����������ļ��У�
//	cout << exp[1] << endl;

	getchar();
	getchar();
	fileout.close();
	return 0;
}