#pragma once
#include"son.h"
#include"daughter.h"
#include<iostream>
using namespace std;
//implementing the grandson class
class grands:public son, public daughter
{
    private:
    int gs;
    public:
    //default constructor
    grands()
    {
        cout<<"grandson constructor called"<<endl;
    }
    //method implementation
    void grandsfunc()
    {
        cout<<"welcome to grandson class"<<endl;
    }
    //setter function
    void setgs(int a)
    {
        gs=a;
    }
    //getter function
    int getgs()
    {
        return gs;
    }
    //destructor
    ~grands()
    {
        cout<<"grandson destructor called"<<endl;
    }
};
//implementing the main function
/*
int main()
{
    grands gs1;
    return 0;
}*/
