#pragma once
#include"grandfather.h"
#include<iostream>
using namespace std;
class son :public grand
{
    private:
    int s;
    public:
    //default constructor
    son()
    {
        cout<<"son constructor called "<<endl;
    }
    //method in the class
    void sonfunc()
    {
        cout<<"welcome to son class"<<endl;
    }
    //setter func
    void sets(int t)
    {
       s=t;
    }
    //getter function
    int gets()
    {
        return s;
    }
    //destructor
    ~son()
    {
        cout<<"son destructor called"<<endl;
    }
};
/*
int main()
{
    son s1;
    s1.sonfunc();
    s1.sets(20);
    int value=s1.gets();
    cout<<"value of son variable :"<<value<<endl;
    return 0;
}*/
//test main
/*
int main()
{
    son s1;
    return 0;
}*/