#include "Minterms.hpp"

Minterms::Minterms()
{
    //This constructor initializes the count for the number of minterms to 0.
    count = 0;
}

void Minterms::counter()
{
    //This function counts the number of minterms for the desired function.
    count++;
}

int Minterms::setMintermNo(string M, int MM)
{
    //This function converts the string read from file into an integer value and sends it to the function which converts it to an 8-bit binary number.
    
    int MintermValue=0;
    stringstream converter(M);
    
    converter>>MintermValue;
    if (MintermValue>MM)
    {
        cout << "Error. There cannot be more than " << MM << " minterms for this function. Please correct your input file \n";
        exit(EXIT_FAILURE);
    }
    
    return MintermValue;
}

string Minterms::convertToBinary(int minTermNo) 
{
    int n = minTermNo;
   
    char bits[20];
    char remainder[20];
    
    for (int i=0 ; i<8 ; i++)
    {
        bits[i] = n%2 + '0';
        n/=2;
    }
    
    bits[8] = 0;
    
    for (int i=7 ; i>=0 ; i--)
    {
        remainder[7-i] = bits[i];
    }
    
    remainder[8] = 0;
    
    string eightBitsMinterm = remainder;
    return eightBitsMinterm;
}

bool Minterms::checkIfPair(string s1, string s2) 
{
    //This function checks for one bit difference between two given bit strings by counting the number of different bits and considering the two different strings a pair only if the number of different bits is equal to 1.
    
    int noOfDifferentBits = 0;
    
    for (int i=0 ; i<8 ; i++)
    {
        if (s1[i]!=s2[i])
        {
            noOfDifferentBits++;
        }
    }
    return (noOfDifferentBits==1);
}

string Minterms::editByte(string s1, string s2)
{
    // Returns a string with '_' in the different bit
    string editedString = s1;
    for (int i=0 ; i<8 ; i++)
    {
        if (s1[i]!=s2[i])
        {
            editedString[i] = '_';
        }
    }
    return editedString;
}

