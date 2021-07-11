// Week 7 Assignment
// Rewrite the below using STRUCT 
// 
// Write a program to calculate a bowling league's average bowling scores
// 1.) Read data from file (BowlingScores.txt)
// 2.) Use a STRUCT:
//		- string data type for bowler names
//		- one dimensional array to store bowlers 4 scores
//		- int to store bowler average score
// 3.) Use functions
//		-Function called "GetBowlingData: to read and store data into STRUCT
//			*Inputs: File Name, Bowler Name (string data type), Bowling Score (1 dimensional array)
//			* return status of success or failure (true/false - bool)
//		-Function called "GetAverageScore" that is used to calculate the average bowling score
//			*Inputs: struct
//			*return - average score into struct
//		-Function called "PrettyPrintResults
//			*Output: bowler name, score, average
// USE GLOBAL CONSTANTS AT TOP OF PROGRAM UNDER INCLUDES
// Using a FOR Loop
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>



using namespace std;


const int row = 10;
const int col = 5;
ifstream inFile;
double sum = 0;
int bScores[row][col];


struct Bowlers {

	string bNames;
	int bScores[5];
	double bAverage = 0;
};

const auto bowlData = ("BowlingScores.txt");
void Greeting()
{
	cout << "************************************************************" << endl;
	cout << "***** Imperial Lanes Too Live Crew Scores and Averages *****" << endl;
	cout << "************************************************************" << endl;
	cout << endl;

}


//the below function opens the file BowlingScores.txt
//if it is open, it will store the names of the bowlers into an array bNames
// it will store the scores in a multidimension array bScores
void GetBowlingData(string bowlData, Bowlers sInfo[], int& scores)
{
	
	inFile.open(bowlData);
	
	if (inFile.is_open())
	{
		cout << "Too Live Crew coming soon to a lane near you..." << endl;
		cout << endl;
		cout << endl;
		
		for (int r = 0; r < 10; r++) {
			inFile >> sInfo[r].bNames;
			
			for (int c = 0; c < 5; c++)
			{
				inFile >> sInfo[scores].bScores[c];
			}
			
			scores++;
		}
		
		inFile.close();
		
		}
}

// this function is to calculate the average scores
// 
	void GetAverages(Bowlers sInfo[], int& scores)
	{
		int sum = 0;
		double bAverage[row];	
		
		//this iterates through the scores and adds them up, and then calculates the average
		for (int r = 0; r < 10; r++) {
			sum = 0;
			for (int c = 0; c < 5; c++)
			{
				sum += sInfo[r].bScores[c];
				
			}
			sInfo[r].bAverage = int (sum/5.0);
			
		}
		
	}

	//printing results
	void PrettyPrintResults(Bowlers sInfo[], int& scores)
	{
		//title for print results
		cout << "Name\t\tScore1\tScore2\tScore3\tScore4\tScore5\tAverage" << endl;
		
		//prints the results of the array bScores and bAverages to the console in a nested loop
		for (int r = 0; r < 10; r++) {
			cout << sInfo[r].bNames;

			sInfo[row].bNames.size() < 10 ? cout << '\t' << '\t' : cout << '\t';

			for (int col = 0; col < 5; col++)
			{
				cout << sInfo[r].bScores[col] << '\t';

			}

			cout << setprecision(2) << fixed << sInfo[r].bAverage << endl;
		}

	}

int main()
{
	
	//variables to pass into functions
	Bowlers sInfo[15];
	int scores = 0;

	
	//call to functions
	Greeting();
	GetBowlingData(bowlData, sInfo, scores);
	GetAverages(sInfo, scores);
	PrettyPrintResults(sInfo, scores);

	
	
	
	
	
}

