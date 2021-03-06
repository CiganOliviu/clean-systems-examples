/*
  remove floating point numbers from char array problem
  Tasks:
    * remove floating numbers from a sequence
*/

#include <chrono>
#include <iostream>
#include <cstring>

#ifndef STD_LENGTH
#define STD_LENGTH 100000
#endif

using namespace std::chrono;

class systemException : public std::exception {
private:
  std::string processMessage;

public:
  systemException (std::string errorMessage) : processMessage(errorMessage) {}

  const char * what () const throw ();

  virtual ~systemException () throw () {}
};

class validationRules {

public:
  validationRules () {}

  bool isNegative (char parameter[]);
  bool isZero (char parameter[]);

  virtual ~validationRules () {}
};

template <class Type> class oneDimensionalArrayType {
private:
  int standardSize = 0;

public:
  oneDimensionalArrayType () {}

  int & length = standardSize;
  int startPoint = standardSize;
  int endPoint = standardSize;

  Type * oneDimensionalArray = new Type[STD_LENGTH];

  virtual ~oneDimensionalArrayType () {}
};

class inputOutputSystem {
private:
  validationRules __validations__;

public:
  inputOutputSystem () {}

  void readOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow);
  void printOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow);

  virtual ~inputOutputSystem () {}
};

class stringWorkFlow {
private:
  validationRules __validations__;

public:
  stringWorkFlow () {}

  void removeAllFloatingNumbersFromSequence (oneDimensionalArrayType<char> dataWorkFlow);

  virtual ~stringWorkFlow () {}
};