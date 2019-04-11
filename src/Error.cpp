#include "Error.h"
#include "lib.h"

char * Error::errorWhat()
{
	switch (errCode)
	{
	case errChoice: return "Incorrect choice";
	case errName: return "Error with name";
	case errMoney: return "Not enough money";
	case errCity: return "City error";
	case errLevel: return "Your level is too low";
	case errMove: return "You cannot move there!";
	case errSign: return "Incorrect sign";
	case errAlphabet: return "It is not a letter";
	case errFileName: return "There is no file like this";
	case errLitera: return "Error letter";
	case errTooShort: return "The word is too short";
	default: return "Unknown Error";
	}
}

Error::~Error()
{
}


bool correctChoice(string in, int x, int y)
{
	if (isdigit(static_cast<int>(in[0])))
	{
		int Ch = stoi(in);
		if (Ch >= x && Ch <= y) return true;
		else return false;
	}
	return false;
}