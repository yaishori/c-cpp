typedef struct {
	unsigned int m_a:4;
	unsigned int m_b:4;	
}bitStruct;

union un {
	bitStruct bitFields;
	unsigned char ab;
};


int packingFields(char* str);
int packing(char* str);
void printStr(char* str);