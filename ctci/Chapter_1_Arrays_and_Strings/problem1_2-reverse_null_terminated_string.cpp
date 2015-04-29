/*
CtCI Chapter 1 Arrays and Strings
Problem 2 Reverse a Null Terminated String

Implement a function void reverse(char* str) in C or C++ which reverses a 
null-terminated string.

(Easy) String
*/

/*
SOLUTION (Pointers)

- A first iteration to get the pointers to the end of the string. A second 
iteration to reverse the string in place.

Tips:
- The right way to run a test on this function is to initialize a char array 
(with string literals) and pass the function the array variable as a pointer. 
Be careful if you use any of the forms below, which are incorrect:

  - Initialize a char pointer with string literal. This would initialize a 
  char pointer to a const string. Any modification on this string would result 
  in bus error. See below:

    char * char1 {"testtest"};

  - Assign a string literal to a pointer variable. See below. The char1 is 
  correctly allocated with a space. However, the assignment below is actually 
  assigning the address to the string literal to the pointer char1. The 
  modification on the space char1 points to is a bus error.

    char * char1 = new char[9];
    char1 = "testtest";

*/

#include <iostream>

using namespace std;

void reverse(char * str) {
    char * end = str;
    while (*end) end++;
    end--;
    while (end > str) {
        char temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
    return;
}

int main() {
    char char1[12] = "reversetest";
    reverse(char1);
    cout << char1 << endl;
    return 0;    
}
