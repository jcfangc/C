// 请说明下列程序的输出结果，并解释程序的功能。

#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

int main(void)
{
    printf("Answer: %d\n", f1(f2));
    return 0;
}

int f1(int (*f)(int))
{
    int n = 0;

    while ((*f)(n)) n++;
    return n;
}

int f2(int i)
{
    return i * i + i - 12;
}

// 首先我们需要明确一个概念，那就是 while 的括号中，非零都是真，只有零才代表假。弄清楚了这一点，理解起来基本就不会太困难了。
// f1 的目的就是找到函数指针 f 所指代的函数返回值为零时的参数。
// f2 的目的就是根据参数 i 计算二次代数式并返回结果。
// 易知 0 = i * i + i - 12 有 -4 和 3 两个实数根，考虑到 f1 对参数是从 0 开始枚举，逐次 +1，所以这里返回的最终只会是正实数根。
// 所以输出结果是 Answer: 3

// 原书作者答案：http://knking.com/books/c2/answers/c17.html