// Aleksey Leshchuk
// CISP400 AD2 Encrypt header file

class Encrypt{
    public:
	Encrypt(int const& inpNum);
	Encrypt(int const* inp_arr);
	void displayOriginalData() const;
	void displayEncryptedData() const;
	int getEncryptedData() const;
	void storeData(int const& plain_text);
    private:
	int dataArray[8];
};

	
