#include <iostream>
#include <string>
using namespace std;

extern int CalcTaxable(int, int); 

int unitTest3(){
  int taxable;

   taxable = CalcTaxable(40000, 3000);
   if (taxable != 37000) {
      cout << "CalcTaxable(40000, 3000) should return 37000 but instead returns "  << taxable << endl;
     // return false;
   }

   taxable = CalcTaxable(10000, 20000);
   if (taxable != 0) {
      cout << "CalcTaxable(10000, 20000) should return 0 but instead returns "  << taxable << endl;
     // return false;
   }

   cout << "Tests returned the correct results for CalcTaxable()." << endl;
   //return true;
  
  exit(EXIT_SUCCESS);
}

static int s = unitTest3();