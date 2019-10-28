#include "parser_t.h"

int main(int argc, char *argv[]){
	int i=1;
	parser_t parser;
	while(i<argc){
		parser.readFile(argv[i]);
		i++;
	}
	return 0;
}