//**********************************************************
//Name: Trevor Lastelick
//Class: COSC 2437 001
//Instructor: Marwa Hassan
//Assignment 7
//Date: 10/16/20
//Program description: This program creates a class and reads 
// in data from a file pertaining to a company. It reads 4 lines 
//of data filling 5 member variables (each company only has 4 
//lines of data pertaining to it). It then runs a hashing 
//function on the name member variable and uses that name as the 
//key to insert the whole block of data into a hash table. It 
//then asks the user to search through that hash table for 
//company names and will cout "Found" and keep asking the user to 
//find more companies, delete those found companies or quit the 
//program.
//************************************************************

//Notes to instructor:
// I found that I needed to write down more vocabulary from this
// chapter such as 'probe sequence' , 'double hashing' and others
// which helped me to differentiate between lab12 and hw7.
// Making those differentiations helped me to understand the 
// differences in code between lab12 and hw7 like lab12 is linear
// probing which uses a single hash function while hw7 uses 
// quadratic probing which is why there is a second hash function
// (quadratic probing uses the double hashing method to resolve //
//collision). Re-working through lab12, hw7, and then reading the 
//textbook(I need to read the textbook more) helped me more than 
//just the slides. I still ran into problems on this hw such as 
//my search function searches for the first index inputed and
// so will say yes "Pizza_Hut" has been found but print out the 
//"Fluor Corporation" data block and I couldn't figure out how 
// to delete the spaces when printing out revenues.
//This program did make headway and has greater functionality
//than my previous attempt.
// I also created a cheat sheet with many different combinations
// for overloading >> operator as well as file stream uses for 
// quicker access in the future. I'm not very proud of my work 
// on this hw, it's something I will have to go to pals for in
// the future to finish off. But now I am going to use this 
// methodology of solving to work on my sorting functions.


#include <iostream>
#include <string>
#include <fstream>
#include "hashT.h"
#include "FirmData.cpp"

using namespace std;

int main()
{
    FirmData comp;
    ifstream file;
    file.open("firm.dat");
    int index = 0;
    hashT<FirmData> table;
    
    while (file)
    {
    file >> comp; // fill class mem vars with data
    // run hashing function on class name
    index = comp.hashFunc(comp.getName()); 
    // insert entire class into table
    table.insert(index, comp);
    
    }
    
    table.print();
    
    
       //int index=0;
    bool found;
    string decision;
    string search;
    bool flag = true;
    string yes;
    cout << "Type S or s to begin search for company data: ";
    cin >> decision;
    
    while (flag == true)
    {
    if (decision == "s" || decision == "S")
    {
        cout << "Enter a name to search for (must use '_' to represent spaces and proper capitalization): ";
        cin >> search;
        // convert search into a hash index
        index = comp.hashFunc(search);
        // pull company data out of table
        table.retrieve(index, comp);
        table.search(index, comp, found);
        
        // print out that specific block of data searched for
            if (found==true)
            {
            cout << endl << comp << endl;
            cout << "Would you like to delete this entry? Y/N: ";
            cin >> yes;
            // if yes delete item. ask if want to search for another item or quit program.
            if (yes == "Y" || "y")
            {
                table.remove(index, comp);
                cout << "Successfully deleted! " << endl;
                cout << "Type 's' to search for another item or 'q' to quit program: "; 
            cin >> decision;
            if (decision == "Q" || "q")
                return 0;
            }
            // if no ask if want to search for another item or quit program.
            else if (yes == "N" || "n")
            {
            cout << "Type 's' to search for another item or 'q' to quit program: "; 
            cin >> decision;
            if (decision == "Q" || "q")
                return 0;
            }
            else
            {
            cout << "Invalid Response type Y or N: " << endl;
            cin >> yes;
            }
            } // end if (found==true)
       // else ask for another search name
            else
            {
            cout << "Did not find a match. Type 's' to search again, 'q' to quit: ";
            cin >> decision;
            if (decision == "q" || "Q")
                return 0;
            }
     }           
   }
   
    return 0;
}

    
    
