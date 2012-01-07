#ifndef CMDHANLDER_H
#define CMDHANLDER_H

#include "jrequest.h"
#include "jresponse.h"
namespace sicd
{
class Cmdhanlder
{
    public:
        Cmdhanlder();
        virtual ~Cmdhanlder();
        JResponse process(JRequest req);
    protected:
    private:
};
}
#endif // CMDHANLDER_H
