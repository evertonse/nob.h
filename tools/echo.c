#define CYE_IMPLEMENTATION
#include "cye.h"

int main(int argc, char **argv) {
    unused(shift(argv, argc));
    if (argc > 0) do
            printf("%s", shift(argv, argc));
        while (argc > 0 && printf(" "));
    printf("\n");
    fprintf(stderr, "%s", "ERROR GOES Burr\n");
    return 0;
}
