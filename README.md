# Hash-tables
Hash tables

a.The file, firm.dat, contains information about some companies with their primary headquarters located in Texas. Companies are listed by their name, industry, headquarter city, founding year and revenues(in billion as of2019).

Design the class FirmData. The class has to include the appropriate functions to manipulate the company’s data, ex. setters and getters. For easy input and output, overload the stream operators. Also, overload the relational operators to compare two companies by the name.

b. Create a hash table for the firms' information. The class uses quadratic probing to resolve collision. You will create a hash table of data type FirmData. Use the company's name as the key to determine the hash address. You may assume that a name is a string of no more than 25 characters. Test your program (firms.cpp) by searching for and removing certain companies from the hash table.
