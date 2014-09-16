// Decrypt.h
// Decrypt class header
// Aleksey Leshchuk 9.14.2014

class Decrypt {
    public:
	Decrypt(int const *inputArray);
	Decrypt(int const &inpNum);
	void displayOriginalData()const ;
	void storeData(int const &number);
	void displayDecryptedData()const ;
	int getDecryptedData()const ;
    private:
	int data[8];
	int processArray(int const *inArray) const;
	void decrypt();
};
