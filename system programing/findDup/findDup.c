
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "md5.h"
#include "findDup.h"
#include "hashTable.h"



void listFilesRecursively(char *basePath,void* hashT)
{
    char path[2048];
    struct dirent *dp;
    int fd;
    unsigned char* res; 
    AdtStatus status;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
       
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            
            if(dp->d_type==8){
                printf("%s\n",dp->d_name);
                res=malloc(2048);
                
                res=md5(dp->d_name);
                

                /*status= hashTableInsert((HashTable*)hashT,res,basePath,0);
                if(status==Exist){
                    printf("%s: %s\n",basePath,dp->d_name);
                }*/
            }


            else if(dp->d_type==4){
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            listFilesRecursively(path,hashT);
            }
            

        }
    }

    closedir(dir);
}