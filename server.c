#include <signal.h>
#include "open62541.h"
UA_Boolean running = true;
void signalHandler(int sig) {
running = false;
}
int main(void) {
signal(SIGINT, signalHandler); /* catch ctrl-c */
UA_ServerConfig config = UA_ServerConfig_standard;
UA_ServerNetworkLayer nl = UA_ServerNetworkLayerTCP(UA_ConnectionConfig_standard, 16664);
config.networkLayers = &nl;
config.networkLayersSize = 1;
UA_Server *server = UA_Server_new(config);
UA_Server_run(server, &running);
UA_Server_delete(server);
nl.deleteMembers(&nl);
while(1);
return 0;
}
