#include <iostream>
#include <string>
#include <fstream>
#include "hashT.h"

using namespace std;

 

class FirmData
{
    private:
    // if HTSIZE is 101 I get 
    // Error: The table is full. Unable to resolve collision (x2)
    // If HTSize == 99 I get the same error, but just once.
    // 89 is the first number where no errors occur.
    int HTSize = 89;
    string name,
            industry,
            city,
            revenues;
    int year;

    public:
    // GETTERS
    string getName()
    { return name; }
    
    string getIndustry()
    { return industry; }
    
    string getCity()
    { return city; }
    
    int getYear()
    { return year; }
    
    string getRevenues()
    { return revenues; }
    
    // OVERLOADED OPERATORS
    friend istream &operator >> (istream &strm, FirmData &r)
    {
        getline(strm, r.name);
        getline(strm, r.industry);
        getline(strm, r.city);
        strm >> r.year;
        getline(strm, r.revenues);
        return strm;
    }
    
    // need to overload so hashT insert func works propery
    bool operator!=(const FirmData &right)
    {
        bool flag;
    
        if (this->name != right.name && this->industry != right.industry && this->city != right.city && this->year != right.year && this->revenues != right.revenues)
        flag = true;
        
        else
        flag = false;
        
        return flag;
   }
   
   // need to overload so hashT insert func works properly
   bool operator==(const FirmData &right)
   {
        bool flag;
        
        if (this->name == right.name && this->industry == right.industry && this->city == right.city && this->year == right.year && this->revenues == right.revenues)
        flag = true;
        
        else
        flag = false;
        
        return flag;
   }
   
   // need overload so hashT print func works properly
   friend ostream &operator << (ostream &strm, FirmData &r)
   {
        strm << "Name: " << r.name << endl;
        strm << "Industry: " << r.industry << endl;
        strm << "City Headquarters: " << r.getCity() << endl;
        strm << "Founding Year: " << r.getYear() << endl;
        strm << "Revenues: " << r.revenues << " in billions as of 2019" << endl;
        return strm;
   }
    
    int hashFunc(string name)
{
    int i=0, sum=0;
    int len = name.length();
    
    for (int k=0; k<25-len; k++)
        name = name + ' ';  // increase the length of name to 25 characters
    
    for (int k=0; k<5; k++)
    {
        sum = sum + static_cast<int>(name[i]) * 128 * 128
        + static_cast<int>(name[i+1]) * 128
        + static_cast<int>(name[i+2]);
       i = i + 3;
    }
    
    return sum % HTSize;
}
    
};  // END CLASS

    
