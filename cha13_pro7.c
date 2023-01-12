// 修改第 5 章的编程题 11，用字符串指针数组取代 switch 语句。例如，现在不再用 switch 语句来显示第一位数字对应的单词，而把该数字用作下标从包含 “twenty”、“thirty” 等字符串数组中搜索。

// 第 5 章 编程题 11：
// 编写一个程序，要求用户输入一个两位数，然后显示该数的英文单词：
// Enter a two-digit number：45
// You entered the number forty-five.
// 提示：把数分解为两个数字。用一个 switch 语句显示第一位数字对应的单词（“twenty”、“thirty” 等），用第二个 switch 语句显示第二位数字对应的单词。不要忘记 11 ~ 19 需要特殊处理。

#include <stdio.h>

int main(int argc, char *argv[])
{
    int entered_num;
    char *teen[10] = { "ten", "eleven", "twelve", "thirteen", "forteen", "fifteen", "sixteen", "seven", "eighteen", "nineteen" };
    char *teens[8] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty" };
    char *digit[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (;;) {
        printf("\n\t Enter a two-digit number: ");
        scanf(" %d", &entered_num);
        getchar(); // '\n'

        if (entered_num >= 10 && entered_num < 100) {
            break;
        }
    }

    if (entered_num < 20) {
        printf("\n\t You entered the number %s.", teen[(entered_num % 10)]);
    }
    else if (entered_num >= 20) {
        // 十位数字
        int timesof_10 = 2;
        for (;;) {
            if (++timesof_10 * 10 >= entered_num) {
                break;
            }
        }
        // 由于副作用在判断条件处，退出时 timesof_10 会是预期数 + 1，这便是下面 - 1 的由来。
        printf("\n\t You entered the number %s", teens[(timesof_10 - 1 - 2)]);
        if (entered_num % 10 != 0) {
            printf(" - %s", digit[(entered_num % 10) - 1]);
        }
        printf(".");
    }

    getchar();
    return 0;
}