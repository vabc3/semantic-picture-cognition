#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>
#define SERVPORT 1212
#define BACKLOG  2
#define dataSize 100
int maind()
{
    int sockfd,client_fd;
    struct sockaddr_in my_addr,remote_addr;
    //char buf[dataSize] ;
    fd_set rfds,wfds;

    struct timeval timeout= {3,0};
    int tags;

    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {

        perror("socket create erro");
        exit(1);
    }
    my_addr.sin_port=htons(SERVPORT);
    my_addr.sin_family=AF_INET;
    my_addr.sin_addr.s_addr=INADDR_ANY;
    bzero(&(my_addr.sin_zero),8);

    if(bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))==-1)
    {
        perror("bind error");
        exit(1);
    }
    if(listen(sockfd,BACKLOG)==-1)
    {
        perror("lister error");
        exit(1);
    }

    while(1)
    {
        socklen_t sin_size=sizeof(struct sockaddr_in);
        if((client_fd=accept(sockfd,(struct sockaddr *)&remote_addr,&sin_size))==-1)
        {

            perror("accept error");
            continue;
        }

        printf("received a connection from %s\n",inet_ntoa(remote_addr.sin_addr));

        if(!fork())
        {
            char content[50];
            printf("I'm child");

        }
        close(client_fd);
    }
}
