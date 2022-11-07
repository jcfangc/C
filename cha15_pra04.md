### 假设 debug.h 是具有如下内容的头文件：
~~~
    #ifdef DEBUG
    #define PRINTF_DEBUG(n) printf("\n\t Value of " #n ": %d", n)
    #else 
    #define PRINTF_DEBUG(n)
    #endif
~~~
### 假定源文件 testdebug.c 的内容如下：
~~~
    #include <stdio.h>

    #define DEBUG
    #include "debug.h"

    int main(void)
    {
        int i = 1, j = 2, k = 3;

    #ifdef DEBUG
        printf("\n\t Output if DEBUG is defined: ");
    #else
        printf("\n\t Output if DEBUG is not defined: ");
    #endif

        PRINTF_DEBUG(i);
        PRINTF_DEBUG(j);
        PRINTF_DEBUG(k);
        PRINTF_DEBUG(i + j);
        PRINTF_DEBUG(2 * i + j - k);

        getchar();
        return 0;
    }
~~~
***
(a) 程序执行时的输出是什么？<br>
(b) 如果从 testdebug.c 中删去 #define 指令，输出又是什么？<br>
(c) 解释 (a) 和 (b) 中的输出为什么不同。<br>
(d) 为了使 PRINTF_DEBUG 能起到预期效果，把 DEBUG 宏的定义放在 debug.h 是否有必要？验证你的结论。
***

<br>

参考答案：
|问题|回答|
|:-|:-|
|程序执行时的输出是什么？|Output if DEBUG is defined:<br>Value of i: 1<br>Value of j: 2<br>Value of k: 3<br>Value of i + j: 3<br>Value of 2 * i + j - k: 1|
|如果从 testdebug.c 中删去 #define 指令，输出又是什么？|Output if DEBUG is not defined: |
|解释 (a) 和 (b) 中的输出为什么不同。|首先时来自于原文加本身的影响：由于宏 DEBUG 没有在 #ifdef DEBUG 之前出现并定义，所以在 #ifdef DEBUG 和 #else 之间的命令行会在预处理时被处理掉，根本不会出现在被编译的文件中，同时 #else 和 #endif 之间的命令行就会取而代之通过预处理和编译，最终成为可执行文件的一部分。<br>其次是来自于头文件传递过来的影响：在头文件 debug.h 中存在这样一个参数的宏 PRINTF_DEBUG(n)，它的替换列表在 #ifdef DEBUG ... #else ... #endif 的两个分支中有所不同。当我们删除了 #define DEBUG，并包含了 debug.h 头文件后，PRINTF_DEBUG 在预处理阶段就取了 #else 和 #endif 之间的定义，即为空，原本应该出现的 pintf 函数，现在就不会出现了。|
|为了使 PRINTF_DEBUG 能起到预期效果，把 DEBUG 宏的定义放在 debug.h 是否有必要？验证你的结论。|PRINTF_DEBUG 的预期效果我们首先需要定义一下，即源文件中输出 “Output if DEBUG is defined:” 时，PRINTF_DEBUG 可以发挥出 “DEBUG is defined” 的相应功能。好比做两盏灯他们原本公用一个开关（在源文件中定义 DEBUG），两盏灯同灭同亮工作，这是正常的工作状态。但是此时我们，设置了另外的开关（在头文件中定义 DEBUG），这个开关常开，可以控制两个开关，原本的开关只能控制一个灯泡的亮灭，此时就容易出现一亮一灭的非常情况。在我们这个题目中，用一个特例来说，如果在头文件中定义了 DEBUG，那么 PRINTF_DEBUG 就永远只会进入 #ifdef 的第一个分支。此时，在源文件适当位置添加 #undef DEBUG 就会同时出现 “Output if DEBUG is not defined:”，和 PRINTF_DEBUG 的输出，然而这两个的同时出现是矛盾的。|