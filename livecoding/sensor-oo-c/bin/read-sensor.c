#include <sensor.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <temperature-file>\n", argv[0]);                
        return 1;
    }
    const char* filename = argv[1];
    double temperature;
    int error = read_temperature(filename, &temperature);
    if (error) {
        fprintf(stderr, "NIX GUT: %d\n", error);
        return 2;
    }

    printf("%lf\n", temperature);
    return 0;
}
