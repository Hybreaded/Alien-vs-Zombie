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
    defaultgamesetting(nrows_ , ncolumns_ , nzombies_); // call funtion to show the default setting

    char ans;
    cout << "Do you wish to change the game setting (y/n)?";
    cin >> ans; 
    ans = toupper(ans); // change receive ans to upper letter

    pf::ClearScreen();

    data1.nrows = nrows_; data1.ncolumns = ncolumns_; data1.nzombies = nzombies_; //assign default setting value into board1.

    if(ans == 'Y') // if the user want to change value:
    {
        int count1 = 1; // using loop here because, later, if user key in invalid value, we need to use "continue;" to repeat the loop
        while(count1 > 0)
        {   cout << "Please re-enter a valid range [Rows and Columns must be in ODD values]" << endl;
            cout << "Enter rows (min: 3, max: 15) ==>  ";
            cin >> data1.nrows; // the name with data.nrows will store the value under the Class Default data, data1;
            cout << "Enter columns (min: 15, max: 29) ==>  ";
            cin >> data1.ncolumns; 

            cout << "Zombie Setting\n--------------" << endl;
            cout << "Enter the number of zombies (min: 1, max: 5) ==> ";
            cin >> data1.nzombies;

            if (data1.nrows > 2 && data1.nrows < 16 && data1.nrows %2 > 0
                && data1.ncolumns > 14 && data1.ncolumns < 31 && data1.ncolumns %2 > 0
                && data1.nzombies > 0 && data1.nzombies < 6)    // to check whether the user key in values are in odd number, and in between the range
            {
                    pf::ClearScreen();
                    count1 = 0; // if yes, count1=0; the loop will end
            }
            else
            {
                    cout << "Please re-enter a valid range" << endl; 
                    pf:: Pause();
                    pf::ClearScreen();
                    continue; // if no, the user need to enter the value again.
            }
        }
        cout << "Game setting has been updated" << endl; // after ending the loop, will tell user game setting has been change
        pf::Pause();   
        pf::ClearScreen();

    }
    else    //if user dw to change default setting, they will use the value of default setting
    {
        pf::Pause();
        pf::ClearScreen();
    }
} //back to main function