//g++ main.cpp pf/helper.cpp -o testing

// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TxxL 
// Names: KOH TOM HAN | KU MING HIN | MEMBER_NAME_3 
// IDs: MEMBER_ID_1 | MEMBER_ID_2 | MEMBER_ID_3 
// Emails: MEMBER_EMAIL_1 | MEMBER_EMAIL_2 | MEMBER_EMAIL_3 
// Phones: MEMBER_PHONE_1 | MEMBER_PHONE_2 | MEMBER_PHONE_3 
// ********************************************************* 

// TODO: Fill in the missing information above and delete this line.

#include "pf/helper.h"
#include "pf/setting.h"
#include "pf/gboard.h"
#include "pf/object.h" 
#include <ctime>
using namespace std;


int main()
{
    Defaultdata data1;
    data1.setting(data1);
    int nrows = data1.nrows ; int ncolumns = data1.ncolumns ;  int nzombies =  data1.nzombies;
    
    Gboard board1;
    board1.grows = nrows; board1.gcolumns = ncolumns; board1.gzombies = nzombies;
    srand(time(NULL));
    board1.element(board1);
    board1.elementZombie(board1);
    board1.elementAlien(board1);
    board1.displayboard(board1);

    Object object1;
    object1.temp = board1.board_; object1.alienhealth = 92;
    

}

//  use this to compile all the file:
//  g++ main.cpp pf/helper.cpp pf/setting.cpp pf/gboard.cpp pf/object.cpp -o try

