#include"greatgrand.h"
#include"grandfather.h"
#include"grandmother.h"
#include"granduncle.h"
#include"son.h"
#include"daughter.h"
#include"grandson.h"
#include"granddaughter.h"
//implementing the main function
int main()
{
   /*greatgr g1;
   g1.greatgrfunc();
   g1.setgtgr(100);
   int v1=g1.getgtgr();
   cout<<"value of great grandfather variable:"<<v1<<endl;
   grand g2;
   g2.grandfunc();
   g2.setgtgr(50);
   int v2=g2.getgtgr();
   cout<<"value of great grandfather variable in grand class :"<<v2<<endl;*/
   /*son s1;
   s1.greatgrfunc();
   s1.setgtgr(100);
   int v1=s1.getgtgr();
   cout<<"value of great grandfather variable in grandson class:"<<v1<<endl;
   return 0;*/
   //we are rectifying the ambiguity problem by two methods
   //method 1 : by using scope resolution operator
   /*grands gs1;
   gs1.son::greatgrfunc();
   gs1.son::setgtgr(150);
   int v1=gs1.son::getgtgr();
   cout<<"value of great grandfather variable in grandson class:"<<v1<<endl;
   return 0;*/
   //method 2:by using virtual inheritance
   grands s1;
   s1.greatgrfunc();
   s1.setgtgr(200);
   int v1=s1.getgtgr();
    cout<<"value of great grandfather variable in grandson class:"<<v1<<endl;
    return 0;
}