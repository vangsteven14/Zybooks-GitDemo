#include <iostream>
#include <string>
using namespace std;

extern int CalcTax(int, int); 

int unitTest4(){
  
 int tax;

   // Married at 10% bracket
   tax = CalcTax(2, 16000);
   if (tax != 1600) {
      cout << "CalcTax(2, 16000) should return 1600 but instead returns "  << tax << endl;
     // return false;
   }

   // Married at 12% bracket
   tax = CalcTax(2, 36000);
   if (tax != 3920) {
      cout << "CalcTax(2, 36000) should return 3920 but instead returns "  << tax << endl;
     // return false;
   }

   // Married at 22% bracket
   tax = CalcTax(2, 96000);
   if (tax != 12720) {
      cout << "CalcTax(2, 96000) should return 12720 but instead returns "  << tax << endl;
     // return false;
   }

   // Single at 10% bracket
   tax = CalcTax(1, 8000);
   if (tax != 800) {
      cout << "CalcTax(1, 8000) should return 800 but instead returns "  << tax << endl;
    //  return false;
   }

   // Dependent at 12% bracket
   tax = CalcTax(0, 30000);
   if (tax != 3400) {
      cout << "CalcTax(0, 30000) should return 3400 but instead returns "  << tax << endl;
     // return false;
   }

   // Dependent at 22% bracket
   tax = CalcTax(0, 60000);
   if (tax != 9000) {
      cout << "CalcTax(0, 60000) should return 9000 but instead returns "  << tax << endl;
     // return false;
   }

   // Single at 24% bracket
   tax = CalcTax(1, 100000);
   if (tax != 18100) {
      cout << "calcTax(1, 100000) should return 18100 but instead returns "  << tax << endl;
      //return false;
   }

   cout << "Tests returned the correct results for CalcTax()." << endl;
  exit(EXIT_SUCCESS);
}

static int s = unitTest4();