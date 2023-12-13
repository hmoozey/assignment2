//file :part10.cpp
//purpose:2 printing functions one of them prints a binary number and the other print many numbeers with one prefix and mmany suffix consist of k digit
//Author:mohamed
//section:s22
//ID:20220974
//TA:rana abdelkader
//Date:30/11/2023

#include <iostream>
using namespace std ;
string binary="";
string suffix ;
int i =0;
class printingfunctions{
private:


public:
    static void binaryprint (int n){

    if(n==0&&i==0){
        cout<<'0' ;
        return ;
    }
    else if(n==0 && i!=0)
        cout <<binary;

     if(n!=0){
            i++;
            if (n%2==0)
                binary ="0"+binary ;
            else if (n%2!=0){
                binary ="1"+binary ;
            }
            binaryprint(n/2);
   }

}
//******************************************

static void numbers (string prefix, int k ){

    if(k==0){
        cout << prefix + suffix <<endl  ;
    }
else if (k>0){
    suffix.push_back('0');
    numbers(prefix,k-1);
    suffix.pop_back();


    suffix.push_back('1');
    numbers(prefix,k-1);
    suffix.pop_back();
}
}
};



int main(){
printingfunctions p1;
cout<<"please enter a if you want to print one binary number \n";
cout<< "please enter b if you want to print many numbers in binary\n";
char c; int num  ;
string pref;
cin >>  c;
if (c =='a') {
    cout << "please enter decimal number \n";
    cin >> num;
    cout<< "n = "<<num << "Output : ";
    p1.binaryprint(num);
}
else {
    cout << "please enter the prefix and the number k \n";
    cin >> pref >> num;
    p1.numbers(pref,num);
}

    return 0;
}