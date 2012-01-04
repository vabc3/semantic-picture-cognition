#include "jresponse.h"
#include <json/json.h>

namespace sicd
{

Jresponse::Jresponse(int flag):flag(flag)
{

}

Cmsg::Cmsg(int flag,string msg):Jresponse(flag), msg(msg) {}


string Cmsg::to_json()
{
    json_object *my_object = json_object_new_object();
    json_object_object_add(my_object, "flag", json_object_new_int(flag));
    json_object_object_add(my_object, "msg",json_object_new_string(msg.c_str()));
    string rt=json_object_to_json_string(my_object);
    json_object_put(my_object);

    return rt;
}


}


