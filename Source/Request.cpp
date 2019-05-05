#include "Request.h"

Request::Request()
{
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
