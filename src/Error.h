#pragma once
#include "lib.h"
class Error
{
public:
	Error(int code) :errCode(code) {};
	char * errorWhat();
	~Error();

	enum { errChoice,errName,errMoney,errCity,errLevel,errMove, errSign, errAlphabet, errFileName, errLitera,errTooShort };
protected:
	int errCode;
};

//is digit() isalpha();

