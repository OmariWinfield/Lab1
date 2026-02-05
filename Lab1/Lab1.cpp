#include <iostream>
#include "Header.h"
#include <fstream>
using namespace std;
int main()
{
	Programmer Progress[10];
	while (Progress.codeLines > 1000)
	{
		ifstream file("program11.txt");
		
	}
}

/*
// program1.cpp
// CSC326 Program 1 - Review of C++ Programming Constructs
// This program tracks programmers' progress in a coding contest

#include <iostream>
#include <fstream>
#include <iomanip>
#include "programmer.h"

using namespace std;

// Function prototypes
void initializeProgrammers(Programmer programmers[], int size);
int readAndProcessData(ifstream& inFile, Programmer programmers[], int size);
void printFinalTotals(Programmer programmers[], int size, int winner);
int findSmallestK(Programmer programmers[], int size, int winner);

int main() {
    const int NUM_PROGRAMMERS = 10;
    Programmer programmers[NUM_PROGRAMMERS];
    ifstream inFile;
    int winner;
    int k;
    
    // Initialize all programmers to zero
    initializeProgrammers(programmers, NUM_PROGRAMMERS);
    
    // Open the input file
    inFile.open("program11.txt");
    if (!inFile) {
        cout << "Error opening input file!" << endl;
        return 1;
    }
    
    // Read and process data
    cout << "PROGRAMMER PROGRESS" << endl << endl;
    cout << "Programmer  Lines of Code  Lines of Comments" << endl << endl;
    
    winner = readAndProcessData(inFile, programmers, NUM_PROGRAMMERS);
    
    // Print final totals
    cout << endl;
    printFinalTotals(programmers, NUM_PROGRAMMERS, winner);
    
    // Find smallest k
    k = findSmallestK(programmers, NUM_PROGRAMMERS, winner);
    
    cout << endl;
    cout << "It took programmers 1 through " << k 
         << " to produce more than the winner." << endl;
    
    // Close the file
    inFile.close();
    
    return 0;
}

// Initialize all programmers' totals to zero
void initializeProgrammers(Programmer programmers[], int size) {
    for (int i = 0; i < size; i++) {
        programmers[i].linesOfCode = 0;
        programmers[i].linesOfComments = 0;
    }
}

// Read data and process until someone reaches >1000 lines of code
// Returns the programmer number (1-10) of the winner
int readAndProcessData(ifstream& inFile, Programmer programmers[], int size) {
    int progNum, code, comments;
    int winner = -1;
    
    while (inFile >> progNum >> code >> comments) {
        // Echo print the input
        cout << setw(4) << progNum << setw(15) << code 
             << setw(18) << comments << endl;
        
        // Update the programmer's totals (array is 0-indexed, programmer numbers are 1-10)
        programmers[progNum - 1].linesOfCode += code;
        programmers[progNum - 1].linesOfComments += comments;
        
        // Check if this programmer has won
        if (programmers[progNum - 1].linesOfCode > 1000) {
            winner = progNum;
            break;
        }
    }
    
    return winner;
}

// Print final totals with winner flagged
void printFinalTotals(Programmer programmers[], int size, int winner) {
    cout << "FINAL TOTALS" << endl << endl;
    cout << "Programmer  Lines of Code  Lines of Comments" << endl << endl;
    
    for (int i = 0; i < size; i++) {
        cout << setw(4) << (i + 1) 
             << setw(15) << programmers[i].linesOfCode
             << setw(18) << programmers[i].linesOfComments;
        
        // Flag the winner
        if ((i + 1) == winner) {
            cout << " ** WINNER **";
        }
        
        cout << endl;
    }
}

// Find the smallest k such that programmers 1-k (excluding winner if in range)
// have total lines > winner's total
int findSmallestK(Programmer programmers[], int size, int winner) {
    int winnerTotal = programmers[winner - 1].linesOfCode;
    int sum = 0;
    int k = 0;
    
    for (int i = 0; i < size; i++) {
        // Add to sum, but skip the winner if they're in the range
        if ((i + 1) != winner) {
            sum += programmers[i].linesOfCode;
        }
        
        k = i + 1;
        
        // Check if we've exceeded the winner's total
        if (sum > winnerTotal) {
            break;
        }
    }
    
    return k;
}
*/
