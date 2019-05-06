#pragma once
#include "Vehicle.h"

class Request
{
public:
	Request();
	~Request();
	int getID();
	int getType();
	int getZipCode();
private:
	int ID;
	int type;
	int zipCode;
};

