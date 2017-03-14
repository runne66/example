object=open62541.o server.o
ipv6server:$(object)
	gcc -o ipv6server $(object) -lrt

open62541.o: open62541.h
	gcc -std=c99 -c open62541.c -lrt
server.o:  open62541.c open62541.h
	gcc -std=c99 -c server.c -lrt
clean:
	rm ipv6server $(object)
