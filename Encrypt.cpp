// Aleksey Leshchuk
// CISP400 AD2 Encrypt class file

#include <iostream>
#include <iomanip>
#include "Encrypt.h"

// constructor takes a 4 digit number
Encrypt::Encrypt(int const& inpNum){
    std::cout<<"*E* The Encrypt constructor is called\n\tand the passed in number is "<<inpNum<<".**\n\n";
    storeData(inpNum);
    displayOriginalData();
    displayEncryptedData();
}
template <int N>
Encrypt::Encrypt(int const(&inp_arr)[N]){
    int convertedArr;
    convertedArr=processArray(inp_arr);
    std::cout<<"*E* The encrypt array constructor is called\n\tand the passed in number is "<< convertedArr<<".**\n\n";

    storeData(convertedArr);

    displayOriginalData();
    displayEncryptedData();
}

void Encrypt::displayOriginalData() const{
    std::cout<<"\tThe original data is ";
    for (int i=4;i<8;i++)
	std::cout<<" "<<dataArray[i];
    std::cout<<".\n";
}
void Encrypt::displayEncryptedData() const{
    std::cout<<"\tThe encrypted data is ";
    for (int i=0;i<4;i++)
	std::cout<<" "<<dataArray[i];
    std::cout<<".\n\n";
}
int Encrypt::getEncryptedData() const{
    int output=dataArray[0];
    for (int i=1;i<4;i++)
	output+=output*10+dataArray[i];
    
    return output;
}
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
template <int SIZE>
int Encrypt::processArray(int const(&inp_arr)[SIZE]){
    int converted=inp_arr[0];	// variable to contain converted array to int
    for (int i=0;i<SIZE && i<4;i++){
	converted=converted*10+inp_arr[i];
    }

    return converted;
}
