#pragma once

#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

// Strongly typed and scoped
enum class EWordStatus
{
	OK,
	Not_Isogram,
	Not_Equal_Length,
	Not_Char
};



class FBullCowGame
{

public:

	FBullCowGame();

	void Reset(); // TODO : create a more rich return value.
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon(int32 BullsCount) const;
	EWordStatus CheckGuessValidity(FString guess) const;

	FBullCowCount SubmitGuess(FString);


private:
	int32 CurrentTry;
	int32 MaxTries;
	FString HiddenWord;
	bool IsIsogram;

};
