#include "helper.h"
#include "setting.h"
#include "gboard.h"
#include "object.h"
#include "gameplay1.h"
#include "stat.h"
using namespace std;

void Stat::getstat(Stat& stat1) 
{
    int zombieLifeStat[] = {100,150,200,250,300}; 
    int zombieAtkStat[] = {5,10,15,20,25,30}; 
    int zombieRangeStat[] = {1,2,3,4,5};
    
    int random1 = rand() % 5; 
    int random2 = rand() % 5; 
    int random3 = rand() % 5; 
    int random4 = rand() % 5; 
    int random5 = rand() % 5;

    for (int i = 1; i <= totalZombies; ++i)
    {
        switch (i)
        {
        case 1:
            zombie1Life =  zombieLifeStat[random1]; zombie1Atk =  zombieAtkStat[random1]; zombie1Range =  zombieRangeStat[random1];
            break;
        
        case 2:
            zombie2Life =  zombieLifeStat[random2]; zombie2Atk =  zombieAtkStat[random2]; zombie2Range =  zombieRangeStat[random2];
            break;

        case 3:
            zombie3Life =  zombieLifeStat[random3]; zombie3Atk =  zombieAtkStat[random3]; zombie3Range =  zombieRangeStat[random3];
            break;

        case 4:
            zombie4Life =  zombieLifeStat[random4]; zombie4Atk =  zombieAtkStat[random4]; zombie4Range =  zombieRangeStat[random4];
            break;

        case 5: 
            zombie5Life =  zombieLifeStat[random5]; zombie5Atk =  zombieAtkStat[random5]; zombie5Range =  zombieRangeStat[random5];
            break;    
        }
    }

}
