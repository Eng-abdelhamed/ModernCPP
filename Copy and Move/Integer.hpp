#include <iostream>
#include <ostream>

class Integer {
private:
  int *m_int;

public:
  // Default constructor
  Integer();
  //  Destrcutor
  ~Integer();
  // Parametrized Constructor
  Integer(int Value);
  // Copy Constructor Lvalue
  Integer(const Integer &Val);
  // copy Assignment operator
  Integer &operator=(const Integer &int1);
  // Move Constructor Rvalue
  Integer(Integer &&Val);
  // Move assignment operator always work with temp values , rvalues, theft
  Integer &operator=(Integer &&int1) noexcept;
  // Setters
  void setInteger(int Val);
  // Getters
  int getValue(void) const;
  // Static add functionality
  static Integer add(const Integer &int1, const Integer &int2);

  friend std::ostream &operator<<(std::ostream &o, const Integer &int1);
};
