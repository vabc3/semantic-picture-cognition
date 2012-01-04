/*
  {"req":{"cmd":"version","path":"/home/xx"}}
{"res":{"ret":"0","version":"version xxx"}}
  {"req":{"cmd":"match","path","/home/xx"}}
{"res":{"ret":"0",[{"img":"/home/xx/x.jpg","key":"keyisxx"}]}}
  {"req":{"cmd":"status"}}
{"res":{"ret":"0","count":32}}
  {"res":{"status":"1","msg":"Invalid command"}}
*/

#ifndef JRESPONSE_H
#define JRESPONSE_H
#include "jmsg.h"
#include <string>
using namespace std;
namespace sicd
{

class Jresponse :public Jmsg
{
    public:
        Jresponse(int flag);
        virtual string to_json()=0;
    protected:
        int flag;
};

class Cmsg :public Jresponse
{
    public:
        Cmsg(int flag,string msg);
        virtual string to_json();
    private:
        string msg;
};


static Cmsg errmsg(1,"Invalid command.");

}
#endif // JRESPONSE_H
