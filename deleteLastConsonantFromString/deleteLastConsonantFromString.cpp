#include "deleteLastConsonantFromStringDef.hpp"

const char * systemException::what () const throw () {

  return processMessage.c_str();
}

bool validationRules::isNegative (char parameter[]) {

  if (strlen(parameter) < 0) return true;

  return false;
}

bool validationRules::isZero (char parameter[]) {

  if (strlen(parameter) == 0) return true;

  return false;
}

void inputOutputSystem::readOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  std::cin.getline (dataWorkFlow.oneDimensionalArray, dataWorkFlow.length);

}

void inputOutputSystem::outputOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  std::cout << dataWorkFlow.oneDimensionalArray << '\n';
}

bool stringWorkFlow::isNotVowel (char element) {

  if (element == 'a' || element == 'e' || element == 'i' || element == 'o' || element == 'u')
    return false;

  return true;
}

int stringWorkFlow::returnPositionOfLastConsona (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  int result = 0;

  for (int iterator = dataWorkFlow.startPoint; iterator < strlen(dataWorkFlow.oneDimensionalArray); iterator++)
    if (isNotVowel (dataWorkFlow.oneDimensionalArray[iterator]))
      result = iterator;

  return result;
}

void stringWorkFlow::deleteLastConsonaFromArray (oneDimensionalArrayType<char> dataWorkFlow) {

  int position = returnPositionOfLastConsona (dataWorkFlow);

  strcpy (dataWorkFlow.oneDimensionalArray + position, dataWorkFlow.oneDimensionalArray + position + 1);
}

int main (int argc, char const *argv[]) {

  oneDimensionalArrayType<char> string;
  inputOutputSystem IOSystem;
  stringWorkFlow workflow;

  string.length = 100;

  IOSystem.readOneDimensionalArray (string);

  auto start = high_resolution_clock::now();

  workflow.deleteLastConsonaFromArray (string);

  IOSystem.outputOneDimensionalArray (string);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}