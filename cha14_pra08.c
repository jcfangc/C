// 答案参考自：https://zhuanlan.zhihu.com/p/30741466

#include <stdio.h>

#define STRINGALIZE(x) #x
#define STRINGALIZE2(x) STRINGALIZE(x)
#define LINE_FILE "Line "STRINGALIZE2(__LINE__)" of file "__FILE__

int main(void)
{
    const char *str = LINE_FILE;

    printf("\n\t %s", str);

    getchar();
    return 0;
}

// 重要概念：
// 替换列表中依赖 ## 的宏通常不能嵌套调用。这里的问题在于 CONCAT(a, CONCAT(b, c)) 不会按照 “正常” 的方式扩展 —— CONCAT(b, c) 首先得出 bc，然后 CONCAT(a, bc) 给出 abc。在替换列表中，位于 ## 运算符之前和之后的红参数在替换时不被扩展，因此，CONCAT(a, CONCAT(b, c)) 扩展成 aCONCAT(b, c)，而不会进一步扩展，因为没有名为 aCONCAT 的宏。
// 有一种办法可以解决这个问题，但不太好看。技巧是再定义一个宏来调用第一个宏：
// #define CONCAT2(x, y) CONCAT(x, y)
// 用 CONCAT2(a, CONCAT2(b, c) 就会得到我们期望的结果。在扩展外面的 CONCAT2 调用时，预处理器将会同时扩展 CONCAT2(b, c)。这里的区别在于 CONCAT2 的替换列表不包含 ##。如果这个也不行，那也不用担心，这种问题并不是经常会遇到。
// 顺便提一下，#运算符也有同样的问题。如果 #x 出现在替换列表中，其中 x 是一个宏参数，其对应实际参数也不会被扩展。因此，假设 N 是一个代表 10 的宏，且 STR(x) 包含替换列表 #x，STR(N) 扩展的结果为 “N”，而不是 “10”。解决的办法与处理 CONCAT 时类似：再定义一个宏来调用 STR。
