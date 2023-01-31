#ifndef PF_STAT_H
#define PF_STAT_H
#include <vector>
using namespace std;

class Stat
{
    public:
    int totalZombies;
    int zombie1Life,  zombie1Atk, zombie1Range;
    int zombie2Life,  zombie2Atk, zombie2Range;
    int zombie3Life,  zombie3Atk, zombie3Range;
    int zombie4Life,  zombie4Atk, zombie4Range;
    int zombie5Life,  zombie5Atk, zombie5Range;
    void getstat(Stat& stat1);

};

#endif