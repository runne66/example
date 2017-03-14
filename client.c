#include "open62541.h"
#include "stdio.h"
int main(int argc, char *argv[])
{
	UA_Client *client = UA_Client_new(UA_ClientConfig_standard);
	UA_StatusCode retval = UA_Client_connect(client, "opc.tcp://ip6-localhost:16664");
	if(retval != UA_STATUSCODE_GOOD) {
	UA_Client_delete(client);
	return retval;
	 }
   	 UA_Int32 value = 0;
    printf("\nReading the value of node (1, \"the.answer\"):\n");
    UA_Variant *val = UA_Variant_new();
    retval = UA_Client_readValueAttribute(client, UA_NODEID_STRING(1, "the.answer"), val);
    if(retval == UA_STATUSCODE_GOOD && UA_Variant_isScalar(val) &&
       val->type == &UA_TYPES[UA_TYPES_INT32]) {
            value = *(UA_Int32*)val->data;
            printf("the value is: %i\n", value);
    }
    UA_Variant_delete(val);
   	 UA_Client_delete(client); /* Disconnects the client internally */
   	 return retval;
}
