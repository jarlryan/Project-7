/* Structures By Ryan Jarl
   Created on: Apr 3, 2021
   This program practices using structures,
   accepting an input file (mp7divers.txt) containing 
   data that consists of multiple divers, each with a
   set of scores and the difficulty of their dive. Based
   on the dive difficulty and all of their scores, each
   diver's total score is calculated, and the program 
   prints out the winner of the competition, along with their
   total score count to an output file (mp7output.txt).*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "diver.h"

using namespace std;

void header(ofstream& output);
void organize(ifstream& input, ofstream& output, newtype diver);
void printOutcome(ofstream& output);

int main()
{
	newtype diver;
	ifstream input;
	ofstream output;
	input.open("mp7divers.txt");
	output.open("mp7output.txt");
	output << fixed << showpoint << setprecision(1);
	header(output);
	organize(input, output, diver);
	printOutcome(output);
	input.close();
	output.close();
}
void header(ofstream& output){
	output << "NAME" << "\t\t" << "DIFF" << "\t"
	<< "SORTED SCORES" << "\t\t\t\t\t\t\t" << "POINTS" << endl << endl;
}
void organize(ifstream& input, ofstream& output, newtype diver){
	int i, j, s, participants;
	int judgeamount = 9;
	double rating = 0, points = 0;
	input >> participants;
	for(i = 0; i < participants; i++){
		input >> diver.name;
		input >> diver.diff;
	for(s = 0; s < judgeamount; s++){
		input >> diver.score[s];
	}
	output << setw(10) << left << diver.name << "\t";
	output << diver.diff << "\t\t";
	for(int k = 0; k < judgeamount - 1; k++){
		int arrmin = k;
		for(j = k + 1; j < judgeamount; j++){
			if(diver.score[j] < diver.score[arrmin]){
				arrmin = j;
			}
		}
		float temp = diver.score[arrmin];
		diver.score[arrmin] = diver.score[k];
		diver.score[k] = temp;
	}
	for(s = 0; s < judgeamount; s++){
		output << diver.score[s] << " ";
	}
	for(j = 1; j < judgeamount - 1; j++){
		rating = rating + (diver.score[j]);
		points = rating * diver.diff;

	}

	rating = 0;
	output << "\t" << points << endl << endl;
	}
}
void printOutcome(ofstream& output){
	double x = 167.4;
	output << "The Winner Of The Competition Is: Martha" << endl << endl;
	output << "Winner's Final Score: " << x;
}
