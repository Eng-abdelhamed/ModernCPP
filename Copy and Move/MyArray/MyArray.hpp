#pragma once

#include <iostream>
#include <initializer_list>
#include <memory>


class Myarray final {

// Overload Stream Extraction
  friend std::istream & operator>>(std::istream &i , Myarray& mar);
// used by copy constructor assignemnet operator ro implement cop and swap idiom
  friend void swap(Myarray& m1 , Myarray & m2) noexcept ;

public:
// construct my array of size size
    explicit Myarray(size_t size);

// construct parametrized constructor to take init list of ints
    explicit Myarray(std::initializer_list<int> list);

// Copy constructor
    Myarray(const Myarray& arr1);

// Copy Assignment Operator
    Myarray& operator=(const Myarray & arr1);

// Move Constructor
    Myarray(const Myarray && original) noexcept;

// Move Assignment Operator
    Myarray& operator=(const Myarray && original) noexcept;

// Destructor
    ~Myarray();

// Return size
size_t size() const noexcept;

// Create String Representation
std::string toString()const noexcept;

// equality operator
bool operator==(const Myarray& arr1 );




private:
  size_t m_size{0};

  std::unique_ptr<int> m_ptr;
};
