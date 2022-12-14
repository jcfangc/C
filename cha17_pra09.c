// 判断：如果 x 是一个结构而 a 是该结构的成员，那么 (&x)->a 与 x.a 是一样的。验证你的判断。

// 是一样的。书本中的原话是 “运算符 -> 是运算符 * 和运算符 . 的组合，它先对 new_node 间接寻址以定位所指向的结构，然后再选择结构的成员 value”。这里 new_node 是一个结构，value 是其成员。下面通过代码进行验证。

#include <stdio.h>

typedef struct suc {
    int a;
} suc;

int main(void)
{
    struct suc x;

    (&x)->a = 1;

    // 如果可以成功给 a 成员赋值，下面的 if 条件就是真
    if ((&x)->a == 1) {
        x.a = 0;
    }

    // 如果 x.a 可以给 a 赋值，下面打印的值会是 0
    printf("\n\t Test: %d", x.a);

    getchar();
    return 0;
}