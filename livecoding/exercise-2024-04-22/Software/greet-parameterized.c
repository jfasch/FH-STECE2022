#include "greet.h"
#include <stdio.h>


int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s NAME\n", argv[0]);
        return 1;
    }

    greet_name(argv[1]);
    return 0;
}
