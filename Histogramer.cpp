#define _CRT_SECURE_NO_WARNINGS 
#include "histogram.h"
#include <iostream>
#include <iomanip>
#include <string>

 
int main(){
	using namespace std;
	setlocale(LC_ALL, "Russian");

	const char * const strProgramName = "Histogramer 1.0";

	std::cout << std::setfill('*') << std::setw(strlen(strProgramName)+4) << "" << std::endl;
	std::cout << '*' << std::setfill(' ') << std::setw(strlen(strProgramName)+3) << '*' << std::endl;
	std::cout << "* " << strProgramName << " *" << std::endl;
	std::cout << '*' << std::setfill(' ') << std::setw(strlen(strProgramName)+3) << '*' << std::endl;
	std::cout << std::setfill('*') << std::setw(strlen(strProgramName)+4) << "" << std::endl << std::endl;

	Histogram myBarChart;

	InitHistogram(myBarChart);
	
	cout << "������� ������: ";
	string str;
	getline(cin, str);
	char* s = (char*)str.c_str(); //������� c_str ���������� ������� �� ������� ������, � ������� �������� ������� ������, ���������� �������� ���� char*. ������������ �������� ����� ������������� ��� C-������ � ������������ � ��������, ������� ������ �������� �� ���� C-������.
	char* p = strtok(s, " ");
	while (p != NULL) // ���� ���� �������
	{
		AddBlock(myBarChart, p);
		p = strtok(NULL, " ");
	}

	PrintHistogram(myBarChart);
	int a;

	cout << "�������� ������ ����������:" << endl;
	cout << "������� '0', ���� �� ��������" << endl;
	cout << "������� '1', ���� �� ����������� " << endl;
	cin >> a;

	SortByVal(myBarChart, a);



	PrintHistogram(myBarChart);

	DestroyHistogram(myBarChart);

	return 0;
}