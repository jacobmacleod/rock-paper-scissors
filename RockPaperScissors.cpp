//============================================================================
// Name        : RockPaperScissors.cpp
// Author      : Jacob MacLeod
// Version     :
// Copyright   : 
// Description : Rock Paper Scissors game in C++
//============================================================================

#include <iostream>
using namespace std;

int getPlayerChoice(int score[]) {
	int playerChoice;
	cout << "Let's play Rock Paper Scissors!\n\n"
		"Player: " << score[0] << "\n"
		"Computer: " << score[1] << "\n"
		"Ties: " << score[2] << "\n\n"
		"Options:\n"
		"1. Rock\n"
		"2. Paper\n"
		"3. Scissors\n"
		"4. Quit Game\n"
		"Choose an option: ";
	cin >> playerChoice;
	return playerChoice;
}

void playGame(int playerChoice, int(&score)[]) {
	int computerChoice = (rand() % 3) + 1;
	int difference = playerChoice - computerChoice;
	if (difference == 0) {
		cout << "\nIt's a tie!\n\n";
		score[2] += 1;
	}
	else if (difference == 1 || difference == -2) {
		cout << "\nYou Win!\n\n";
		score[0] += 1;
	}
	else if (difference == -1 || difference == 2) {
		cout << "\nI Win!\n\n";
		score[1] += 1;
	}
}

int main() {
	int score[3] = { 0, 0, 0 };
	int playerChoice = 0;
	int difference = 0;
	bool isGoing = true;
	while (isGoing) {
		playerChoice = getPlayerChoice(score);
		if (playerChoice == 4) {
			isGoing = false;
		}
		else if (playerChoice <= 3 && playerChoice >= 1) {
			playGame(playerChoice, score);
		}
		else {
			cout << "Enter one of the numerals listed.\n\n";
			if (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}
	return 0;
}
