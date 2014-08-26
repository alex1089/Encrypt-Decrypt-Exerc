// Aleksey Leshchuk
// CISP400 AD2 Encrypt class file

#include <iostream>
#include "Encrypt.h"

// constructor takes a 4 digit number
Encrypt(int const& inpNum);
Encrypt(int const* inp_arr);
void Encrypt::displayOriginalData() const;
void Encrypt::displayEncryptedData() const;
int Encrypt::getEncryptedData() const;
void Encrypt::storeDate(int const& plain_text);
