#include <iostream>
#include <string>
using namespace std;


void myFunc(string source){
  cout<<"Calling function from "<<source<<endl;
}

int adder(int a){
  return a*a;
}

int main() {
  myFunc("main");
  cout<<"adder result = "<<adder(5)<<endl;
}