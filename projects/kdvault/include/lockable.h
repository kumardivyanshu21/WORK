#pragma once
//implementing the interface which defines two behaviours encrypt and encrypt
class lockable{
    public:
    //defining two pure  virtual functions to define the behaviour of the class
    virtual void encrypt()=0;
    virtual void decrypt()=0;
};