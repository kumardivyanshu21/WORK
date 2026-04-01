#pragma once
#include<iostream>
using namespace std;
//implementing the grandmother class
class grandm:virtual public greatgr
{
    private:
    int gm;
    public:
    //default constructor
    grandm()
    {
        cout<<"grandmother constructor called"<<endl;
    }
    //method implementation
    void grandmfunc()
    {
        cout<<"welcome to grandmother class"<<endl;
    }
    //setter function
    void setgm(int a)
    {
        gm=a;
    }
    //getter function
    int getgm()
    {
        return gm;
    }
    //implementing the destructor
    ~grandm()
    {
        cout<<"grandmother destructor called"<<endl;
    }
};
//implementing the main function
/*
int main()
{
    grandm g1;
    return 0;
}*/