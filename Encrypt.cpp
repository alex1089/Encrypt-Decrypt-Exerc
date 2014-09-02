// Aleksey Leshchuk
// CISP400 AD2 Encrypt class file

#include <iostream>
#include "Encrypt.h"

// constructor takes a 4 digit number
Encrypt::Encrypt(int const& inpNum){
    std::cout<<"*E* The Encrypt constructor is called\n\tand the passed in number is "<<inpNum<<".**\n\n";
    storeData(inpNum);
}
template <int N>
Encrypt::Encrypt(int const(&inp_arr)[N]){
    std::cout<<"*E* The encrypt array constructor is called\n\tand the passed in number is ";

    for (int i=0;i<N;i++)
	std::cout<<inp_arr[i];

    std::cout<<".**\n\n";

    //if (inp_arr[0]<=0)
	processZeroOrNegArray(inp_arr);
    //else
//	processPosArray(inp_arr);
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
    std::cout<<".\n";
}
int Encrypt::getEncryptedData() const{
    int output=dataArray[0];
    for (int i=1;i<4;i++)
	output+=output*10+dataArray[i];
    
    return output;
}
void Encrypt::storeData(int const& number){
    int temp=number;	// stores input number for manipulation
    for (int i=7;i>3;i--){
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
    
    displayOriginalData();
    displayEncryptedData();
}
template <int SIZE>
void Encrypt::processZeroOrNegArray(int const (&inp_arr)[SIZE]){
    std::cout<<SIZE; 
}
int main(){
    int array[]{1,2,4,4,1,6,7,2,1,4};
    Encrypt test{array};
}

