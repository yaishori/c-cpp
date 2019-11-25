#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>
#include "mq.h"

int main()
{
        int ret;
        int fd;
        char buff[4096];
        
        printf("\nOpening Driver\n");
        fd = open("/dev/mq2", O_RDWR);
        if(fd < 0) {
                fprintf(stderr, "Cannot open device file...\n");
                return 1;
        }

        printf("Getting value from driver\n");
        ret=ioctl(fd, RD_VALUE, buff);
        if(ret<0) {
                fprintf(stderr, "ioctl had errors...%d\n", ret);
                return 1;
        }
        printf("size:%d\n", ret);
        printf("message:%s\n", buff);

        printf("Closing Driver\n");
        if(close(fd)<0) {
                fprintf(stderr, "problems with close\n");
                return 1;
        }
        return 0;
}
