#include "gboard.h"
#include "setting.h"
#include "helper.h"
#include <iostream>
#include <iomanip>
using namespace std;

Defaultdata::Defaultdata()
{
    nrows = 3 ; ncolumns = 15 ; nzombies = 2;
    nrows_ = 3 ; ncolumns_ = 15 ; nzombies_ = 2;
}

void defaultgamesetting(int br, int bc, int zc)
{
    
    cout<< "Board Rows"    << setw(6) << " :" <<br << endl
        << "Board Columns" << setw(3) << " :" <<bc << endl
        << "Zombie Count"  << setw(4) << " :" <<zc << endl;

}

void displaydata(Defaultdata& data1)
{
    cout<< "Board Rows"    << setw(6) <<" :" <<data1.nrows << endl         
        << "Board Columns" << setw(3) <<" :" <<data1.ncolumns << endl
        << "Zombie Count"  << setw(4) <<" :" <<data1.nzombies << endl;
}

void Defaultdata::setting(Defaultdata& data1)
{
    
    cout << "DEFAULT GAME SETTING" << endl;
    cout << "--------------------" << endl;
    defaultgamesetting(nrows , ncolumns , nzombies);

    char ans;
    cout << "Do you wish to change the game setting (y/n)?";
    cin >> ans; 
    ans = toupper(ans);

    pf::ClearScreen();

    if(ans == 'Y')
    {
        int count1 = 1;
        while(count1 > 0)
        {   cout << "Board Setting\n------------" << endl;
            cout << "Enter rows ==>  ";
            cin >> data1.nrows;
            cout << "Enter columns ==>  ";
            cin >> data1.ncolumns;

            cout << "Zombie Setting\n--------------" << endl;
            cout << "Enter the number of zombies ==> ";
            cin >> data1.nzombies;

            if (data1.nrows > 2 && data1.nrows < 16 && data1.nrows %2 > 0
                && data1.ncolumns > 14 && data1.ncolumns < 31 && data1.ncolumns %2 > 0
                && data1.nzombies > 0 && data1.nzombies < 6)
            {
                    pf::ClearScreen();
                    count1 = 0;
            }
            else
            {
                    cout << "Please re-enter a valid range" << endl;
                    pf:: Pause();
                    pf::ClearScreen();
                    continue;
            }
        }
        cout << "Game setting has been updated" << endl;
        pf::Pause();
        pf::ClearScreen();

    }
    else
    {
        pf::Pause();
        pf::ClearScreen();
    }
} 