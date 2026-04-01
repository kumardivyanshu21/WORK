#pragma once
#include<iostream>
using namespace std;
//implementing the grandfather class
class grand:virtual public greatgr
{
    private:
    int g;
    public:
    //default constructor
    grand()
    {
        cout<<"grand  father constructor called"<<endl;
    }
    //implementing the grandfather class
    void grandfunc()
    {
        cout<<"welcome to grand  father class"<<endl;
    }
    //setter function
    void setg(int a)
    {
        g=a;
    }
    //getter function
    int getg()
    {
        return g;
    }
    //destructor
    ~grand()
    {
        cout<<"grand  father destructor called"<<endl;
    }
};
//implementing main function to test just 
/*
int main()
{
   grand g1;
   g1.setg(10);
   g1.grandfunc();
   int value=g1.getg();
   cout<<"value of grand variable :"<<value<<endl;
   return 0;
}*/