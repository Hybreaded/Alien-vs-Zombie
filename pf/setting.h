#ifndef PF_SETTING_H
#define PF_SETTING_H


class Defaultdata
{
    public :
    Defaultdata();
    void setting(Defaultdata& data1);
    int nrows, ncolumns, nzombies;

    private :
    int nrows_, ncolumns_, nzombies_;
};


#endif
