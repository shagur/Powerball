//Powerball Simulator
//Class: 1106

#include <iostream>
#include <ctime>
using namespace std;

void enterBalls(int []);
void drawBalls(int []);
void determineMoney(int [], int []);

int main(){

	srand(time(NULL));

	int powerball[6], draw[6];

	enterBalls(powerball);	
	drawBalls(draw);
	determineMoney(powerball, draw);

	return 0;
}//end main

void enterBalls(int powerball[]){

	int i, j;

	for(i = 0; i < 6; i++){
		if(i < 5)
			cout << "Please enter white ball number " << i + 1 << ": ";
		else
			cout << "Please enter powerball: ";

		cin >> powerball[i];

		if(i < 5){
			while(powerball[i] < 1 || powerball[i] > 59){
				cout << "Input invalid, please re-enter a number between 1 and 59: ";
				cin >> powerball[i];
			}//end while
		}else
			while(powerball[i] < 1 || powerball[i] > 39){
				cout << "Input invalid, please re-enter a number between 1 and 39: ";
				cin >> powerball[i];
			}//end while

		for(j = 0; j < i; j++){
			while(powerball[i] == powerball[j] && i < 5){
				cout << "Input invalid, please re-enter a number that has not already been chosen: ";
				cin >> powerball[i];
				j = 0;
			}//end while
		}//end for
	}//end for
}//end Enter balls

void drawBalls(int draw[]){
	for(int i = 0; i < 6; i++){

		if(i < 5)
			draw[i] = 1 + rand() % 59;
		else
			draw[i] = 1 + rand() % 39;

		for(int j = 0; j < i; j++){
			while(draw[i] == draw[j] && i < 5){
				draw[i] = 1 + rand() % 59;
				j = 0;
			}
		}//end for	
	}//end for
}//end Draw balls

void determineMoney(int powerball[], int draw[]){
	int whiteMatch = 0, powerballMatch = 0;

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++)
			if(powerball[i] == draw[j]){
				if(i == 5)
					powerballMatch++;
				else
					whiteMatch++;
			}
	}//end for

	if(whiteMatch == 0 && powerballMatch == 1)
		cout << "You have won 3$";
	else if(whiteMatch == 1 && powerballMatch == 1)
		cout << "You have won 4$";
	else if(whiteMatch == 2 && powerballMatch == 1)
		cout << "You have won 7$";
	else if(whiteMatch == 3 && powerballMatch == 0)
		cout << "You have won 7$";
	else if(whiteMatch == 3 && powerballMatch == 1)
		cout << "You have won 100$";
	else if(whiteMatch == 4 && powerballMatch == 0)
		cout << "You have won 100$";
	else if(whiteMatch == 4 && powerballMatch == 1)
		cout << "You have won 10,000$";
	else if(whiteMatch == 5 && powerballMatch == 0)
		cout << "You have won 200,000$";
	else if(whiteMatch == 5 && powerballMatch == 1)
		cout << "You have won the Jackpot!";
	cout << endl;
}//end Determine Money