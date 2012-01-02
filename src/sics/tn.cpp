#include <netinet/in.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
static void logpid(const char *st)
{

    printf("[L%d]%s\n",getpid(),st);
}
static void endsr(int sig)
{

    printf("Sig:%d\n",sig);
    //exit(-3);
}
int main()
{
    int port =1213;
    struct sockaddr_in soin,remote_addr;
    int msock, csock;
    memset(&soin, 0, sizeof(struct sockaddr_in));
    soin.sin_family = AF_INET;

    // bind port
    const static int on=1;
    msock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    setsockopt(msock, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof(int));

    soin.sin_port = htons(port);
   
    logpid("Start");
//fcntl(STDOUT_FILENO, F_SETFL, O_NONBLOCK);
 signal(SIGTERM, endsr);
 //signal(SIGINT, endsr);
 signal(SIGPIPE, endsr);
 signal(SIGKILL, endsr);
    while(1)
    {
        printf("Into while Outer\n");
        socklen_t sin_size=sizeof(struct sockaddr_in);
        if((connect(msock,(struct sockaddr *)&soin,sin_size))==-1)
        {
            perror("conn error\n");
            break;
        }
        char buf[20];
   
        fd_set rfds,wfds;
        int tags;
        struct timeval timeout= {3,0};
        int wr=0;
        while(1)
        {
         bzero(buf,8);
           scanf("%s",buf);
            
           write(msock,buf,strlen(buf));              
         
            printf("After Write\n");
        }
        printf("Jump out\n");
    }

    return 0;
}
