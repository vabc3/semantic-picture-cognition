#include "jrequest.h"


#include <iostream>
#include <cstdio>
using namespace std;

namespace sicd
{


JRequest::JRequest(string cmd,string path) : cmd(cmd),path(path)
{
    valid=true;
}

JRequest::JRequest(string jsonstr)
{
    valid=true;
    json_object *jobj,*p,*t;
    jobj = getobj(jsonstr);
    if (!jobj)
    {
        valid=false;
        return;
    }

    //json_object_object_foreach(jobj, key, val) {printf("\t%s: %s\n", key, json_object_to_json_string(val));}

    t=getobj(jobj,"req");
    if (!t)
    {
        valid=false;
        json_object_put(jobj);
        return;
    }

    cmd=getstr(t,"cmd");
    path=getstr(t,"path");
}

JRequest::~JRequest()
{
    //dtor
}

string JRequest::to_json()
{
    json_object *my_object = json_object_new_object();

    json_object_object_add(my_object, "cmd", json_object_new_string(cmd.c_str()));
    json_object_object_add(my_object, "path",json_object_new_string(path.c_str()));
    string rt=json_object_to_json_string(my_object);
    json_object_put(my_object);

    return rt;
}
}
