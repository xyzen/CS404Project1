#pragma once
struct Vehicle
{
	Vehicle();
<<<<<<< HEAD
	Vehicle(unsigned int, unsigned int, unsigned int);
	unsigned int zip, type, ID;
=======
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
>>>>>>> 72501ab31fd7c069f3f2b6ce6116f84a042e94c3
};
