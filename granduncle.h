#pragma once
#include<iostream>
using namespace std;
//implementing the granduncle class
class grandunc
{
   private:
   int gu;
   public:
   //default constructor
   grandunc()
   {
    cout<<"granduncle constructor called"<<endl;
   }
   //method implementation
   void granduncfunc()
   {
    cout<<"welcome to granduncle class"<<endl;
   }
   //setter function
   void setgu(int a)
   {
    gu=a;
   }
   //getter function
   int getgu()
   {
    return gu;
   }
   //destructor
   ~grandunc()
   {
     cout<<"granduncle destructor called"<<endl;
   }
};
//implementing the main function
/*
int main()
{
    grandunc gu;
    return 0;
}*/