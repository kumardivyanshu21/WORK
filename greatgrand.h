#pragma once
#include<iostream>
using namespace std;
//implementing the greatgrandfathcer class
class greatgr
{
    private:
    int gtgr;
    public:
    //default constructor
    greatgr()
    {
        cout<<"greatgrandfather constructor called"<<endl;
    }
    //method implementation
    void greatgrfunc()
    {
        cout<<"welcome to great grandfather class"<<endl;
    }
    //setter function
    void setgtgr(int a)
    {
        gtgr=a;
    }
    //getter function
    int getgtgr()
    {
        return gtgr;
    }
    //destructor
    ~greatgr()
    {
        cout<<"great granfatcher destructor called"<<endl;
    }
};
//implementing the main function
/*
int main()
{
    greatgr g1;
    return 0;
}*/