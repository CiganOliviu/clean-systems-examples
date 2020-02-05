/*
nearest or fibonacci problem problem
Tasks:
  * determine if a number is fibonacci, if it is return the number else return the nearest fibonacci number
*/

#include <chrono>
#include <iostream>
#include <stdlib.h>

using namespace std::chrono;

class systemException : public std::exception {
private:
  std::string processMessage;

public:
  systemException (std::string errorMessage) : processMessage(errorMessage) {}

  const char * what () const throw ();

  virtual ~systemException () throw () {}
};

const char * systemException::what () const throw () {

  return processMessage.c_str();
}

class validationRules {

public:
  validationRules () {}

  template <class Type> bool isNegative (Type parameter);
  template <class Type> bool isZero (Type parameter);

  virtual ~validationRules () {}
};

template <class Type> bool validationRules::isNegative (Type parameter) {

  if (parameter < 0) return true;

  return false;
}

template <class Type> bool validationRules::isZero (Type parameter) {

  if (parameter == 0) return true;

  return false;
}

class fibonacciWorkFlow {
private:
  validationRules __validations__;

  int minimumDifference (int argOne, int argTwo, int differenceTermen);
  int returnFibonacciNumber (int numberIndex);

public:
  fibonacciWorkFlow () {}

  int returnFiboNumber (int number);

  virtual ~fibonacciWorkFlow () {}
};

int fibonacciWorkFlow::minimumDifference (int argOne, int argTwo, int differenceTermen) {

  if (abs(differenceTermen - argOne) < abs(differenceTermen - argTwo)) return argOne;

  return argTwo;
}

int fibonacciWorkFlow::returnFibonacciNumber (int numberIndex) {

  if (__validations__.isNegative(numberIndex)) systemException("Unable to process negative values");
  if (__validations__.isZero(numberIndex)) systemException("Unable to process number as zero");
  if (numberIndex == 1 || numberIndex == 2) return 1;

  return returnFibonacciNumber(numberIndex - 1) + returnFibonacciNumber(numberIndex - 2);
}

int fibonacciWorkFlow::returnFiboNumber (int number) {

  int underNumber, aboveNumber, closestNumber, iterator = 1;
  bool runTimeChecker = true;

  while (runTimeChecker) {

    if (returnFibonacciNumber(iterator) < number)
      underNumber = returnFibonacciNumber(iterator);
    if (returnFibonacciNumber(iterator) > number) {
      aboveNumber = returnFibonacciNumber(iterator);
      runTimeChecker = false;
    }
    if (returnFibonacciNumber(iterator) == number) return number;

    iterator += 1;
  }
  closestNumber = minimumDifference (underNumber, aboveNumber, number);

  return closestNumber;
}

int main(int argc, char const *argv[]) {

  int number;

  std::cin >> number;

  auto start = high_resolution_clock::now();

  fibonacciWorkFlow fibonacci;

  std::cout << fibonacci.returnFiboNumber (number) << '\n' << '\n';

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
