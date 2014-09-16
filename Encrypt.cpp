// Aleksey Leshchuk
// CISP400 AD2 Encrypt class file

#include <iostream>
#include <iomanip>
#include "Encrypt.h"

// constructor takes any number
Encrypt::Encrypt(int const& inpNum){
    std::cout<<"*E* The Encrypt constructor is called\n\tand the passed in number is "<<inpNum<<".**\n\n";
    storeData(inpNum);
    displayOriginalData();
    displayEncryptedData();
}

// constructor takes an array of 8 elements
// for any size array need a delim char or size passed in as parameter
// template didn't seem to work in external file
Encrypt::Encrypt(int const *inp_arr){
    int convertedArr;
    convertedArr=processArray(inp_arr);
    std::cout<<"*E* The encrypt array constructor is called\n\tand the passed in number is "<< convertedArr<<".**\n\n";

    storeData(convertedArr);

    displayOriginalData();
    displayEncryptedData();
}

// Displays original data that was entered
void Encrypt::displayOriginalData() const{
    std::cout<<"\tThe original data is ";
    for (int i=4;i<8;i++)
	std::cout<<" "<<dataArray[i];
    std::cout<<".\n";
}

// Displays the data after encryption
void Encrypt::displayEncryptedData() const{
    std::cout<<"\tThe encrypted data is ";
    for (int i=0;i<4;i++)
	std::cout<<" "<<dataArray[i];
    std::cout<<".\n\n";
}

// Returns encrypted data as int
int Encrypt::getEncryptedData() const{
    int output=dataArray[0];
    for (int i=1;i<4;i++)
	output=output*10+dataArray[i];
    
    return output;
}

// Stores data entered as int and calls encryptData() member function
void Encrypt::storeData(int const& number){
    int temp=number;	// stores input number for manipulation
    if (number<=0){ // if number passed in is less than or equal to zero, reset it to 9436
	std::cout<<" XXX The number you entered is less than or equal to 0.\n"
	    <<"\tThe number is reset to 9436. XXX\n\n";
	temp=9436;
    }
    
    for (int i=7;i>3;i--){ // store input number into last 4 elements of dataArray
	dataArray[i]=temp%10;
	temp/=10;
	}
    encryptData();
}

// Encrypts data in the last four elements of the data array and stores it in the first 4 elements.
void Encrypt::encryptData(){
    int temp_holder; // holder variable 
    // increment each digit by 7 and % 10
    for (int i=0;i<4;i++)
	dataArray[i]=(dataArray[i+4]+7)%10;

    // swap first and third digits
    temp_holder=dataArray[0];
    dataArray[0]=dataArray[2];
    dataArray[2]=temp_holder;

    // swap second and fourth digit
    temp_holder=dataArray[1];
    dataArray[1]=dataArray[3];
    dataArray[3]=temp_holder;
    
}

// converts 8 elements array into int.
// Returns converted value
int Encrypt::processArray(int const *inp_array){
    int num=inp_array[0];
    if (num<0){ // if number is negative
	for (int i=1;i<8;i++){
	    num=num*10-inp_array[i];
	}
    } else { // if positive
	for (int i=1;i<8;i++){
	    num= num*10+inp_array[i];
	}
    }
    return num;
}
