#include <stdio.h>
#include <string.h>

#define ERROR(x,y) fprintf(stderr,x,y)

int main(int argc, char *argv[])
{
    int index = 3;

    ERROR("\n\t Range error: index = %d", index);

    getchar();
    return 0;
}