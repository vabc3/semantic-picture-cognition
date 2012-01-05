#ifndef JMSG_H
#define JMSG_H
#include <string>
#include <json/json.h>
using namespace std;

namespace sicd
{
class Jmsg
{
    public:
        Jmsg();
        virtual string to_json()=0;
    protected:
        json_object* getobj(string);
        json_object* getobj(json_object *obj,string);
        string getstr(json_object *obj,string);
        friend ostream& operator<< (ostream & os,Jmsg &t1);
    private:
};
}
#endif // JMSG_H
