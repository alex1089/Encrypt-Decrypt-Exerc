// Decrypt.cpp
// Decrypt class definition
// Aleksey Leshchuk 9.14.2014

#include <iostream>
#include <array>
#include "Decrypt.h"

class Decrypt {
    public:
	template <int SIZE>
	Decrypt(std::array<int, SIZE> const inputArray){
	    int convNum=processArray(inputArray);
	    std::cout<<"*D* Decrypt array constructor is called\n"
		<<"    and the passed in number is "<<convNum<<".**\n\n";
	    storeData(convNum);
	    }
	Decrypt(int& const inpNum) {
	    std::cout<<"*D* Decrypt constructor is called\n"
		<<"    and the passed in number is "<<inpNum<<".**\n\n";
	    storeData(inpNum);
	}
	void displayOriginalData() const {
	    std::cout<<"    The original data is ";
	    for (int i=4;i<data.size();i++){
		std::cout<<data.at(i)<<(data.size()<data.size()-2?(" "):(".\n")); // cout space if element is not the last in array, else print .\n
	    }
	}
	void storeData(int& const number){
	    temp=number; // mutable int to process
	    if (temp<=0){
		std::cout<<"  XXXXX The inputted number is less than or equal to 0.\n"
		    <<"       The number is reset to 1234. XXXXX";
		temp=1234;
	    }
	    for (int i=7;i>3;i--){
		data.at(i)=temp%10;
		temp/=10;
	    }
	    decrypt();
	}
	    
	void displayDecryptedData() const {
	    std::cout<<"    The decrypted data is ";
	    for (int i=0;i<4;i++){
		std::cout<<data.at(i)<<(data.size()<data.size()-2:(" "):(".\n")); // print space if element is not the last to be printed, else print .\n
	    }
	int getDecryptedData() const 
	    
    private:
	std::array inputArray;
	void decrypt(int& num);
}
