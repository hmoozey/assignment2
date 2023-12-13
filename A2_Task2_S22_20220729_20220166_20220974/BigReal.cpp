//
// Created by HP on 11/4/2023.
#include <string>
#include <regex>
#include <iostream>
#include <utility>
#include "BigReal.h"
using namespace std;

BigReal::BigReal(string real) {
    // that takes a string to comare with , the thing that i search about in string
    // ? means txat you have 0 or 1 from +- and \\d* means zero or more than digit
    if (regex_match(real , regex("[+-]?\\d*.?\\d*"))) {
        if (real[0] == '-') {
            sign = '-';
            real[0] = '0';
        }
        else {
            sign ='+';
            real.erase(remove(real.begin(), real.end(), '+'), real.end());
        }//in the case that real doesn't have fraction--->what
        integer = real.substr(0, real.find('.'));
        fraction = real.substr(integer.size() + 1, real.size() - 1);
        if (integer.empty())
            integer = '0';
        if (fraction.empty())
            fraction = '0';
    }

}

void BigReal::print() {
    cout << sign <<integer<< '.'<< fraction <<endl ;

}

//[[maybe_unused]] BigReal::BigReal(string frac , string inte ) {
//fraction =std::move(frac) ;
//integer =std::move(inte) ;
//}

BigReal::~BigReal() {

}
// function valid for real
bool BigReal::IsValid(string real) {
    if (regex_match(real , regex("[+-]?\\d*.?\\d*"))) {
        cout <<"the  real number is valid ";
        return true ;
    }
    else {
        cout <<"the real number is unvalid " ;
        return false;
    }

}
string common="" ,temp ="",result ="";
char carry ='0';
int x ;
//
BigReal BigReal::operator+ (BigReal &anotherreal ) {//4   076520
    BigReal n;

    // add the fraction part
    if (fraction.size() > anotherreal.fraction.size()) {
        result = fraction.substr(anotherreal.fraction.size(), fraction.size() - 1);
        common =anotherreal.fraction ;


    }
    else if (fraction.size() < anotherreal.fraction.size()) {
        result = anotherreal.fraction.substr(fraction.size(), anotherreal.fraction.size() - 1);
        common = fraction;
    } else common = fraction ;


    for (int i = common.size() - 1; i >= 0; i--) {
        // we add the carry with the brevious addition
        temp = to_string((int (carry)-48) + (int(fraction[i])-48) + (int(anotherreal.fraction[i])-48) );
        if (temp.size()==2) {
            temp = to_string(stoi (temp) - 10);
            carry = '1';
        } else carry = '0';
        result = temp + result;

    }
    result =  result ;
       fraction  = result;
       n.fraction =fraction ;
      // cout <<fraction <<endl ;




    //add the integer part
    if (integer.size() > anotherreal.integer.size()) {
         x = integer.size() - anotherreal.integer.size();
        for (int i = 0; i < x; i++) {
            anotherreal.integer = '0' + anotherreal.integer;
        }
      //  cout <<anotherreal.integer<<endl ;
    }
    else if (anotherreal.integer.size() > integer.size()) {
             x = anotherreal.integer.size() - integer.size();
            for (int i = 0; i < x; i++) {
                integer = '0' + integer;
            }

    } result ="";
        for (int i =integer.size()-1 ; i >=0; i--) {
            temp = to_string((int(carry)-48) +( int(integer[i])-48) + (int(anotherreal.integer[i])-48) );
            if (temp.size()==2) {
                temp = to_string(stoi(temp)  - 10);
                carry = '1';
            } else carry = '0';

            result = temp + result;
        }
        if (carry == '1') {
            result = carry  + result;
            integer =result ;
        }

        else integer =result ;
        n.integer =integer ;
        n.sign = sign ;
        return n;

}

BigReal::BigReal() {

}


