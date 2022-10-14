/* 
Patrick Ging
Professor Zamanksy
Lab 6
main.cpp
*/

#include <iostream>
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

int main()
{

  std::cout << "C shifted to the right by three is " << shiftChar('C',3) << std::endl;
  std::cout << "E shifted to the right by five is " << shiftChar('E',5) << std::endl;
  std::cout << "L shifted to the right by 2 is " << shiftChar('L',2) << std::endl;

  std::cout << "\'Patrick\' caesar shifted by 3 is " << encryptCaesar("Patrick", 3) << std::endl;
  std::cout << "\'Vlad\' caesar shifted by 10 is " << encryptCaesar("Vlad", 10) << std::endl;

  std::cout << "\'Sausages\' vigenere shifted with the key \'abc\' is " << encryptVigenere("Sausages", "abc") << std::endl;
  std::cout << "\'Computer\' vigenere shifted with the key \'lol\' is " << encryptVigenere("Computer", "lol") << std::endl;
 
  std::cout << "\'aBcDeFgH\' caesar decrypted with 10 is " << decryptCaesar("aBcDeFgH", 10) << std::endl;

  std::cout << "\'Jevpq, Wyvnd!\' Vigenere decrypted with key cake is " << decryptVigenere("Jevpq, Wyvnd!", "cake") << std::endl;

  return 0;
}
