#include "gboard.h"
#include "setting.h"
#include "helper.h"
#include <iostream>
#include <iomanip>
using namespace std;

void defaultgamesetting(int br, int bc, int zc)
{
    
    cout<< "Board Rows"    << setw(6) << " :" <<br << endl
        << "Board Columns" << setw(3) << " :" <<bc << endl
        << "Zombie Count"  << setw(4) << " :" <<zc << endl;

}

void Defaultdata::setting(Defaultdata& data1)
{
    
    cout << "DEFAULT GAME SETTING" << endl;
    cout << "--------------------" << endl;
    defaultgamesetting(nrows_ , ncolumns_ , nzombies_);

    char ans;
    cout << "Do you wish to change the game setting (y/n)?";
    cin >> ans; 
    ans = toupper(ans); 

    pf::ClearScreen();

    data1.nrows = nrows_; data1.ncolumns = ncolumns_; data1.nzombies = nzombies_; 
    if(ans == 'Y') 
    {
        int count1 = 1;
        while(count1 > 0)
        {   cout << "Board Setting\n------------" << endl;
            cout << "Enter rows (min: 3, max: 15) ==>  ";
            cin >> data1.nrows; 
            cout << "Enter columns (min: 15, max: 29) ==>  ";
            cin >> data1.ncolumns; 

            cout << "Zombie Setting\n--------------" << endl;
            cout << "Enter the number of zombies (min: 1, max: 5) ==> ";
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
                    cout << "Please re-enter a valid range [Rows and Columns must be in ODD values]" << endl; 
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