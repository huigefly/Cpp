//: C14:PrivateInheritance.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include <iostream>
using namespace std;

class Pet {
public:
  char eat() const { return 'a'; }
  int speak() const { return 2; }
  float sleep() const { return 3.0; }
  float sleep(int) const { return 4.0; }
};

class Goldfish : Pet { // Private inheritance
public:
  using Pet::eat; // Name publicizes member
  using Pet::sleep; // Both members exposed
};

int main() {
  Goldfish bob;
  cout << bob.eat() << endl;
  cout << bob.sleep() << endl;
  cout << bob.sleep(1) << endl;
//! bob.speak();// Error: private member function
} ///:~
