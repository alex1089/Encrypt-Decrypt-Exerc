// Decrypt.cpp
// Decrypt class definition
// Aleksey Leshchuk 9.14.2014

#include <iostream>
#include "Decrypt.h"

Decrypt::Decrypt(int const *inputArray){
    int convNum=processArray(inputArray);
    std::cout<<"*D* Decrypt array constructor is called\n"
	<<"    and the passed in number is "<<convNum<<".**\n\n";
    storeData(convNum);
    }
Decrypt::Decrypt(int const &inpNum) {
    std::cout<<"*D* Decrypt constructor is called\n"
	<<"    and the passed in number is "<<inpNum<<".**\n\n";
    storeData(inpNum);
}
void Decrypt::displayOriginalData() const {
    std::cout<<"    The original data is ";
    for (int i=4;i<8;i++){
	std::cout<<data[i]<<(i<7?" ":".\n"); // print space if element is not last, else print \n. 
    }
}
void Decrypt::storeData(int const &number){
    int temp=number; // mutable int to process
    if (temp<=0){
	std::cout<<"  XXXXX The inputted number is less than or equal to 0.\n"
	    <<"       The number is reset to 1234. XXXXX";
	temp=1234;
    }
    for (int i=7;i>3;i--){
	data[i]=temp%10;
	temp/=10;
    }
    decrypt();
}
    
void Decrypt::displayDecryptedData() const {
    std::cout<<"    The decrypted data is ";
    for (int i=0;i<4;i++){
	std::cout<<data[i]<<(i<3?" ":".\n"); // print space if element is not last, else print \n. 
    }
}
int Decrypt::getDecryptedData() const {
    int converted=data[0];
    for (int i=1;i<4;i++)
	converted=converted*10+data[i];
    return converted;
}
int Decrypt::processArray(int const *inArray) const{
    int num=inArray[0];
    for (int i=1;i<4;i++){
	num= num*10+inArray[i];
    }
    return num;
}

void Decrypt::decrypt(){
    // swap 1st digit and 3rd digit
    data[0]=data[6];
    data[2]=data[4];
    // swap 2nd and 4th digit
    data[1]=data[5];
    data[3]=data[7];
    // reverse of (n+7)%10, n+3
    for (int i=0;i<4;i++)
	data[i]+=3;
}

