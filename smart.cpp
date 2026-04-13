#include <iostream>
using namespace std;
// implementing my own unique pointer in cpp
// DESTRUCTOR,COPY CONSTRUCTOR,COPY ASSIGNMENT OPERATOR,MOVE CONSTRUCTOR,MOVE ASSIGNMENT OPERATOR-RULE OF FIVE
class kd_ptr
{
private:
    int *p;

public:
    // default constructor 
    kd_ptr(int *ptr)
    {
        p = ptr;
    }
    // copy constructor
    kd_ptr(const kd_ptr &other) = delete;
    // copy assignment operator
    kd_ptr &operator=(const kd_ptr &other) = delete;
    // move constructor
    kd_ptr(kd_ptr &&other)
    {
        p = other.p;
        other.p = nullptr;
    }
    // move assignment constructor
    kd_ptr &operator=(kd_ptr &&other)
    {
        if (this != &other)
        {
            delete[] p;
            p = other.p;
            other.p = nullptr;
        }
        return *this;
    }
    // destructor
    ~kd_ptr()
    {
        delete[]  p;
    }
    //* operator overloading ie dereference operator
    //here although we can print the integer value but not modigy it since * operator is not returning the reference its returning copy of the integer present
    /*int operator*()
    {
        return *p;
    }*/
   //we are returning 
   int& operator*()
   {
    return *p;
   }

};
//implementing the main function
//currently we are dealing with only integers but when dealing with class or structure we need arrow operator
int main()
{
   kd_ptr kd1(new int(10));
   cout<<"value pointed by kd1:"<<*kd1<<endl;
   kd_ptr kd2(new int(40));
   *kd2=20;
   cout<<*kd2;
   return 0;
}