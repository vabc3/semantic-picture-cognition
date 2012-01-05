#ifndef SICW_H
#define SICW_H

#include <string>
using namespace std;
namespace sicd
{
class Sicw
{
public:
    Sicw();
    virtual ~Sicw();
    Sicw(const Sicw& other);
    string getver();
    int getstatus();
protected:
private:
};
}

#endif // SICW_H
