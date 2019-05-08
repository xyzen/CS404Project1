#include "Request.h"

Request::Request()
{
}
Request::Request(int id, int type, int zip)
{
	this->ID = id;
	this->ID = type;
	this->ID = zip;
}


Request::~Request()
{
}

int Request::getID()
{
  return ID;
}

int Request::getType()
{
  return type;
}

int Request::getZipCode()
{
  return zipCode;
}
void Request::setID(int id)
{
	this->ID = id;
}

void Request::setType(int type)
{
	this->type = type;
}

void Request::setZipCode(int zip)
{
	this->zipCode = zip;
}
