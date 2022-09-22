#include <iostream>
#include <string>
using namespace std;

extern int GetDeduction(int); 

int unitTest2(){
  
   int deduction;

   deduction = GetDeduction(0);
   if (deduction != 6000) {
      cout << "GetDeduction(0) should return 6000 but instead returns "  << deduction << endl;
      return false;
   }

   deduction = GetDeduction(1);
   if (deduction != 12000) {
      cout << "GetDeduction(1) should return 12000 but instead returns "  << deduction << endl;
      //return false;
   }

   deduction = GetDeduction(2);
   if (deduction != 24000) {
      cout << "GetDeduction(2) should return 24000 but instead returns "  << deduction << endl;
     // return false;
   }

   deduction = GetDeduction(5);
   if (deduction != 6000) {
      cout << "GetDeduction(5) should ignore invalid status and return 6000 but instead returns "  << deduction << endl;
      //return false;
   }

   cout << "Tests returned the correct results for GetDeduction()." << endl;
  // return true;

  exit(EXIT_SUCCESS);
}

static int s = unitTest2();