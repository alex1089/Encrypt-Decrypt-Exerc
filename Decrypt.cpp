// Decrypt.cpp
// Decrypt class definition
// Aleksey Leshchuk 9.14.2014

#include <iostream>
#include "Decrypt.h"

// Decrypt array constructor. Takes int array of 8 elements
// else would need to pass in size of array
Decrypt::Decrypt(int const *inputArray){
    int convNum=processArray(inputArray);
    std::cout<<"\n*D* Decrypt array constructor is called\n"
	<<"\tand the passed in number is "<<convNum<<".**\n\n";
    storeData(convNum);
    displayOriginalData();
    displayDecryptedData();
    }

// Decrypt constructor takes any int value
Decrypt::Decrypt(int const &inpNum) {
    std::cout<<"\n*D* Decrypt constructor is called\n"
	<<"\tand the passed in number is "<<inpNum<<".**\n\n";
    storeData(inpNum);
    displayOriginalData();
    displayDecryptedData();
}

// Displays original data entered
void Decrypt::displayOriginalData() const {
    std::cout<<"\tThe original data is ";
    for (int i=4;i<8;i++){
	std::cout<<data[i]<<(i<7?" ":".\n"); // print space if element is not last, else print \n. 
    }
}

// stores data entered as argument in the last 4 elements of data array
// calls decrypt() to decrypt data
void Decrypt::storeData(int const &number){
    int temp=number; // mutable int to process
    if (temp<=0){
	std::cout<<"  XXXXX The inputted number is less than or equal to 0.\n"
	    <<"\tThe number is reset to 1234. XXXXX\n\n";
	temp=1234;
    }
    for (int i=7;i>3;i--){
	data[i]=temp%10;
	temp/=10;
    }
    decrypt();
}
// displays derypted data    
void Decrypt::displayDecryptedData() const {
    std::cout<<"\tThe decrypted data is ";
    for (int i=0;i<4;i++){
	std::cout<<data[i]<<(i<3?" ":".\n"); // print space if element is not last, else print \n. 
    }
}
// returns decrypted data as int
int Decrypt::getDecryptedData() const {
    int converted=data[0];
    for (int i=1;i<4;i++)
	converted=converted*10+data[i];
    return converted;
}

// converts first 4 elements of entered array into an int
// returns the converted value
int Decrypt::processArray(int const *inArray) const{
    int num=inArray[0];
    if (num<0){ // if number is negative
	for (int i=1;i<8;i++){
	    num=num*10-inArray[i];
	}
    } else { // if positive
	for (int i=1;i<8;i++){
	    num= num*10+inArray[i];
	}
    }
    return num;
}

// decrypt private method. Decrypts and stores data in first 4 data elements.
void Decrypt::decrypt(){
    // swap 1st digit and 3rd digit
    data[0]=data[6];
    data[2]=data[4];
    // swap 2nd and 4th digit
    data[1]=data[7];
    data[3]=data[5];
    // reverse of (n+7)%10, (n+3)%10
    for (int i=0;i<4;i++)
	data[i]=(data[i]+3)%10;
}

