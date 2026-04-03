#include"file.h"
#include"lockable.h"
//this is our actual class whose object we can create 
class vaultfile:public file, public lockable//multiple inheritance implemented
{
    public:
    void encrypt() override;
    void decrypt() override;
    void movevault() ;
    bool restorevault() ;
   //constructor
   vaultfile(string name, string path):file(name, path)
   {
   }
};