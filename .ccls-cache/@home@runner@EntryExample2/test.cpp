#include <iostream>
#include <string>
using namespace std;

extern void myFunc(std::string);
extern int adder(int);

int testmain(){
  myFunc("testmain");
  if (adder(5)==10){
    cout<<"Test successfull"<<endl;
  } else {
    cout<<"Test failed"<<endl;
  }
  exit(EXIT_SUCCESS);
}

static int s = testmain();