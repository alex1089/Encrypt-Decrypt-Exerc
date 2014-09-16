// Decrypt.h
// Decrypt class header
// Aleksey Leshchuk 9.14.2014

#include <array>

class Decrypt {
    public:
	template<int SIZE>
	Decrypt(int const (&inputArray)[SIZE]);
	Decrypt(int const &inpNum);
	void displayOriginalData()const ;
	void storeData(int const &number);
	void displayDecryptedData()const ;
	int getDecryptedData()const ;
    private:
	int data[8];
	template<int SIZE>
	int processArray(int const (&inArray)[SIZE]) const;
	void decrypt();
};
