#ifndef H_MD
#define H_MD

void print_md5_sum(unsigned char* md);
unsigned long get_size_by_fd(int fd);
unsigned char* md5(char* fileName);
#endif