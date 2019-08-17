typedef struct {
	int numOfFe;
	int* fe;	
}bitStruct;

typedef int (*bitsFunc)(int bitIndex,bitStruct* bitS);

bitStruct* createBitStruct(int numOfFe);
int bitOn(int bitIndex,bitStruct* bitS);
int bitOff(int bitIndex,bitStruct* bitS);
int bitStatus(int bitIndex,bitStruct* bitS);
void printBits(bitStruct* bitS);
void destroyBitStruct(bitStruct* bitS);
int calculate(bitsFunc f,int bitIndex,bitStruct* bitS);
void reverseString(char* str);
void int2bin(int x,int numOfFe);
