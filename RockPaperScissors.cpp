//============================================================================
// Name        : RockPaperScissors.cpp
// Author      : Jacob MacLeod
// Version     :
// Copyright   : 
// Description : Rock Paper Scissors game in C++
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int winsByPlayer = 0;
	int winsByComputer = 0;
	int ties = 0;
	int playerChoice = 0;
	int computerChoice = 0;
	int difference = 0;
	bool isGoing = true;
	while (isGoing) {
		cout << "Let's play Rock Paper Scissors!\n\n"
				"Player: " << winsByPlayer << "\n"
				"Computer: " << winsByComputer << "\n"
				"Ties: " << ties << "\n\n"
				"Options:\n"
				"1. Rock\n"
				"2. Paper\n"
				"3. Scissors\n"
				"4. Quit Game\n"
				"Choose an option: ";
		cin >> playerChoice;
		if (playerChoice == 4) {
			isGoing = false;
		}
		else if (playerChoice <=3 && playerChoice >= 1) {
			computerChoice = (rand() % 3) + 1;
			difference = playerChoice - computerChoice;
			if (difference == 0) {
				cout << "\nIt's a tie!\n\n";
				ties += 1;
			}
			else if (difference == 1 || difference == -2) {
				cout << "\nYou Win!\n\n";
				winsByPlayer += 1;
			}
			else if (difference == -1 || difference == 2) {
				cout << "\nI Win!\n\n";
				winsByComputer += 1;
			}

		}
		else {
			cout << "Enter one of the numerals listed.\n\n";
		}
	}
	return 0;
}
