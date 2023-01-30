// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TxxL 
// Names: MEMBER_NAME_1 | MEMBER_NAME_2 | MEMBER_NAME_3 
// IDs: MEMBER_ID_1 | MEMBER_ID_2 | MEMBER_ID_3 
// Emails: MEMBER_EMAIL_1 | MEMBER_EMAIL_2 | MEMBER_EMAIL_3 
// Phones: MEMBER_PHONE_1 | MEMBER_PHONE_2 | MEMBER_PHONE_3 
// ********************************************************* 

// TODO: Fill in the missing information above and delete this line.

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


/*void gamesetting(int br, int bc, int zc)
{
    
    cout<< "Board Rows"    << setw(6) << " :" <<br << endl
        << "Board Columns" << setw(3) << " :" <<bc << endl
        << "Zombie Count"  << setw(4) << " :" <<zc << endl;

}

int finalsetting(int row, int columns)
{
    //return pf::CreateGameBoard();
    return 0;
}

int main()
{
    /*cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl; 

    cout << "DEFAULT GAME SETTING" << endl;
    cout << "--------------------" << endl;
    gamesetting(3,5,1);

    char ans;
    cout << "Do you wish to change the game setting (y/n)?";
    cin >> ans; ans = toupper(ans);

    pf::ClearScreen();

    int count = 1, nrows, ncolumns, nzombies;
    if(ans == 'Y')
    {
        int count1 = 1;
        while(count1 > 0)
        {   cout << "Board Setting\n------------" << endl;
            cout << "Enter rows ==>  ";
            cin >> nrows;
            cout << "Enter columns ==>  ";
            cin >> ncolumns;

            cout << "Zombie Setting\n--------------" << endl;
            cout << "Enter the number of zombies ==> ";
            cin >> nzombies;

            if (nrows > 4 && nrows < 16 && ncolumns > 9 && ncolumns < 26 && nzombies > 0 && nzombies < 6)
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

    }
    else
    {
        cout << "Press to continue" << endl;
        pf::Pause();
    }
    
}*/

int main()
{   
    srand(time(NULL));
    int grows = 3; int gcolumns = 15;
    int y = rand() % grows; int x = rand() % gcolumns;
    cout << y << endl << x;
    
}

