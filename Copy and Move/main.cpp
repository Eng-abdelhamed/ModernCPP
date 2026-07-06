#include "Integer.hpp"
#include <iostream>

int main() {
  Integer a{1}, b{2};
  const Integer c{5}; // object is const , member fucntion non-const
  std::cout << c.getValue() << std::endl;
  Integer Temp = Integer::add(a, b);
  a.setInteger(Temp.getValue());
  std::cout << Temp;
}
