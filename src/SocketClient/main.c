#include "../Library/Client/client.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  
    int sockfd;
    struct addrinfo *servinfo;

    if (argc != 2) {
      fprintf(stderr, "usage: client hostname\n");
      exit(1);
    }

    servinfo = setup_connection(argv[1], PORT);
    if (servinfo == NULL) {
      return 1; //set up failed
    }

    sockfd = connection(servinfo);
    if (sockfd == -1) {
      freeaddrinfo(servinfo); // Handle err if connection fails and clear memory buffer
      return 2;
    }

    communicate(sockfd);
    freeaddrinfo(servinfo);
    return 0;
}