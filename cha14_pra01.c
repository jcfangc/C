// 编写宏来计算下面的值。

// （a）x 的立方。
// （b）n 除以 4 的余数。
// （c）如果 x 与 y 的乘积小于 100 则值为 1，否则值为 0。

// 你写的宏始终正常工作吗？如果不是哪些参数会导致失败呢？

#include <stdio.h>

#define CUBE(x) printf("\n\t cube of " #x " is %d (CUBE)", ((x)*(x)*(x))) 

#define CUBE_1(x) \
    do {\
        int num;\
        num = (int)(x);\
        printf("\n\t cube of " #x " is %d (CUBE_1)", ((num)*(num)*(num)));\
    } while(0)

#define CUBE_2(x) (((x) > (x)) ? (((x)+2)*((x)+3)*((x)+4)) : (((x) < (x)) ? (((x)-4)*((x)-5)*((x)-6)) : ((x)*(x)*(x))))

#define REMAINDERby4(x) \
    do {\
        int num;\
        num = (int)(x);\
        printf("\n\t remainder of " #x " devided by 4 is %d (REMAINDERby4)", (num % 4));\
    } while(0)

#define XtimesYversus100(x,y) \
    do {\
        int num_1, num_2;\
        num_1 = (int)(x);\
        num_2 = (int)(y);\
        if ((num_1 * num_2 < 100)) {\
            printf("\n\t 1 (XtimesYversus100)");\
        }\
        else {\
            printf("\n\t 0 (XtimesYversus100)");\
        }\
    } while (0)

int main(void)
{
    int i = 2;
    printf("\n\t i: %d", i);
    CUBE(i++);
    printf("\n\t i: %d", i);

    int j = 2;
    printf("\n\n\t j: %d", j);
    CUBE_1(j++);
    printf("\n\t j: %d", j);
    CUBE_1(++j);
    printf("\n\t j: %d", j);

    int x = 3, y = 3, z = 3;
    int result_ppx = CUBE_2(++x);
    printf("\n\n\t x: %d, CUBE_2(++x): %d", x, result_ppx);
    printf("\n\t y: %d, CUBE_2(y): %d", y, CUBE_2(y));
    printf("\n\t z: %d, CUBE_2(--z): %d", z, CUBE_2(--z));
    /* CUBE_2 这个宏本身其实是不完美的，因为它是否可以顺利执行往往取决于编译器对于计算顺序的判断，对于程序员来说，这样的程序运行的不同的设备上会产生不同的结果，这样的不确定性或许是个大麻烦。笔者通过测试发现本机的编译器上，当自增自减发生在变量之前时，CUBE_2 就会产生难以解释的结果，但是我请教了 C语言 方面的前辈，在他的电脑上就可以顺利的运行得到正确的结果。同时，通过和他的讨论学习，我了解到这种在 C标准 中没有明确定义的规则常被称作：undefined behavior。问题的根源是 CUBE_2 在调用参数的时候同时也在使用自增自减符号进行修改，这导致了 undefined behavior。 */

    int k = 18;
    printf("\n\n\t k: %d", k);
    REMAINDERby4(k++);
    printf("\n\t k: %d", k);
    REMAINDERby4(k);
    printf("\n\t k: %d", k);
    REMAINDERby4(--k);
    printf("\n\t k: %d", k);
    /* 在了解到 undefined behavior 之后我也打消了将后面两个小题制作一种可以直接返回数值的版本的想法，因为我想到的方案都和CUBE_2 类似，而且 CUBE_2 也并非是很好的解决方案，除了存在 undefined behavior 这个致命缺陷之外，带有副作用的参数会在宏中出现若干次，副作用也会随着出现次数增加而被放大，形象的说，就好像把变量“污染”了一样。 */

    int p = 50, q = 1;
    printf("\n\n\t %d, %d in XtimesYversus100, result: ", p, q);
    XtimesYversus100(p, q++);
    printf("\n\t %d, %d in XtimesYversus100, result: ", p, q);
    XtimesYversus100(p, q);

    getchar();
    return 0;
}