#include "Integer.hpp"
#include <iostream>
#include <utility>
Integer::Integer():Integer(0){}

Integer::Integer(int Val) {
  m_int = new int(Val);
}

// Copy Construtor
Integer::Integer(const Integer& Val) {
    // Make The New Pointer Point to The Same Memory Sectio
    this->m_int = new int(*Val.m_int);
}

// Move constructor ,  Move -> RValue (temp)
Integer::Integer(Integer &&Val) : m_int {std::exchange(Val.m_int,nullptr)} {}

void Integer::setInteger(int Val) {
  * m_int = Val;
}

int Integer::getValue(void) const {
    return *m_int;
}

Integer Integer::add(const Integer & int1 , const Integer & int2) {
    Integer Temp;
    Temp.setInteger(int1.getValue() + int2.getValue());
    return Temp;
}

// Deep Copy , copy assigment operator
Integer & Integer::operator=(const Integer & int1) {
  if( this != &int1) {
      delete m_int;
      m_int = new int {*int1.m_int};
  }
  return *this;
}

// Move assignment operator
Integer & Integer::operator=(Integer && int1) noexcept  {
  if( this != &int1) {
      delete m_int;
      m_int= std::exchange(int1.m_int , nullptr);
  }
  return *this;
}
std::ostream & operator<<(std::ostream &o , const Integer &int1)
{
    o << "m_int value : " << *int1.m_int << std::endl;
    return o;
}

Integer::~Integer() {
  delete(m_int);
}





