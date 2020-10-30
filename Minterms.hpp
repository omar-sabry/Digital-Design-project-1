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
