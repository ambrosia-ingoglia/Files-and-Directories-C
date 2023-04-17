//create a symbolic link with symlinkat()
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

extern int errno;
int main(int argc, char* argv[])
{   
    //opens the file to get the newdirfd argument
    int fd = open(argv[1], O_RDONLY | O_CREAT);

    //creates the symbolic link
    int sl = symlinkat(argv[1],fd,argv[2]);
    
    //checks for errors
    if (sl == 0) {
        return 0;
    }    
    else {
    fprintf(stderr, "Usage: %s filename\n", argv[0] );
    return -1;
    }    
    close(fd);
}