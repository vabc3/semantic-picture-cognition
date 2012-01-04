#include "jmsg.h"
#include <iostream>
namespace sicd
{


Jmsg::Jmsg()
{
}
ostream & operator << (ostream & os,Jmsg &t1)
{
    os << t1.to_json();
    return os;
}

json_object* Jmsg::getobj(string jsonstr)
{
    json_object *jobj = json_tokener_parse(jsonstr.c_str());
    if (is_error(jobj)||(json_object_get_type(jobj)!=json_type_object))
    {
        return NULL;
    }
    return jobj;
}


json_object* Jmsg::getobj(json_object *obj,string key)
{
    json_object *rt;
    if(json_object_get_type(obj)!=json_type_object)
    {
        return NULL;
    }
    rt=json_object_object_get(obj,key.c_str());

    if(!rt||is_error(rt))
    {
        return NULL;
    }

    if(json_object_get_type(rt)!=json_type_object)
    {
        json_object_put(rt);
        return NULL;
    }

    return rt;
}

string Jmsg::getstr(json_object *obj,string key)
{
    json_object *rt;

    if(json_object_get_type(obj)!=json_type_object)
    {
        return "";
    }
    rt=json_object_object_get(obj,key.c_str());

    if(!rt||is_error(rt))
    {
        return "";
    }

    if(json_object_get_type(rt)!=json_type_string)
    {
        json_object_put(rt);
        return "";
    }

    return json_object_get_string(rt);
}
}
