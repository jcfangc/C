### 下面的函数希望打印一条出错消息。每条消息的前面有一个整数，表明函数已经被调用了多少次。但是消息前面的整数总是 1。找出错误所在，并说明如何在不对函数外部做任何修改的情况下修正该错误。
***
~~~
    void print_error(const char *message)
    {
        int n = 1;
        printf("ERROR %d: %s\n", n++, message);
    }
~~~
***

<br>

参考答案：<br>
~~~
    void print_error(const char *message)
    {
        static int n = 1;
        printf("ERROR %d: %s\n", n++, message);
    }
~~~