// 编写名为 sum.c 的程序，用来对命令行参数（假设都是整数）求和。如果键入
// sum 8 24 62
// 运行程序，产生的输出应为
// Total：94
// 提示：用 atoi 函数（→26.2节）把每个命令行参数从字符串格式转换成整数格式。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int total = 0;

    // argv[0] --> 程序名
    // argv[1] --> "sum"
    if (strcmp(argv[1], "sum") == 0) {
        for (int i = 2; i < argc; i++) {
            total += atoi(argv[i]);
        }
    }

    printf("\n\t Total: %d ", total);

    getchar();
    return 0;
}