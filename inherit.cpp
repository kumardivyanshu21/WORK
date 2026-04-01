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
   /* greatgr g1;
     g1.greatgrfunc();
     grand g2;
     g2.grandfunc();
     g2.setgtgr(20);
     int value=g2.getgtgr();
     cout<<"value of greatgrand variable is:"<<value<<endl;
     grands gs1;
     gs1.grandsfunc();
     gs1.setgs(30);
     int value1=gs1.getgs();
     cout<<"value of grandson variable is:"<<value1<<endl;
    return 0;*/
    //resolving the ambiguity error
    //one is to use scope
    /*grands s1;
    s1.son::greatgrfunc();
    //now we can also do other things also*/
    //used the virtual function thing
    grands s1;
    s1.greatgrfunc();
    return 0;
}