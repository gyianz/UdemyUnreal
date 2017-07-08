#include "FBullCowGame.h"
#include <algorithm>
#include <iostream>
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "PLANET";
	HiddenWord = HIDDEN_WORD;

	CurrentTry = 1;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return CurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return HiddenWord.length();
}

bool FBullCowGame::IsGameWon(int32 BullsCount) const
{
	if (BullsCount == GetHiddenWordLength())
	{
		std::cout << "Congrats you have won the game. \n";
		return true;
	}
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString guess) const
{

	if (guess.length() != GetHiddenWordLength())
	{
		return EWordStatus::Not_Equal_Length;
	}
	
	for (int i = 0; i < guess.length(); i++)
	{
		if (!isalpha(guess[i]))
		{
			return EWordStatus::Not_Char;
		}
		if (std::count(guess.begin(), guess.end(), guess[i]) > 1)
		{
			return EWordStatus::Not_Isogram;
		}
	}

	return EWordStatus::OK;
}



FBullCowCount FBullCowGame::SubmitGuess(FString submission)
{
	CurrentTry++;

	FBullCowCount BullCowCount;
	int32 hiddenLength = GetHiddenWordLength();

	//Get the submission
	// compare it against the hidden word
	
	for (int i = 0; i < hiddenLength; i++)
	{
		if (submission[i] == HiddenWord[i])
		{
			BullCowCount.Bulls++;
		}
		else
		{
			for (int j = 0; j < hiddenLength; j++)
			{
				if (submission[i] == HiddenWord[j])
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}