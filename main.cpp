//g++ main.cpp pf/helper.cpp -o testing

// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: T10L 
// Names: KOH TOM HAN | KU MING HIN |
// IDs: 1211103910 | 1211311715 | 
// Emails: 1211103910@student.mmu.edu.my | 1211311715@student.mmu.edu.my | 
// Phones: 0163666111 | 0122515491 | 
// ********************************************************* 

#include "pf/helper.h"
#include "pf/setting.h"
#include "pf/gboard.h"
#include "pf/object.h" 
#include "pf/gameplay.h"
#include "pf/stat.h"
#include <ctime>
using namespace std;


int main()
{
    Defaultdata data1;   //create data1 under class, Defaultdata 
    data1.setting(data1);  //call function with data1
    int nrows = data1.nrows; int ncolumns = data1.ncolumns; int nzombies = data1.nzombies; //assign value that user enter justnow where stored under data1. to new variable which is:
    
    Gboard board1; //create board1 under class, Gboard
    board1.grows = nrows; board1.gcolumns = ncolumns; board1.gzombies = nzombies; //assign the value nrows, ncolumns... to board1
    srand(time(NULL)); //to get random map everytime when compile the program
    board1.element(board1); //call function with board1
    board1.elementZombie(board1); 
    board1.elementAlien(board1);
    board1.displayboard(board1);

    Stat stat1; //create stat1 under class, Stat. || for this whole part, is basically getting the stat of the zombie.
    stat1.totalZombies = nzombies; // assign nzombies to stat1.totalzombies
    stat1.getstat(stat1); //call function.
    int zombie1Life = stat1.zombie1Life; int zombie1Atk = stat1.zombie1Atk; int zombie1Range = stat1.zombie1Range;
    int zombie2Life = stat1.zombie2Life; int zombie2Atk = stat1.zombie2Atk; int zombie2Range = stat1.zombie2Range;
    int zombie3Life = stat1.zombie3Life; int zombie3Atk = stat1.zombie3Atk; int zombie3Range = stat1.zombie3Range;
    int zombie4Life = stat1.zombie4Life; int zombie4Atk = stat1.zombie4Atk; int zombie4Range = stat1.zombie4Range;
    int zombie5Life = stat1.zombie5Life; int zombie5Atk = stat1.zombie5Atk; int zombie5Range = stat1.zombie5Range;

    Gameplay gameplay1; // this part not fully done yet, so no explain.
    gameplay1.game_ = board1.board_;
    gameplay1.totalrows = nrows; gameplay1.totalcolumns = ncolumns; gameplay1.totalZombies = nzombies; 
    gameplay1.alienLife = 100; gameplay1.alienAtk = 0;
    
    gameplay1.zombie1Life = zombie1Life; gameplay1.zombie1Atk = zombie1Atk; gameplay1.zombie1Range = zombie1Range;
    gameplay1.zombie2Life = zombie2Life; gameplay1.zombie2Atk = zombie2Atk; gameplay1.zombie2Range = zombie2Range;
    gameplay1.zombie3Life = zombie3Life; gameplay1.zombie3Atk = zombie3Atk; gameplay1.zombie3Range = zombie3Range;
    gameplay1.zombie4Life = zombie4Life; gameplay1.zombie4Atk = zombie4Atk; gameplay1.zombie4Range = zombie4Range;
    gameplay1.zombie5Life = zombie5Life; gameplay1.zombie5Atk = zombie5Atk; gameplay1.zombie5Range = zombie5Range;

    gameplay1.displayAttributes(gameplay1);
}

//  use this to compile all the file:
//  g++ main.cpp pf/helper.cpp pf/setting.cpp pf/gboard.cpp pf/object.cpp pf/gameplay.cpp pf/stat.cpp -o try

