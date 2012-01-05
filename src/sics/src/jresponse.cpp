#include "jresponse.h"
#include <json/json.h>

namespace sicd
{

JResponse::JResponse(int flag)
{
    jo = json_object_new_object();
    json_object_object_add(jo, "ret", json_object_new_int(flag));
    jres = json_object_new_object();
    json_object_object_add(jres, "res", jo);
}



void JResponse::release()
{
    json_object_put(jo);
    json_object_put(jres);
}

string JResponse::to_json()
{
    return json_object_to_json_string(jres);
}

Cmsg::Cmsg(int flag,string msg):JResponse(flag), msg(msg)
{
    json_object_object_add(jo, "msg",json_object_new_string(msg.c_str()));
}

Cstatus::Cstatus(int flag,int count):JResponse(flag),count(count)
{
    json_object_object_add(jo, "count",json_object_new_int(count));
}

Cversion::Cversion(int flag,string version):JResponse(flag),version(version)
{
    json_object_object_add(jo, "version",json_object_new_string(version.c_str()));
}

}
