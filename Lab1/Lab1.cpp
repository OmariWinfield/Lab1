#include <iostream>
#include "Header.h"
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	Programmer Progress[10];
	ifstream file("program11.txt");
	
	if (!file) {
		cout << "Error opening file!" << endl;
		return 1;
	}
	
	// Initialize all programmers to zero
	InitializeArray(Progress);
	
	// Read and process data
	cout << "PROGRAMMER PROGRESS\n\n";
	cout << "Programmer\tLines of Code\tLines of Comments\n\n";
	
	int progNum, code, comments;
	int winner = -1;
	
	while (file >> progNum >> code >> comments)
	{
		// Echo print the input
		cout << progNum << "\t\t" << code << "\t\t" << comments << endl;
		
		// Update the programmer's totals
		Progress[progNum - 1].codeLines += code;
		Progress[progNum - 1].Comments += comments;
		
		// Check if this programmer has won
		if (Progress[progNum - 1].codeLines > 1000)
		{
			winner = progNum;
			break;
		}
	}
	
	file.close();
	
	// Print final results
	cout << "\n";
	PrintTable(Progress, winner);
	
	// Find smallest k
	int k = FindSmallestK(Progress, winner);
	cout << "\nIt took programmers 1 through " << k 
	     << " to produce more than the winner.\n";
	
	return 0;
}

// Initialize all programmers' totals to zero
void InitializeArray(Programmer Programmers[])
{
	for (int i = 0; i < 10; i++)
	{
		Programmers[i].codeLines = 0;
		Programmers[i].Comments = 0;
	}
}

// Print final totals table with winner flagged
void PrintTable(Programmer Programmers[], int winner)
{
	cout << "FINAL TOTALS\n\n";
	cout << "Programmer\tLines of Code\tLines of Comments\n\n";
	
	for (int i = 0; i < 10; i++)
	{
		cout << (i + 1) << "\t\t" 
		     << Programmers[i].codeLines << "\t\t" 
		     << Programmers[i].Comments;
		
		// Flag the winner
		if ((i + 1) == winner)
		{
			cout << "\t** WINNER **";
		}
		
		cout << endl;
	}
}

// Find the smallest k such that programmers 1-k (excluding winner)
// have total lines > winner's total
int FindSmallestK(Programmer Programmers[], int winner)
{
	int winnerTotal = Programmers[winner - 1].codeLines;
	int sum = 0;
	int k = 0;
	
	for (int i = 0; i < 10; i++)
	{
		// Add to sum, but skip the winner if they're in the range
		if ((i + 1) != winner)
		{
			sum += Programmers[i].codeLines;
		}
		
		k = i + 1;
		
		// Check if we've exceeded the winner's total
		if (sum > winnerTotal)
		{
			break;
		}
	}
	
	return k;
}
