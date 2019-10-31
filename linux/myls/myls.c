#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>

int main() {
   struct dirent *dp;
   DIR *dir;
   char cwd[PATH_MAX];
   struct stat fileStat;
    
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
       dir = opendir(cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }

    while((dp = readdir(dir)) != NULL){
    	if(strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
        if(stat(dp->d_name,&fileStat) < 0){  
          return 1;
        }
        printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
        printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
        printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
        printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
        printf(" ");
        printf("%d",(int)fileStat.st_nlink);
        printf(" ");
        struct passwd *pw = getpwuid(fileStat.st_uid);
        struct group  *gr = getgrgid(fileStat.st_gid);

        printf("%s %s", pw->pw_name, gr->gr_name);
        printf(" ");
        printf("%d",(int)fileStat.st_size);
        printf(" ");
        char time[50];
        strftime(time, 50, "%m %d %H:%M", localtime(&fileStat.st_mtime));
        printf ("%s ", time);
        printf("%s\n",dp->d_name);
        }
    }

    closedir(dir);
   return 0;
}