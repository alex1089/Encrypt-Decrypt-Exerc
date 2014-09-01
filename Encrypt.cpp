// Aleksey Leshchuk
// CISP400 AD2 Encrypt class file

#include <iostream>
#include "Encrypt.h"

// constructor takes a 4 digit number
Encrypt::Encrypt(int const& inpNum){
    std::cout<<"*E* Encrypt constructor is called\nand the passed in number is "<<inpNum<<".**";
    storeData(inpNum);
}
Encrypt::Encrypt(int const a[5]){
    int formal_num; // variable to store converted value of the passed in array
    std::cout<<"Encrypt array constructor is called\nand the passed in number is ";

    for (int i:inp_arr)
	std::cout<<i;
    std::cout<<".**";
    formal_num=inp_arr[0];

    for (int i:inp_arr)
	formal_num+=formal_num*10+i;
    storeData(formal_num);
}
void Encrypt::displayOriginalData() const{}
void Encrypt::displayEncryptedData() const{}
int Encrypt::getEncryptedData() const{}
void Encrypt::storeData(int const& plain_text){}
