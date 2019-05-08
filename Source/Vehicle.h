#pragma once
class Vehicle
{
public:
	Vehicle();
	Vehicle(int ID, int Type, int zipCode);
	~Vehicle();
	int getID();
	int getType();
	int getZipCode();
	void setID(int id);
	void setType(int type);
	void setZipCode(int zip);
	bool getAvail();
	
private:
	int ID;
	int type;
	int zipCode;
	bool avail;
};

