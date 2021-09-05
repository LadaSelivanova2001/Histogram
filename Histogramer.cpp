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
	
	cout << "Введите строку: ";
	string str;
	getline(cin, str);
	char* s = (char*)str.c_str(); //функция c_str возвращает указать на область памяти, в которой хранятся символы строки, возвращает значение типа char*. Возвращаемое значение можно рассматривать как C-строку и использовать в функциях, которые должны получать на вход C-строку.
	char* p = strtok(s, " ");
	while (p != NULL) // пока есть лексемы
	{
		AddBlock(myBarChart, p);
		p = strtok(NULL, " ");
	}

	PrintHistogram(myBarChart);
	int a;

	cout << "Выберите способ сортировки:" << endl;
	cout << "Введите '0', если по убыванию" << endl;
	cout << "Введите '1', если по возрастанию " << endl;
	cin >> a;

	SortByVal(myBarChart, a);



	PrintHistogram(myBarChart);

	DestroyHistogram(myBarChart);

	return 0;
}