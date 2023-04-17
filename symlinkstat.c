//print out the information of a symbolic link using lstat()
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{    
    struct stat buffer;
    int status;

    status = lstat(argv[1], &buffer);

    //prints the information of the symbolic link
    if (status == 0) {
        printf("st_dev  :   %ld\n", buffer.st_dev);
        printf("st_ino :   %ld\n", buffer.st_ino);
        printf("st_mode:   %d\n", buffer.st_mode);
        printf("st_nlink:   %ld\n", buffer.st_nlink);
        printf("st_uid  :   %d\n", buffer.st_uid);
        printf("st_gid :   %d\n", buffer.st_gid);
        printf("st_rdev :   %ld\n", buffer.st_rdev);
        printf("st_size :   %ld\n", buffer.st_size);
        printf("st_blksize: %ld\n", buffer.st_blksize);
        printf("st_blocks:  %ld\n", buffer.st_blocks);
        printf("st_atime:   %ld\n", buffer.st_atime);
        printf("st_mtime:   %ld\n", buffer.st_mtime);
        printf("st_ctime:  %ld\n", buffer.st_ctime);
        return 0;
    }    
    //checks for errors
    else {
    fprintf(stderr, "Usage: %s filename\n", argv[0] );
    return -1;
    }      
}
