#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include "Minterms.hpp"

using namespace std;

int countNoofOnes(string a);
bool compareNoofOnes(string a, string b);
bool existing(vector<string> a,string b);
vector<string> recursivePairs(vector <string>& ArrayOfPairs,vector<string> Minterm8Bits,Minterms groupOfMinterms);
bool VectorsEqual(vector<string> a,vector<string> b);


int main() {
    
    vector <int> MintermDecimals;
    vector <string> Minterm8Bits;
    vector <string> ArrayOfPairs;
    vector <string> NewMinterms;
    
    ifstream inputFromFile;
    string line, line2, line3;
    
    Minterms groupOfMinterms;
    
    inputFromFile.open("/Users/salmaabdellatif/Desktop/inputFile1.txt");
    if (!inputFromFile.is_open())
    {
        cout <<"There was a problem accessing your desired function.\n";
        exit(EXIT_FAILURE);
    }
    
    //Retrieving lines.
    getline(inputFromFile, line);
    getline(inputFromFile, line2);
    getline(inputFromFile, line3);

    int NoofVariables=stoi(line);
    int MaxNoofMinterms = pow(2,NoofVariables);
    
    cout << "The number of variables for this function are: " << line <<".\n";
 
       stringstream ssLine2(line2);
       stringstream ssLine3(line3);

        while (ssLine2.good())
        {
            string nextCharacter;
            getline(ssLine2, nextCharacter, ',');
            groupOfMinterms.counter();
            int mintermValue = groupOfMinterms.setMintermNo(nextCharacter, MaxNoofMinterms);
            string mintermBinary = groupOfMinterms.convertToBinary(mintermValue);
            MintermDecimals.push_back(mintermValue);
            Minterm8Bits.push_back(mintermBinary);
            ArrayOfPairs.push_back(nextCharacter);
        }
        
        while (ssLine3.good())
        {
            string nextCharacter;
            getline(ssLine3, nextCharacter, ',');
            groupOfMinterms.counter();
            int mintermValue = groupOfMinterms.setMintermNo(nextCharacter, MaxNoofMinterms);
            string mintermBinary = groupOfMinterms.convertToBinary(mintermValue);
            MintermDecimals.push_back(mintermValue);
            Minterm8Bits.push_back(mintermBinary);
            ArrayOfPairs.push_back(nextCharacter);
        }
        
        
        inputFromFile.close();

           
       

    for (int i=0; i<MintermDecimals.size();i++)
    {
       for (int j=i+1; j< MintermDecimals.size(); j++)
            {
                if (MintermDecimals[i]==MintermDecimals[j])
                {
                 cout << "Error. Repeated minterm values. Please correct your input file and start again." << endl;
                 exit(EXIT_FAILURE);
                }
            }
        cout << MintermDecimals[i] <<endl;
    }
     cout << endl;
    
    for (int i=0; i<MintermDecimals.size();i++)
       {
           for (int j=i;j<MintermDecimals.size();j++)
               compareNoofOnes(Minterm8Bits[i], Minterm8Bits[j]);
           sort(Minterm8Bits.begin(), Minterm8Bits.end(), compareNoofOnes);
           int x=stoi(Minterm8Bits[i]);
           int y=groupOfMinterms.binaryToDecimal(x);
           stringstream z;
           z<<y;
           string w;
           z>>w;
           ArrayOfPairs[i]= w;
           cout << Minterm8Bits[i] << endl;
       }
    for (int i=0; i<ArrayOfPairs.size(); i++)
    {
        cout << ArrayOfPairs[i] <<endl;
    }
    
     cout << endl;
    int noOfColumns=0;
    do
    {
        noOfColumns++;
        //if (noOfColumns==2)
        //{ArrayOfPairs.clear();}
        Minterm8Bits= recursivePairs(ArrayOfPairs, Minterm8Bits,groupOfMinterms);
        sort(Minterm8Bits.begin(), Minterm8Bits.end(),compareNoofOnes);
        cout << "Column " << noOfColumns << endl;
        for (int i=0; i<Minterm8Bits.size(); i++)
        {
            cout << Minterm8Bits[i] <<endl;
           
        }
        for (int i=0; i<ArrayOfPairs.size(); i++)
        {
            cout << ArrayOfPairs[i] <<endl;
        }
        
        cout << endl;

    }while(!VectorsEqual(Minterm8Bits,recursivePairs(ArrayOfPairs, Minterm8Bits,groupOfMinterms)));
    cout << endl;
    
    
    cout << "Prime Implicants " <<endl;
    for (int i=0; i<Minterm8Bits.size(); i++)
    {
        cout << Minterm8Bits[i] << endl;
    }
    
    
    
    return 0;
}

int countNoofOnes(string a)
{
    int countofOnes=0;
    for (int i=0 ; i<20 ; i++)
    {
        if (a[i]=='1')
        {
            countofOnes++;
        }
    }
    return countofOnes;
}

bool compareNoofOnes(string a, string b)
{
    
    int count1 = countNoofOnes(a);
    int count2 = countNoofOnes(b);
    
    if (count1 >= count2)
        return false;
    return true;
}

bool existing(vector<string> a,string b)
{
    for(int i=0;i<a.size();i++)
        if(a[i].compare(b)==0)
            return true;
    return false;
}

vector<string> recursivePairs(vector <string>& ArrayOfPairs,vector<string> Minterm8Bits,Minterms groupOfMinterms)
{
    vector<string> NewMinterms;

    int max=Minterm8Bits.size();
    int* checked = new int[max];
    for(int i=0;i<max;i++)
    {
        for(int j=i+1;j<max;j++)
        {
            if(groupOfMinterms.checkIfPair(Minterm8Bits[i],Minterm8Bits[j]))
            {
                checked[i]=1;
                checked[j]=1;
                if(!existing(NewMinterms, groupOfMinterms.editByte(Minterm8Bits[i],Minterm8Bits[j])))
                {
                    NewMinterms.push_back(groupOfMinterms.editByte(Minterm8Bits[i],Minterm8Bits[j]));
                    ArrayOfPairs.push_back(ArrayOfPairs[i]+","+ArrayOfPairs[j]);
                }
            }
            
            
    }
    }
    for(int i=0;i<max;i++)
    {
        if((checked[i]!=1) && !(existing(NewMinterms,Minterm8Bits[i])))
        {
            NewMinterms.push_back(Minterm8Bits[i]);
        }
    }
    
    delete[] checked;
    
    return NewMinterms;
    
}
bool VectorsEqual(vector<string> a,vector<string> b)
{
    if(a.size()!=b.size())
        return false;
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}
