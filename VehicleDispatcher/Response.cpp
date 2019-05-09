#include "Response.h"

Response::Response(unsigned int xreqID, unsigned int xtype, unsigned int xzip, unsigned int xid, unsigned int xdist, std::string xroute) {
	reqID = xreqID;
	type = xtype;
	zip = xzip;
	id = xid;
	dist = xdist;
	route = xroute;

}
