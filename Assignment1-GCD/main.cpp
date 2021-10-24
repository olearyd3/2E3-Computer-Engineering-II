//This is a program to compute and return the greatest common divisor of two positive and non-zero integers (natural numbers).

#include <iostream>
using namespace std;

int gcd(int firstnum, int secondnum);

int main() {
  int num_one, num_two;
  //Prompt user to enter two numbers and read them in
  cout << "Please enter the two numbers whose GCD you wish to calculate: " << flush;
  cin >> num_one >> num_two;
  //If numbers are natural, call on gcd function to compute the greatest common divisor
  if(num_one > 0 && num_two > 0) {
    gcd(num_one, num_two);
    //Print out the result
    cout << "\nThe GCD of " << num_one << " and " << num_two << " is " << gcd(num_one, num_two) << "." << endl;
  }
  //If something other than a natural number entered, print error message.
  else {
    cout << "\nAn error occurred.";
  }
  return 0;
}

//Function to calculate the greatest common divisor
int gcd(int firstnum, int secondnum) {
  //If numbers are equal return one of them
  if(firstnum == secondnum) {
    return firstnum;
  }
  //otherwise subtract from each other until gcd is reached
  else {
    while (firstnum != secondnum) {
      if (firstnum > secondnum) {
        firstnum = firstnum - secondnum;
      }
      else {
        secondnum = secondnum - firstnum;
      }
    }
    return firstnum;
  }
}
