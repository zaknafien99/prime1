// prime1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <list>
#include <algorithm>
#include <cstdlib>  //for abs()
#include <iostream>
using namespace std;

// predicate, which returns whether an integer is a prime number
bool isPrime(int number)
{
    //ignore negative sign
    number = abs(number);

    // 0 and 1 are not prime numbers
    if (number == 0 || number == 1) {
        return false;
    }

    //find divisor that divides without a remainder
    int divisor;
    for (divisor = number / 2; number % divisor != 0; --divisor) {
        ;
    }

    //if no divisor greater than 1 is found it is a prime number
    return divisor == 1;
}

int main()
{
    list<int> coll;

    //insert elements from 24 to 30
    for (int i = 24; i <= 30; ++i) {
        coll.push_back(i);
    }

    //search for prime number
    auto pos = find_if(coll.cbegin(), coll.cend(),  //range
        isPrime);                                   // predicate

    if (pos != coll.end()) {
        // found
        cout << *pos << "is first prime number found" << endl;
    }
    else {
        //not found
        cout << "no prime number found" << endl;
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
