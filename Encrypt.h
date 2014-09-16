// Aleksey Leshchuk
// CISP400 AD2 Encrypt header file

class Encrypt{
    public:
	Encrypt(int const& inpNum);
	template <int N>
	Encrypt(int const (&inp_arr)[N]);
	void displayOriginalData() const;
	void displayEncryptedData() const;
	int getEncryptedData() const;
	void storeData(int const& plain_text);
    private:
	template <int SIZE>
	int processArray(int const(&inp_arr)[SIZE]);
	void encryptData();
	int dataArray[8];
};

	
