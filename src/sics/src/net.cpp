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
#include "jrequest.h"
#include "jresponse.h"

#include "cmdhanlder.h"

namespace sicd
{

Log Net::logger;

const int bufsize=8;
const int sizeprefix=4;

void Net::sockwrite(string st)
{
    char buf[4];
    int n =st.length();
    sprintf(buf,"%04d",n);
    string tmp(buf);
    write(csock,(tmp+st+'\n').c_str(),st.length()+5);
}

int Net::sockread(string &st)
{
    int n,c;
    char buf[5],sbuf[1024];
    buf[4]='\0';
    int rt=read(csock,buf,4);

    if(rt<0){
        logger.logr("Connect error");
        return -1;
    }else if((n=atoi(buf))<=0){
        logger.logr("Format error");
        return -1;
    }else{

        c=read(csock,sbuf,1024);
        sbuf[n]='\0';
    }
    string tmp(sbuf);
    st=tmp;
    return 0;
}


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

void Net::run()
{
    struct sockaddr_in remote_addr;


    Cmdhanlder ch;



    while(1)
    {
        socklen_t sin_size=sizeof(struct sockaddr_in);
        if((csock=accept(msock,(struct sockaddr *)&remote_addr,&sin_size))==-1)
        {
            perror("accept error\n");
            continue;
        }
        printf("received a connection from %s %u\n",inet_ntoa(remote_addr.sin_addr),ntohs(remote_addr.sin_port));
        //sockwrite(verinfo);
        cout<<"Welcome sended\n";
        //fcntl(csock, F_SETFL, O_NONBLOCK);

        string sts;
        int rt;
        while(1)
        {
            cout<<"{Inwire}\n";
            rt=sockread(sts);
            if(rt==-1){
                sockwrite(errfmt.to_json());
                break;
            }
            //cout<<sts<<endl;

            if(sts=="q")
            {
                write(csock,"bye\n",4);
               // close(csock);
                break;
            }
            JRequest jr(sts);
            JResponse jp=ch.process(jr);

            sockwrite(jp.to_json());
        }
        close(csock);
        printf("End_%s:%hx\n",inet_ntoa(remote_addr.sin_addr),remote_addr.sin_port);
        cout<<"Connection Ended\n";
    }
}
}
