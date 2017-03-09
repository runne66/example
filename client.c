#include "open62541.h"
int main(void) {
	UA_Client *client = UA_Client_new(UA_ClientConfig_standard);
	UA_StatusCode retval = UA_Client_connect(client, "opc.tcp://fe80::20c:29ff:fe00:b7e2/64:16664");
	if(retval != UA_STATUSCODE_GOOD) {
	UA_Client_delete(client);
	return retval;
	}
	UA_Client_disconnect(client);
	UA_Client_delete(client);
	while(1);
	return 0;
}
