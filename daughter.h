#pragma once
#include"grandfather.h"
#include"grandmother.h"
#include<iostream>
using namespace std;
class daughter:public grand,public grandm
{
    private:
    int d;
    public:
    //default constructor
    daughter()
    {
        cout<<"daughter constructor called"<<endl;
    }
    //method implementation
    void daughterfunc()
    {
        cout<<"welcome to daughter class"<<endl;
    }
    //setter function
    void setd(int t)
    {
        d=t;
    }
    //getter function
    int getd()
    {
        return d;
    }
    //destructor implementation
    ~daughter()
    {
        cout<<"daughter destructor called"<<endl;
    }
};
//implementing the main function
/*
int main()
{
    daughter d1;

}*/
