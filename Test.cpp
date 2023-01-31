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

void trylol(vector<int> &vec)
{
    vec[0] = vec[0] * 20;
    vec[1] = vec[1] * 30;
}

int main()
{
    vector<int> v;
    v[0]= 4; v[1]=2;
    trylol(v);
    cout << v[0] << " " << v[1] << endl;
}
