/*
PROBLEM:
If we list all the natural numbers below 10 that are multiples of 3 or 5,
we get 3, 5, 6 and 9.
The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/


#include <iostream>
using namespace std;

int MAXVALUE = 1000; //value to count up to

/* This function determines the sum of all multiples
of 3 and 5 that are < MAXVALUE */
int multiples(int n){
  int sum = 0;
  for (int i = 0; i < n; i++){
    if (i%3 == 0 || i%5 == 0)
      sum = sum + i;
  }
  return sum;
}

int main(){
  cout << "Sum of all multiples of 3 or 5 below "
    << MAXVALUE << " is: " << multiples(MAXVALUE) << "\n";
}
