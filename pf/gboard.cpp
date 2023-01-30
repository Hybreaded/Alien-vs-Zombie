#include "helper.h"
#include "setting.h"
#include "gboard.h"
#include <iostream>
#include <vector>
#include <ctime>   
#include <iomanip>
using namespace std;

void Gboard ::element(Gboard& board1)
{
    char elements[] = {' ',' ',' ','<','>','^','v','h','p','r'};
    numeoflements = 10;
    board1.board_.resize(grows);

    for (int i = 0; i < grows; ++i)
    {
        board1.board_[i].resize(gcolumns); //resize each row a.k.a resize total column in that row
    }

    for (int  y = 0 ; y < grows; ++y)
    {
        for (int x = 0;  x < gcolumns; ++x)
        {
            numeoflements;
            int elementsNo = rand() % numeoflements;
            board1.board_[y][x] = elements[elementsNo];
        }
    }       
}

void Gboard::elementZombie(Gboard& board1)
{
    int i = 0;
    //cout << "gzombies = " << gzombies;
    while(i < gzombies)
    {
        int y = rand() % grows; int x = rand() % gcolumns;

        if (board1.board_[y][x] == '1')
        {
            continue;
        }
        if (board1.board_[y][x] == '2')
        {
            continue;
        }
        if (board1.board_[y][x] == '3')
        {
            continue;
        }
        if (board1.board_[y][x] == '4')
        {
            continue;
        }
        if (board1.board_[y][x] == '5')
        {
            continue;
        }
        else
        {
            char zombienum = '1';
            int j = 0;
            board1.board_[y][x] = zombienum + i;
            ++j;
        }
        ++i;
    }
}

void Gboard::elementAlien(Gboard& board1)
{
    int y = ((grows-1)/2); int x = ((gcolumns-1)/2);
    board1.board_[y][x] = 'A';
}

void Gboard::displayboard(Gboard& board1)
{
    int with = (((gcolumns-1) / 2)+1);  // to make "ALIEN VS ZOMBIE" to middle of gboard.
    string space = " ";
    if (grows >= 10)
    {
        cout << " ";
    }

    for (int i = 0; i < with ; ++i)
    {
        cout << space;
    }
    cout << ".:Alien Vs Zombie:." <<endl;

    for (int y = 0; y <grows; ++y ) 
    {
        cout << setw(4);

        for (int x = 0; x < gcolumns; ++x) 
        {
            cout << "+-";
        }
        cout << "+" << endl;

        cout << setw(2) << (grows - y); 

        for (int x = 0; x < gcolumns; ++x)
        {
            cout << "|" << board1.board_[y][x];
        }
        cout << "|" << endl;
    }    

    cout << setw(4);  //print last row
    for (int x = 0; x < gcolumns; ++x) 
    {
        cout << "+-";
    }
    cout << "+" << endl;
    cout << setw(3);

    for (int x = 0; x < gcolumns; ++x) //upper number
    {
        int num = ((x+1) / 10);
        cout << " ";
        if (num == 0)
        {
            cout << " ";
        }
        else
        {
            cout << num;
        }
    }
    cout << endl;
    cout << setw(3); 
    
    for (int x = 0; x < gcolumns; ++x) //lower number
    {
        cout << " " << ((x + 1)) % 10;
    }
    cout << "\t\t\t" <<endl;
    
}