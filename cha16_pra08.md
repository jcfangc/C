### 设 color 是如下的结构：
***
~~~
    struct color {
        int red;
        int green;
        int blue;
    };
~~~
(a) 为 struct color 类型的 const 变量 MAGENTA 编写声明，成员的值分别为 255，0 和 255。<br>
(b) (C99) 重复上题，但是使用执行初始化式。要求不指定 green 的值，使其默认为 0。<br>
***

<br>

参考答案：<br>
(a)<br>
~~~
    const struct color MAGENTA = { 255, 0, 255 };
~~~

<br>

(b)<br>
~~~
    const struct color MAGENTA = { .red = 255, 0, .blue = 255 };
~~~