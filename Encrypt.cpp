// Aleksey Leshchuk
// CISP400 AD2 Encrypt class file

#include <string>
#include <iostream>
#include "Encrypt.h"

Encrypt(int const& inpNum);
Encrypt(int const* inp_arr);
void Encrypt::displayOriginalData() const;
void Encrypt::displayEncryptedData() const;
int Encrypt::getEncryptedData() const;
void Encrypt::storeDate(int const& plain_text);
