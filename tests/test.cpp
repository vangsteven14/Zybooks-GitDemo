#include <iostream>
#include <string>
using namespace std;

extern int CalcAGI(int, int, int); 

int unitTest1(){
  
  int agi;

   agi = CalcAGI(20000, 500, 300);
   if (agi != 20800) {
      cout << "CalcAGI(20000, 500, 300) should return 20800 but instead returns "  << agi << endl;
      return false;
   }

   agi = CalcAGI(-20000, -500, -300);
   if (agi != 20800) {
      cout << "CalcAGI(-20000, -500, -300) should correct negative values and return 20800 but instead returns "  << agi << endl;
      return false;
   }

   cout << "Tests returned the correct results for CalcAGI()." << endl;
  exit(EXIT_SUCCESS);
}

static int s = unitTest1();