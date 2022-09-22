#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double TEN_PCT = 0.1;
const double TWELVE_PCT = 0.12;
const double TWENTY_TWO_PCT = 0.22;
const double TWENTY_FOUR_PCT = 0.24;

// Calculate AGI and repair any negative values
int CalcAGI(int wages, int interest, int unemployment) {
   int agi;
   agi = abs(wages);
   agi += abs(interest);
   agi += abs(unemployment);
   return agi;
}

// Calculate deduction depending on single, dependent or married
int GetDeduction(int status) {
   int deduction = 0;

   if (status == 2) {
      deduction = 24000;
   }
   else if (status == 1) {
      deduction = 12000;
   }
   else {
      deduction = 6000;
   }
   return deduction;
}

// Calculate taxable but not allow negative results
int CalcTaxable(int agi, int deduction) {
   int taxable;
   taxable = agi - deduction;
   if(taxable < 0) {
      taxable = 0;
   }
   return taxable;
}

// Calculate tax for single or dependent
int CalcTax(int status, int taxable) {
   double tax = 0.0;

   // Married
   if (status == 2) {
      if(taxable > 80000){
         tax = (taxable-80000) * TWENTY_TWO_PCT + 9200;
      }
      else if(taxable > 20000){
         tax = (taxable-20000) * TWELVE_PCT + 2000;
      }
      else {
         tax = taxable * TEN_PCT;
      }
   }
   // Single or dependent
   else {
      if(taxable > 85000) {
         tax = (taxable-85000) * TWENTY_FOUR_PCT + 14500;
      }
      else if (taxable > 40000) {
         tax = (taxable-40000) * TWENTY_TWO_PCT + 4600;
      }
      else if (taxable > 10000) {
         tax = (taxable-10000) * TWELVE_PCT + 1000;
      }
      else {
         tax = taxable * TEN_PCT;
      }
   }
   tax = round(tax);
   return (int) tax;
}

// Calculate tax due and check for negative withheld
int CalcTaxDue(int tax, int withheld) {
   int due;
   if (withheld < 0) {
      withheld = 0;
   }
   due = tax - withheld;
   return due;
}

int main() {
   int wages, interest, unemployment, status, withheld;
   int tax, agi, due, deduction, taxable;

   // Input information
   cin >> wages;
   cin >> interest;
   cin >> unemployment;
   cin >> status;
   cin >> withheld;

   // Calculate AGI and taxable amount
   agi = CalcAGI(wages, interest, unemployment);
   cout << "AGI: $" << agi << endl;

   deduction = GetDeduction(status);
   cout << "Deduction: $" << deduction << endl;

   // Calculate taxable income
   taxable = CalcTaxable(agi, deduction);
   cout << "Taxable income: $" << taxable << endl;

   // Calculate tax
   tax = CalcTax(status, taxable);
   cout << "Federal tax: $" << tax << endl;

   // Calculate tax due
   due = CalcTaxDue(tax, withheld);
   cout << "Tax due: $" << due << endl;
   
   return 0;
}
