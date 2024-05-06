#include "greet.h"

#include <stdio.h>


void greet_simple(void)
{
    printf("Hallo mein Schatz\n");
}

void greet_name(const char* name)
{
    printf("Hallo %s\n", name);
}
