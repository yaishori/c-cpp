#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>
#include "mq.h"

int main(int argc, char** argv, char** envp)
{
        int fd;
        struct ms_buff buff;
        char* str = argv[1];
        buff.size =strlen(str);
        buff.mes=str;

        printf("\nOpening Driver\n");
        fd = open("/dev/mq2", O_RDWR);
        if(fd < 0) {
                fprintf(stderr, "Cannot open device file...\n");
                return 1;
        }

        printf("Writing Value to Driver\n");
        if(ioctl(fd, WR_VALUE, &buff)<0) {
                fprintf(stderr, "ioctl had errors...\n");
                return 1;
        }

        printf("Closing Driver\n");
        if(close(fd)<0) {
                fprintf(stderr, "problems with close\n");
                return 1;
        }
        return 0;
}
