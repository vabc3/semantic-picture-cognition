/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Main sicd
 *
 *        Version:  1.0
 *        Created:  2012年01月01日 19时49分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karata Lau (kl), vabc3h@gmail.com
 *        Company:  ZJU
 *
 * =====================================================================================
 */


#include "net.h"
#include <signal.h>

using namespace sicd;


static void endsr(int sig)
{
    //printf("Sig:%d\n",sig);
    //cout
}

int main()
{
    signal(SIGINT, endsr);
    signal(SIGPIPE, endsr);

    Net ne(1213);
    ne.run();

	return 0;
}
