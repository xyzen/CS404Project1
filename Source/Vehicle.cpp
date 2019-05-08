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
  
