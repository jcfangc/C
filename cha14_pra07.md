### 假定 GENERIC_MAX 是如下宏：
***
~~~
    #define GENERIC_MAX(type)          \
    type type##_max(type x, type y)    \
    {                                  \
        return x > y ? x : y;          \
    }                                  \
~~~
(a) 写出 GENERIC_MAX(long) 被预处理器扩展后的形式。<br>
(b) 解释为什么 GENERIC_MAX 不能应用于 unsigned long 这样的基本类型？<br>
(c) 如何使 GENERIC_MAX 可以用于 unsigned long 这样的基本类型？提示：不要改变 GENERIC_MAX 的定义。
***

<br>

参考答案：<br>
(a)<br>
~~~
    long long_max(long x, long y) {return x > y ? x : y;}
~~~

<br>

(b)<br>
本题我没有很好的答案，参考了作者的解答，应该是这样：我们需要 unsigned long 带入扩展就会发现问题。<br>
~~~
    unsigned long unsigned long_max(unsigned long x, unsigned long y) {return x > y ? x : y;}
~~~
这样的函数声明就是在声明一个返回类型为 unsigned long unsigned 的函数，而函数名则是 long_max。这显然不是我们最初希望的。<br>
究其原因，主要是因为 unsigned long 是由两个单词组成的，并不能很好的适应宏的展开。

<br>

(c)<br>
将 unsigned long 由两个单词变为一个单词即可，正好我们存在这样一个给类型定义别名的工具 “typedef”。<br>
~~~
    typedef unsigned long UN_LONG_t;
~~~

