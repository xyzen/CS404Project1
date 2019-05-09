#include "Response.h"

Response::Response(unsigned int xreqID, unsigned int xtype, unsigned int xzip, unsigned int xvehID, unsigned int xdist, std::string xroute) {
	reqID = xreqID;
	type = xtype;
	zip = xzip;
	vehID = xvehID;
	dist = xdist;
	route = xroute;
}
