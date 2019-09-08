/*
PROBLEM:
  A palindromic number reads the same both ways. The largest palindrome made
  from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <string>

int num1, num2; //max N-digit number. Value set in setNums().
//Store palindrome multiples as global variable.
int firstMultiple, secondMultiple;
int i_count = 0; //Count iterations for benchmarking

/*
Objective of this algorithm is to find the larger palindromes first to reduce
execution time.
If num1 * num2 is less than the current maximum palindrome, then break.
*/
int findLargestPalindrome(int mult = num1*num2){
  //Use strings to determine if palindrome.
  std::string curr = " ";
  std::string rev = " ";
  int currPalindrome = -1;

  while(mult > currPalindrome){ //if false, no point continuing search.
    //num2 iterates backwards, mult updated every iteration.
    for(; mult > currPalindrome; num2--, mult = num1*num2){
      i_count++; //Increment iteration count
      //Check if palindrome through string comparison.
      curr = std::to_string(mult);
      rev = curr;
      std::reverse(rev.begin(), rev.end());
      //Check if palindrome. Discard if smaller than current palindrome.
      if(curr == rev && mult > currPalindrome){
        currPalindrome = std::stoi(curr); //cast back to integer.
        //Update palindrome multiples
        firstMultiple = num1;
        secondMultiple = num2;
        break; //break since for loop is only getting smaller.
      }
    }
    num1--; //decrement num1
    num2 = num1; //reset num2
    mult = num1*num2;
  }
  return currPalindrome;
}

/*
Set num1, and num2 to the largest number of N-digits
Example: num1 = num2 = 999 when N=3.
*/
void setNums(int input){
  num1 = 1;
  for(int i = 0; i<input; i++){
    num1 = num1*10;
  }
  num2 = num1-1;
  num1 = num2;
}

int consoleInOut(){
  int temp = -1; //Temporary user input
  std::cout << "This program will calculate the largest palindrome of two" <<
    " N-digit numbers." << std::endl
    << "Please enter an integer value [1-5] for N" << std::endl;
  std::cin >> temp;
  while(temp >= 6 || temp < 1){
    std::cout << "Try again. Please enter an integer value [1-5] for N"
      << std::endl;
    std::cin >> temp;
  }
  return temp;
}

int main(){
  int nDigit = consoleInOut();
  setNums(nDigit);

  std::cout << "The largest palindrome of the product of two " << nDigit
   <<"-digit numbers is " << findLargestPalindrome()
   << " = " << firstMultiple << " x " << secondMultiple << std::endl
   << "This was calculated in " << i_count << " loop iterations." << std::endl;

  return 0;
}
