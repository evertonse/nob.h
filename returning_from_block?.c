#include "stdio.h"

int main(int argc, char *argv[]) {

    float num  = ({
        argc = 123; // Some statement
        num = 3.14;    // referencing before
        (float)argc;        // ""returns"" from que block?
    });
    printf("num=%f\n", num); // value is 123.0
}

