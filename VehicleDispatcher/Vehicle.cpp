<<<<<<< HEAD
#include "Vehicle.h"

Vehicle::Vehicle() {
	zip = 0; type = 0; ID = 0;
}

Vehicle::Vehicle(unsigned int z, unsigned int t, unsigned int id) {
	zip = z; type = t; ID = id;
}
=======
#include "Vehicle.h"

Vehicle::Vehicle()
{

}
Vehicle::Vehicle(int ID, int Type, int zipCode)
{
	this->setID(ID);
	this->setType(Type);
	this->setZipCode(zipCode);
}

Vehicle::~Vehicle()
{
}

int Vehicle::getID()
{
  return ID;
}

int Vehicle::getType()
{
  return type;
}

int Vehicle::getZipCode()
{
  return zipCode;
}

void Vehicle::setID(int id)
{
	this->ID = id;
}

void Vehicle::setType(int type)
{
	this->type = type;
}

void Vehicle::setZipCode(int zip)
{
	this->zipCode = zip;
}

bool Vehicle::getAvail()
{
  return avail;
}
  
>>>>>>> 72501ab31fd7c069f3f2b6ce6116f84a042e94c3
