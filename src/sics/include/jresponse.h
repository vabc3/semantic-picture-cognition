/*
  {"req":{"cmd":"version","path":"/home/xx"}}
  {"res":{"ret":"0","version":"version xxx"}}
  {"req":{"cmd":"match","path","/home/xx"}}
{"res":{"ret":"0",[{"img":"/home/xx/x.jpg","key":"keyisxx"}]}}
  {"req":{"cmd":"status"}}
  {"res":{"ret":"0","count":32}}
  {"res":{"ret":"1","msg":"Invalid command"}}
*/

#ifndef JRESPONSE_H
#define JRESPONSE_H
#include "jmsg.h"
#include <string>
using namespace std;
namespace sicd
{

class JResponse :public Jmsg
{
    public:
        JResponse(int flag);
        void release();
        string to_json();
    protected:
        json_object *jo;
    private:
        json_object *jres;
};

class Cmsg :public JResponse
{
    public:
        Cmsg(int flag,string msg);
    private:
        string msg;
};

static Cmsg errcmd(1,"Invalid command.");
static Cmsg errfmt(1,"Invalid format.");

class Cstatus : public JResponse
{
    public:
        Cstatus(int flag,int count);
    private:
        int count;
};


class Cversion : public JResponse
{
    public:
        Cversion(int flag,string version);
    private:
        string version;
};

}
#endif // JRESPONSE_H
