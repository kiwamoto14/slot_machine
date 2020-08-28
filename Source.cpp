#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

int main() {

	int numTokens;
	int randNum1;
	int randNum2;
	int randNum3;
	char playAgain;
	char random = 's';

	system("Color 7C");

	while (random != 'Y' && random != 'y' && random != 'n' && random != 'N') {
		cout << "Would you like to be assigned a random token amount? (y/n)" << endl;
		cin >> random;

		srand(time(0));

		if (random == 'Y' || random == 'y') {
			numTokens = (rand() % 200) + 5;
			cout << "You will start with " << numTokens << " tokens." << endl;
			Sleep(2000);
		}
		else if (random == 'N' || random == 'n') {
			cout << "Please enter the number of tokens you wish to start with" << endl;
			cin >> numTokens;
			cout << "You will start with " << numTokens << " tokens." << endl;
			Sleep(2000);
		}
		else {
			cout << "That is not a valid answer" << endl;
		}
	}

	//srand(time(0));

	cout << endl;
	do {
		numTokens = numTokens - 5;
		randNum1 = (rand() % 7) + 1; // generate 1st random number
		cout << "*" << randNum1 << "*  ";
		Sleep(2000);
		randNum2 = (rand() % 7) + 1; // generate 2nd random number
		cout << "*" << randNum2 << "*  ";
		Sleep(2000);
		randNum3 = (rand() % 7) + 1; // generate 3rd random number
		cout << "*" << randNum3 << "*" << endl << endl;
		Sleep(1000);

		if ((randNum1 == 7) && (randNum2 == 7) && (randNum3 == 7)) {
			numTokens = numTokens + 500; // award for jackpot
			cout << "***************" << endl;
			cout << "*  JACKPOT!!  *" << endl;
			cout << "***************" << endl << endl;
			Sleep(1000);
			cout << "You have " << numTokens << " tokens.";
		}
		else if ((randNum1 == randNum2) && (randNum2 == randNum3)) {
			numTokens = numTokens + 100; // award for triple
			cout << "***************" << endl;
			cout << "*   TRIPLE!!  *" << endl;
			cout << "***************" << endl << endl;
			Sleep(1000);
			cout << "You have " << numTokens << " tokens.";
		}
		else if ((randNum1 + 1 == randNum2) && (randNum2 + 1 == randNum3)) {
			numTokens = numTokens + 50; // award for straight
			cout << "***************" << endl;
			cout << "*  STRAIGHT!! *" << endl;
			cout << "***************" << endl << endl;
			Sleep(1000);
			cout << "You have " << numTokens << " tokens.";
		}
		else if ((randNum1 == randNum2) || (randNum2 == randNum3) || (randNum1 == randNum3)) {
			numTokens = numTokens + 3; // award for double
			cout << "***************" << endl;
			cout << "*   DOUBLE!!  *" << endl;
			cout << "***************" << endl << endl;
			Sleep(1000);
			cout << "You have " << numTokens << " tokens.";
		}
		else {
			cout << "***LOSER!!***" << endl << endl;
			Sleep(1000);
			cout << "You have " << numTokens << " tokens." << endl;
		}

		if (numTokens >= 5) {
			cout << "Would you like to play again? (y/n)" << endl;
			cin >> playAgain; // y if user wants to continue, n if user doesn't want to continue
			if (playAgain == 'y') {
				cout << endl << endl;
			}
			else {
				cout << endl;
			}
		}
		else {
			cout << endl << "Sorry, you need 5 tokens to play." << endl;
		}
	} while ((numTokens >= 5) && (playAgain == 'y'));


	cout << "Thank you for playing.  Come again." << endl; // message when loop ends


	return 0;
}
