#include "sicw.h"
#include <sic.h>

using namespace sicd;
Sicw::Sicw()
{
    //ctor
}

Sicw::~Sicw()
{
    //dtor
}

Sicw::Sicw(const Sicw& other)
{
    //copy ctor
}

string Sicw::getver()
{
    char buf[255];
    sic_getver(buf);
    string tmp(buf);
    sic_debug();
    sic_init();
    sic_status(0,0);
    sic_end();
    return tmp;
}
