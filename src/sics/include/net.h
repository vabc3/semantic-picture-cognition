/*
 * =====================================================================================
 *
 *       Filename:  net.h
 *
 *    Description:  Net fore sicd
 *
 *        Version:  1.0
 *        Created:  2012年01月01日 22时27分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karata Lau (kl), vabc3h@gmail.com
 *        Company:  ZJU
 *
 * =====================================================================================
 */
#ifndef NET_H
#define NET_H

#include "util.h"
#include "sicw.h"

namespace sicd{
	class Net{
	    private:
            static Log logger;
            Sicw sicw;
            string verinfo;
            int port,msock,csock;
            void sockwrite(string st);
            int sockread(string& st);
		public:
			Net(int port);
			~Net();
			void run();
	};
}

#endif
