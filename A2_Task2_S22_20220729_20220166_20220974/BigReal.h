//
// Created by HP on 11/4/2023.
//

#ifndef A2_TASK2_S22_20220166_BIGREAL_H
#define A2_TASK2_S22_20220166_BIGREAL_H
#include <string>
using namespace std;

class BigReal : public error_code {
private :



public:
    char sign ='+';
    string integer ,fraction;


    BigReal(string real) ;
     void print();
     bool IsValid(string real);
     BigReal operator+(BigReal &anotherreal );

  //  [[maybe_unused]] BigReal(string  ,string);
     ~BigReal();
BigReal();
};


#endif //A2_TASK2_S22_20220166_BIGREAL_H
