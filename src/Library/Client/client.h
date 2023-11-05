#ifndef CLIENT_H
#define CLIENT_H

#include <netinet/in.h>

#define PORT "5000"
#define MAXDATASIZE 100 //max number of bytes to obtain at once

//prototypes

void *get_in_addr(struct sockaddr *sa);
struct addrinfo *setup_connection(const char *hostname, const char *port);
int connection(struct addrinfo *servinfo);
void communicate(int sockfd);

#endif