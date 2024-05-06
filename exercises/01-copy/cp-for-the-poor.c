#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    const char* filename1 = argv[1];
    const char* filename2 = argv[2];
    int fd;
    int fd2;
    char buffer[128];
    ssize_t nread, nwritten;

    fd = open(filename1, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    fd2 = open(filename2, O_WRONLY|O_CREAT|O_EXCL, 0666);
    if (fd2 == -1) {
        perror("open");
        return 4;
    }

    while (1) {
        nread = read(fd, buffer, sizeof(buffer));
        if (nread == -1) {
            perror("read");
            return 2;
        }

        nwritten = write(fd2, buffer, nread);
        if (nwritten == -1) {
            perror("write");
            return 3;
        }

        // end of file (EOF) reached?
        if (nread == 0)
            break;
    }

    close(fd);
    close(fd2);
    return 0;
}
