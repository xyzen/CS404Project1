#pragma once
class Vehicle
{
public:
	Vehicle();
	~Vehicle();
	int getID();
	int getType();
	int getZipCode();
	bool getAvail();
private:
	int ID;
	int type;
	int zipCode;
	bool avail;
};

