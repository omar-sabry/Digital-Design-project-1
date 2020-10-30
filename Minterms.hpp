//
//  Minterms.hpp
//  QMProject
//
//  Created by Salma Ahmed on 10/28/20.
//  Copyright © 2020 Salma Ahmed. All rights reserved.
//

#ifndef Minterms_hpp
#define Minterms_hpp

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Minterms
{
private:
    int count;

public:
    Minterms();
    int setMintermNo(string, int);
    string convertToBinary(int);
    string editByte(string, string);
    bool checkIfPair(string, string);
    void counter();
    
};
#endif /* Minterms_hpp */
