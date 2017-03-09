ipv6server:open62541.o server.o
	gcc -o ipv6server open62541.o server.o -lrt

open62541.o:open62541.c open62541.h
	gcc -std=c99 -c open62541.c -lrt
server.o:server.c  open62541.c open62541.h
	gcc -std=c99 -c server.c -lrt
clean:
	rm ipv6server server.o open62541.o
