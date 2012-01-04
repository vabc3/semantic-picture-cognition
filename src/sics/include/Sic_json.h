#ifndef SIC_JSON_H
#define SIC_JSON_H


namespace sicd
{


class Sic_json
{
public:

    typedef enum
    {
        Cstatus,Cmatch,Cversion
    } cmds;

    Sic_json();
    virtual ~Sic_json();

    void gen();

private:
};
}
#endif // SIC_JSON_H
