#include "Vehicle.h"

Vehicle::Vehicle() {
	zip = 0; type = 0; ID = 0;
} // Constructs a default vehicle

Vehicle::Vehicle(unsigned int z, unsigned int t, unsigned int id) {
	zip = z; type = t; ID = id;
} // Constructs a vehicle based on passed arguments
