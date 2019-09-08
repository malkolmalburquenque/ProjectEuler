/*
PROBLEM:
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>
#include <cmath>

long int N; //number to test for largest prime factor.

int largestPrimeFactor(long int n = N){
  long int largestPrime = 0;

  /*
  Even check:
  If even divide by 2.
  */
  while(n % 2 == 0){
    largestPrime = 2;
    n /= 2;
  }

  /*
  Odd check:
  Increment by two to skip even numbers.
  */
  for(long int i = 3; i < sqrt(n); i += 2){ //increment by 2 (stay odd)
    while(n % i == 0){ //if divisible check if prime.
      largestPrime = i;
      n /= i; // n = n/i
    }
  }

  // for(int i = 3; i < n/2; i += 2){
  //   if(n % i == 0){
  //     n /= i;
  //     i--;
  //   }
  // }

  //if n is a prime
  if(n > 2){
    largestPrime = n;
  }

  return largestPrime;
}

int main (){
  std::cout << "Please enter an integer value \n";
  std::cin >> N;
  std::cout << "The largest prime factor of the number " << N <<
    " is " <<largestPrimeFactor() << "\n";
  return 0;
}
