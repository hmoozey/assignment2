#include <iostream>
#include "BigReal.h"
using namespace std;

int main() {
//    //bigreal i will input it string and bass to methods
    BigReal t ("+548.75");
t.print ();

    string s2 ,s1 ;
    cin >> s2 >> s1 ;
    BigReal r1(s1);
 BigReal r2(s2);
 if (r1.sign == r2.sign){

 }

BigReal r3= r2.operator+(r1);;

r3.print ();

    return 0;
}
//big numberer that execut 4 bytes