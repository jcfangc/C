// chapter 8 practice 6
// 关于七段码显示数字
//       0
//      ——
//    1| 2|3
//      ——
//    4| 5|6
//      ——

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    const int segments[10][7] =
    {
        {1, 1, 0, 1, 1, 1, 1}, // 0
        {0, 0, 0, 1, 0, 0, 1}, // 1
        {1, 0, 1, 1, 1, 1, 0}, // 2
        {1, 0, 1, 1, 0, 1, 1}, // 3
        {0, 1, 1, 1, 0, 0, 1}, // 4
        {1, 1, 1, 0, 0, 1, 1}, // 5
        {1, 1, 1, 0, 1, 1, 1}, // 6
        {1, 0, 0, 1, 0, 0, 1}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 0, 1, 1}, // 9
    };
    int number, digits = 0, temp_0, temp_1;
    int num[10] = { 10,10,10,10,10,10,10,10,10,10 };

    printf("Enter a number: (less than 10 digits) ");
    scanf("%d", &number);
    getchar();

    temp_0 = number;

    // 确定输入数字是几位数
    for (; number >= 10;) {
        digits++;
        number /= 10;
        printf("digit %d and counting...\n", digits);
    }
    printf("digit %d and counting...\n", ++digits);

    number = temp_0;
    temp_1 = digits;

    // 确定各个数字
    for (; digits > 0; digits--) {
        num[digits - 1] = number % 10;
        number /= 10;
        printf("%d will be shown later. \n", num[digits - 1]);
    }

    digits = temp_1;

    // 开始依次打印
    // 第一行
    printf("\n");
    for (int i = 0; num[i] != 10; i++) {
        if (segments[num[i]][0] != 0) {
            printf(" _ ");
        }
        else if (segments[num[i]][0] == 0) {
            printf("   ");
        }
        printf(" ");
    }
    // 第二行
    printf("\n");
    for (int i = 0; num[i] != 10; i++) {
        // 1号位
        if (segments[num[i]][1] != 0) {
            printf("|");
        }
        else if (segments[num[i]][1] == 0) {
            printf(" ");
        }
        // 2号位
        if (segments[num[i]][2] != 0) {
            printf("_");
        }
        else if (segments[num[i]][2] == 0) {
            printf(" ");
        }
        // 3号位
        if (segments[num[i]][3] != 0) {
            printf("|");
        }
        else if (segments[num[i]][3] == 0) {
            printf(" ");
        }
        printf(" ");
    }
    // 第三行
    printf("\n");
    for (int i = 0; num[i] != 10; i++) {
        // 4号位
        if (segments[num[i]][4] != 0) {
            printf("|");
        }
        else if (segments[num[i]][4] == 0) {
            printf(" ");
        }
        // 5号位
        if (segments[num[i]][5] != 0) {
            printf("_");
        }
        else if (segments[num[i]][5] == 0) {
            printf(" ");
        }
        // 6号位
        if (segments[num[i]][6] != 0) {
            printf("|");
        }
        else if (segments[num[i]][6] == 0) {
            printf(" ");
        }
        printf(" ");
    }

    getchar();
    return 0;
}
