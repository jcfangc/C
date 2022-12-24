// 改进 13.7 节的程序 planet.c，使它在对命令行参数和 planets 数组中的字符串进行比较时忽略大小写。

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
    char *planets[] = { "mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune", "pluto" };
    int i, j;

    // agrv[0] --> 程序名
    for (i = 1; i < argc; i++) {
        // 将命令行参数全部转为小写
        for (int k = 0; k < (int)strlen(argv[i]); k++) {
            argv[i][k] = tolower(argv[i][k]);
        }
        // 比较小写化的命令行参数，遍历 planets 查看是否有相同的字符串
        for (j = 0; j < NUM_PLANETS; j++) {
            if (strcmp(argv[i], planets[j]) == 0) {
                printf("\n\t %c%s is planet %d. ", toupper(argv[i][0]), argv[i] + 1, j + 1);
                break;
            }
        }
        // j 最大值本应为 NUM_PLANETS - 1，当 j == NUM_PLANETS，说明遍历数组后没有发现匹配的字符串
        if (j == NUM_PLANETS) {
            printf("\n\t %c%s is not a planet. ", toupper(argv[i][0]), argv[i] + 1);
        }
    }

    getchar();
    return 0;
}