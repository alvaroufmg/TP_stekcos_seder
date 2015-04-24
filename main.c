#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "client.h"
#include <sys/types.h>
#include <sys/socket.h>

#define outport 789
#define inport	987

int main(int argc, char *argv[])
{
	struct sockaddr_in client;
	struct addrinfo hints, *res;
	int Conector;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

	client.sin_family = AF_UNSPEC;/*troquei de AF_INET para AF_UNSPEC*/
	client.sin_port = htons(atoi(argv[2]));
	client.sin_addr.s_addr = inet_addr(argv[1]);
	bzero(&(client.sin_zero),8);	

	getaddrinfo(argv[1], argv[2], &hints, &res);

	/*cria o socket*/
    	int socketAlv = socket(AF_INET,SOCK_STREAM,0);
    	ipKind ip;
	

	/*converte o formato de nome para ip ou ip para ip*/
    	ip = extractIP(argc,argv[1]);

	/*testa se socket foi criado caso negativo reotorna um erro*/
    	if(socketAlv < 0)
    	{
        	perror("Socket");
        	exit(1);
    	}
	

	bind(socketAlv,res->ai_addr, res->ai_addrlen);

	Conector = connect(socketAlv,(struct sockaddr * )&client, sizeof(client));

	if(Conector < 0)
	{
		perror("Connect");
		exit(1);
	}

	


    /*argv[1] = "150.164.49.158";
    argv[2] = "8080";*/
/*
    char *ipServ;
    char *port;
    char *directory;
    ipKind ip;

    strcpy(ipServ,argv[1]);
    strcpy(port,argv[2]);
    strcpy(directory,argv[3]);



    ip = extractIP(argc,ipServ);

    int Conector;


	Conector = creatSocket(argc,ipServ,port);

*/
    return 0;
}
