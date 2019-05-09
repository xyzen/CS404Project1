#pragma once
struct Vehicle
{
	// Constructors
	Vehicle();
	Vehicle(unsigned int zip, unsigned int type, unsigned int id);

	// Primative members
	unsigned int zip, type, ID;
};
