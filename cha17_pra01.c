// 每次调用时都检查函数 malloc （或其他任何内存分配函数）的返回值是件很烦人的事情。请编写一个名为 my_malloc 的函数作为 malloc 函数的 “包装器”。当调用函数 my_malloc 并要求分配 n 个字节时，它会调用 malloc 函数，判断 malloc 函数确实没有返回空指针，然后返回来自 malloc 的指针。如果 malloc 返回空指针，那么函数 my_malloc 显示出错信息并终止程序。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL_ERR printf("\n\t Null pointer returned in %s", __func__)
#define N 2147483647

void *my_malloc(size_t);

int main(void)
{
    char *str;

    str = my_malloc(N * sizeof(char));
    strncpy(str, "My_malloc works well.", N);
    printf("\n\t %s", str);
    free(str);

    getchar();
    return 0;
}

void *my_malloc(size_t size)
{
    void *p;

    if ((p = malloc(size)) == NULL) {
        NULL_ERR;
        getchar();
        exit(EXIT_FAILURE);
    }

    return p;
}
