#include "hello-flexible.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <whom>\n", argv[0]);
        return 1;
    }

    hello_flexible(argv[1]);   // <--- HERE: new functionality used
    return 0;
}
