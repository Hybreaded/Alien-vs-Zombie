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
#include <cstring>
using namespace std;

class TRY
{
  public:
  int test1;
  void pass(TRY& trying);

  private:

};

void TRY::pass(TRY& trying)
{
  cout << test1 << " ok";
}

int main()
{
  srand(time(NULL));
  /*TRY trying;
  trying.test1 = 666;
  trying.pass(trying);*/


  char ans[5];
  cout << "ans  ";
  cin >> ans;
  char arrow[] = "ARROW";
  //ARROW

  for (int i = 0; i < strlen(ans); ++i)
  {
    cout << "compare = " << strcmp(ans,arrow) <<endl;
    cout << "char ans = " << ans[i] << " char arrow = "<< arrow[i]<<endl; 

    if (strcmp(ans,arrow) != 0 || ans[i] != arrow[i])
    {
      cout << "Please enter correct characters (Arrow)"<< endl << endl;
      std::system("pause");
    }
  }

  
  //char arrowZ[] = "ARROW";
  
  //cout << strcmp(arrowZ, arrow );
  
}