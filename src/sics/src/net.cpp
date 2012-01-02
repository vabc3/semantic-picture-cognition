/*
 * =====================================================================================
 *
 *       Filename:  net.cpp
 *
 *    Description:  impl net
 *
 *        Version:  1.0
 *        Created:  2012年01月01日 22时28分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karata Lau (kl), vabc3h@gmail.com
 *        Company:  ZJU
 *
 * =====================================================================================
 */
#include <iostream>
#include <netinet/in.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "net.h"
#include "sicw.h"

namespace sicd
{

Log Net::logger;


Net::Net(int port)
{
    verinfo=sicw.getver()+"_Server";
    cout<<(verinfo)<<endl;
    this->port=port;

    struct sockaddr_in soin;
    const static int on=1;

    bzero(&soin, sizeof(struct sockaddr_in));
    soin.sin_family = AF_INET;

    msock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    setsockopt(msock, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof(int));
    soin.sin_port = htons(port);
    if (bind(msock, (struct sockaddr *) & soin, sizeof(struct sockaddr_in)) == -1)
    {
        logger.logr("Error: Can't bind to port");
        exit(-1);
    }
    if (listen(msock, 4) < 0)
    {
        logger.logr("Error: Can't listen to %d. (errno %d)\n");
       exit(-1);
    }

    logger.logr("Start OK");
}

Net::~Net()
{
    close(msock);
}

void Net::sockwrite(string st)
{
    write(csock,(st+"\n").c_str(),st.length()+1);
}


const int bufsize=8;
void Net::run()
{
    struct sockaddr_in remote_addr;

    char buf[bufsize];

    while(1)
    {
        socklen_t sin_size=sizeof(struct sockaddr_in);
        if((csock=accept(msock,(struct sockaddr *)&remote_addr,&sin_size))==-1)
        {
            perror("accept error\n");
            continue;
        }

        printf("received a connection from %s %u\n",inet_ntoa(remote_addr.sin_addr),ntohs(remote_addr.sin_port));

        sockwrite(verinfo);

        cout<<"Welcome sended\n";


        //fcntl(csock, F_SETFL, O_NONBLOCK);

        int wr=0,rt;
        string sts;
        while(1)
        {
            sts="";
            while((rt=read(csock,buf,bufsize))>0){
                int i;
                printf("%ld:::",strlen(buf));


                string tmp(buf);
                cout<<"{rt="<<rt<<",Conetent:";

                for(i=0;i<strlen(buf);i++){
                    printf("%d|",buf[i]);
                }

                cout<<"}"<<endl;
                sts+=tmp;
                bzero(buf,bufsize);
            }

            cout<<sts<<endl;

            if(rt<0)
                break;

            if(buf[0]=='q')
            {
                write(csock,"bye\n",4);

                close(csock);
                printf("End_%s:%hx\n",inet_ntoa(remote_addr.sin_addr),remote_addr.sin_port);
                break;
            }

            int rt=-1;
            if((rt=write(csock,buf,3))<0)
            {
                printf("rt=%d\n",rt);
                break;
            }
        }
        cout<<"Connection Ended\n";
    }
}
}
