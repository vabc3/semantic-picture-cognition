#include "cmdhanlder.h"
#include <iostream>
#include "sicw.h"
//#include <sic.h>
using namespace std;


namespace sicd
{



Cmdhanlder::Cmdhanlder()
{
    //ctor
}

Cmdhanlder::~Cmdhanlder()
{
    //dtor
}

JResponse Cmdhanlder::process(JRequest req)
{
    Sicw sw;

    cout <<req.cmd<<endl;
    if(req.cmd=="version"){
        Cversion cv(0,sw.getver());
        return cv;
    }else if(req.cmd=="status"){
        Cstatus cv(0,sw.getstatus());
        return cv;
    }else
        return errcmd;

}
}
