#define _CRT_SECURE_NO_WARNINGS
#include "histogram.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

///////////////////////////////////////////////////////////////////
// ��������������� �������
void AddBar(Histogram &historgam, const char *strName);
bool AppendBar(Histogram &historgam, const char *strName);

///////////////////////////////////////////////////////////////////
// ���������� ������� �� ����� histogram.h


//-----------------------------------------------------------------
// ������� AddBlock ����������� �������� ������� strName ���������� historgam �� 1.
// ���� ������� � ����� ������ �� ����������, �� ���������.
void AddBlock(Histogram &historgam, const char *strName){
	if(!AppendBar(historgam, strName)){
		AddBar(historgam, strName);
	}
}

//-----------------------------------------------------------------
// ������� PrintHistogram ������� ���������� �� �����.
void PrintHistogram(const Histogram& historgam) {
	for (int i = 0; i < historgam.nBarsSize; i++) {
		cout << left << setfill(' ') << setw(10) << historgam.BarNames[i] << '|';
		cout << setfill(historgam.chBlock) << setw(10 * historgam.Bars[i] / historgam.nMaxBar) << "" << endl;
	}
}

///////////////////////////////////////////////////////////////////
// ���������� ��������������� �������

//-----------------------------------------------------------------
// ������� AppendBar ����������� �������� ������� strName ���������� historgam �� 1.
bool AppendBar(Histogram &historgam, const char *strName){
	for(int i=0; i<historgam.nBarsSize; i++){
		if(strcmp(historgam.BarNames[i], strName)==0){
			historgam.nMaxBar = max(historgam.nMaxBar, ++historgam.Bars[i]);
			return true;
		}
	}
	return false;
}

// ������� AddBar ������� � ���������� historgam ����� ������� � ������ strName.
//-----------------------------------------------------------------
void AddBar(Histogram &historgam, const char *strName){
	char **newNames = new char *[historgam.nBarsSize+1];
	int   *newBars  = new int[historgam.nBarsSize+1];
	if(historgam.nBarsSize > 0){
		for(int i=0; i<historgam.nBarsSize; i++){
			newNames[i] = historgam.BarNames[i];
			newBars[i] = historgam.Bars[i];
		}
		delete[] historgam.BarNames;
		delete[] historgam.Bars;
	}

	newNames[historgam.nBarsSize] = new char[strlen(strName)+1];
	strcpy(newNames[historgam.nBarsSize], strName);
	newBars[historgam.nBarsSize] = 1;

	historgam.nBarsSize++;
	historgam.BarNames = newNames;
	historgam.Bars = newBars;
}

void SortByVal(Histogram& historgam, bool bAscending) 
{
	if (bAscending == true)
	{
		int p;
		char* h;
		for (int i = 0; i < historgam.nBarsSize; i++)
		{
			for (int j = 0; j < historgam.nBarsSize - i - 1; j++)
			{
				if (historgam.Bars[j] > historgam.Bars[j + 1]) {
					p = historgam.Bars[j];
					historgam.Bars[j] = historgam.Bars[j + 1];
					historgam.Bars[j + 1] = p;
					h = historgam.BarNames[j];
					historgam.BarNames[j] = historgam.BarNames[j + 1];
					historgam.BarNames[j + 1] = h;
				}
			}
		}
	}
	else
	{
		int p;
		char* h;
		for (int i = 0; i < historgam.nBarsSize; i++)
		{
			for (int j = 0; j < historgam.nBarsSize - i - 1; j++)
			{
				if (historgam.Bars[j] < historgam.Bars[j + 1]) {
					p = historgam.Bars[j];
					historgam.Bars[j] = historgam.Bars[j + 1];
					historgam.Bars[j + 1] = p;
					h = historgam.BarNames[j];
					historgam.BarNames[j] = historgam.BarNames[j + 1];
					historgam.BarNames[j + 1] = h;
				}
			}
		}
	}
}

