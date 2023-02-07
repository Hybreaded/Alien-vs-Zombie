#ifndef PF_SETTING_H
#define PF_SETTING_H


class Defaultdata
{
    public :
    void setting(Defaultdata& data1);
    int nrows, ncolumns, nzombies;

    private :
    const int nrows_ = 3, ncolumns_ = 15, nzombies_ = 2; 
};


#endif
