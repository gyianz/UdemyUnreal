// UdemyCourse.cpp : Defines the entry point for the console application.
//

// Preprocessor directive ( just before the compilation happens )
// <> for standard libraries (PATH)
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

// Function prototype
void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();
FBullCowGame BCGame; // instantiate a new game

int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	
	return 0;
}

void PrintIntro()
{
	// constant expression
	
	std::cout << "Welcome to my game" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of? \n";
}

FText GetGuess()
{
	int32 currentTry = BCGame.GetCurrentTry();

	// get a guess from the player
	std::cout << "\n Try " << currentTry << ". Enter your guess :";
	FText Guess = "";
	getline(std::cin, Guess);

	return Guess;
}


void PlayGame()
{

	BCGame.Reset();
	FBullCowCount BullCowCount;

	// loop for the number of turns asking for guesses
	
	for (int32 i = BCGame.GetCurrentTry(); i <= BCGame.GetMaxTries(); i++)
	{
		FText Guess = GetGuess();

		EWordStatus status = BCGame.CheckGuessValidity(Guess);

		switch (status)
		{
			case EWordStatus::Not_Char :
				std::cout << "Please remove any non characters from the input." << std::endl;
				break;
			case EWordStatus::Not_Isogram :
				std::cout << "There are duplicating chars in the input." << std::endl;
				break;
			case EWordStatus::Not_Equal_Length :
				std::cout << "Input string is different length from the hidden word." << std::endl;
				break;
			default :
				BullCowCount = BCGame.SubmitGuess(Guess);
				break;
		}
			
		std::cout << "Bulls : " << BullCowCount.Bulls;
		std::cout << " Cows : " << BullCowCount.Cows << std::endl;
		
		if (BCGame.IsGameWon(BullCowCount.Bulls))
		{
			return;
		}
	}

	std::cout << "Sorry you lost \n";
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)" << std::endl;
	FText Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}


