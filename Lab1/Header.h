#pragma once
#include <iostream>
using namespace std;

struct Programmer 
{
	int codeLines;
	int Comments;
};

void FindWinner(Programmer Programmers[], int& winner);
void PrintTable(Programmer Programmers[], int winner);
void InitializeArray(Programmer Programmers[]);
int FindSmallestK(Programmer Programmers[], int winner);
