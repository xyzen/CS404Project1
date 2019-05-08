#pragma once
#include "Vehicle.h"

class Request
{
public:
	Request();
	Request(int id,int type,int zip);
	~Request();
	int getID();
	int getType();
	int getZipCode();
	void setID(int id);
	void setType(int type);
	void setZipCode(int zip);
private:
	int ID;
	int type;
	int zipCode;
};

