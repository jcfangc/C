### 用指针变量 top_ptr 代替整型变量 top 来重新编写 10.2 节的函数 make_empty、is_empty 和 is_full。

<br>

参考答案：

原程序中，content 代表栈本身的一个数组。 STACK_SIZE 则是定义的宏。

~~~
    void make_empty(void)
    {
        top_ptr = contents; // &contents[0]
    }

    bool is_empty(void)
    {
        return (top_ptr == contents);
    }

    bool is_full(void)
    {
        return top_ptr == (contents + STACK_SIZE); // &contents[STACK_SIZE]
    }
~~~