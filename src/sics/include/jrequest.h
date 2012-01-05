#ifndef JREQUEST_H
#define JREQUEST_H

#include <string>
#include <json/json.h>
#include "net.h"
#include "jmsg.h"

using namespace std;
namespace sicd
{

class JRequest :public Jmsg
{
    public:
        friend class Cmdhanlder;
        JRequest(string cmd,string path);
        JRequest(string json);
        virtual ~JRequest();
        string to_json();
    private:
        string cmd,path;
        bool valid;
};
}
#endif // JREQUEST_H
