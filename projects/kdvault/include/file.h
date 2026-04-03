#pragma once
#include<string>
#include<iostream>
using namespace std;
#pragma once
//this is my file class which contains the properties of the file
class file
{
    protected:
    string filename;//stores the filename
    string filepath;//stores the file path
    public:
    //constructor
    file(string name, string path)
    {
        filename=name;
        filepath=path;
    }
    //destructor
    ~file(){}
};
