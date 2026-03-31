#pragma once
#include"daughter.h"
#include<iostream>
using namespace std;
//implementing the granddaughter class
class granddu:public daughter
{
    private:
    int gd;
    public:
    //default constructor
    granddu()
    {
        cout<<"granddaughter constructor called"<<endl;
    }
    //method implementation
    void granddufunc()
    {
        cout<<"welcome to granddaughter class"<<endl;
    }
    //setter function
    void setgdu(int a)
    {
        gd=a;
    }
    //getter function
    int getgdu()
    {
        return gd;
    }
    //destructor 
    ~granddu()
    {
        cout<<"granddaughter destructor called"<<endl;
    }
};
//implementing the main function
/*
int main()
{
    granddu gd1;
    return 0;
}*/