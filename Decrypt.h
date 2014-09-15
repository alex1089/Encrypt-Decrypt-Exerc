// Decrypt.h
// Decrypt class header
// Aleksey Leshchuk 9.14.2014

#include <array>

class Decrypt {
    public:
	template <int SIZE>
	Decrypt(std::array<int, SIZE> const inputArray);
	Decrypt(int& const inpNum);
	void displayOriginalData()const ;
	void storeData(int& const  number);
	void displayDecryptedData()const ;
	int getDecryptedData()const ;
    private:
	std::array inputArray;
	void decrypt(int& const num);
}
