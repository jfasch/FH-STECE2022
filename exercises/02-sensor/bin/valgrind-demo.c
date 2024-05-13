#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <FILENAME>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buf[16];
    ssize_t nread = read(fd, buf, sizeof(buf));
    (void)nread; // do something with bytes

    return 0;
}
