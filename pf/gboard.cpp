#include "helper.h"
#include "setting.h"
#include "gboard.h"
#include <iostream>
#include <vector>
#include <ctime>   
#include <iomanip>
using namespace std;

void Gboard ::element(Gboard& board1) // assign element to the vector
{
    char elements[] = {' ',' ',' ','<','>','^','v','h','p','r'};
    numeoflements = 10;
    board1.board_.resize(grows); //create the empty rows base on grows

    for (int i = 0; i < grows; ++i)
    {
        board1.board_[i].resize(gcolumns); //resize each row with total columns base on gcolumns
    }

    for (int  y = 0 ; y < grows; ++y) //for every row,
    {
        for (int x = 0;  x < gcolumns; ++x) //for every column in that row,
        {
            numeoflements;
            int elementsNo = rand() % numeoflements; //get random element from the array "elements"
            board1.board_[y][x] = elements[elementsNo]; //and assign it, into the vector, board1.board_
        }
    }       
}

void Gboard::elementZombie(Gboard& board1)  //set zombie into the vector base on total zombie, range : 1-5
{
    int i = 0;
    while(i < gzombies) //loop base on how many zombie user entered;
    {
        int y = rand() % grows; int x = rand() % gcolumns; //to get rows and columns, a.k.a the index of the vector where y = rows, x = columns

        //below these are to check the random generated index whether have exisiting zombie or not. If the random generated index have existing zombie, then it will regerate new index again.
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
            char zombienum = '1';   // here is to assign the char '1' to '5'to indicate the no.of zombie base on how many loop it goes.
            board1.board_[y][x] = zombienum + i;
        }
        ++i;
    }
}

void Gboard::elementAlien(Gboard& board1) // set Alien to middle
{
    int y = ((grows-1)/2); int x = ((gcolumns-1)/2); //by using this formula.
    board1.board_[y][x] = 'A';
}

void Gboard::displayboard(Gboard& board1) // create gameboard
{
    int numofcharacter = 19;
    int width = (((gcolumns*2)+1)-numofcharacter)/2; // to make "Alien Vs Zombie" to middle

    string space = " ";
    cout << "  ";
    for (int i = 0; i < width ; ++i)
    {
        cout << space;
    }
    cout << ".:Alien Vs Zombie:." <<endl;

    for (int y = grows; y > 0; --y) //for every row,
    {
        int tempY = grows - y;  //for every loop, tempY will be 0,1,2,.... base on total rows. This is to sub this tempY into the vector board1.board_[tempY][X]. 
        cout << setw(4);

        for (int x = 0; x < gcolumns; ++x)  
        {
            cout << "+-";   //making the gameboard 
        }
        cout << "+" << endl;

        cout << setw(2) << (grows - y + 1); // to show the number of rows in ascending order. eg: if rows is 5, then 1,2,3,4,5.

        for (int x = 0; x < gcolumns; ++x)
        {
            cout << "|" << board1.board_[tempY][x]; //for every column, cout the elements that created in the vector justnow.
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
    cout << endl;
    cout << endl;
}