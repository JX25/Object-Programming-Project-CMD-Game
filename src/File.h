#pragma once
#include "lib.h"
#include "Town.h"
#include <fstream>
#include <sstream>

class File
{

public:
	void static save();
	void static readFromFile();
	File();
	~File();
};

