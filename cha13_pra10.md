### 下面的函数用于创建字符串的相同副本。请指出这个函数中的错误。
***
~~~
    char *duplicate(const char *p)
    {
        char *q;

        strcpy(q, p);
        return q;
    }
~~~
***

<br>

参考答案：<br>
|代码|理解|
|:-|:-|
|char* duplicate(const char* p)|首先明确我们想要达到的功能，即复制一个字符串，最终函数返回的应该是该字符串的副本。这就意味着函数的形式参数应该首先是 cha * 或 char[] 类型的。可以看到题目中为了确保被复制的数组不会被修改添加了 const，这也是没有问题的。而函数的返回值也被设定为 char *，符合我们想要达成的输出数组的设想。|
|char(*q);|在此定义了 char * 型的指针 q，在之后是用来作为指向被复制的数组的指针。|
|strcpy(q, p);|本句用 strcpy 复制了 p 所指向的字符数组，复制到了 q 中。|
|return q;|返回成功复制好的字符数组副本 q。|

<br>

笔者看来似乎这样的函数没有什么问题，但是原书作者给出的答案说明了问题：The value of q is undefined, so the call of strcpy attempts to copy the string pointed to by p into some unknown area of memory. Exercise 2 in Chapter 17 discusses how to write this function correctly. 作者的意思大概是：变量 q 并没有得到初始化，这时它指向内存中的地址是未知的，所以当我们使用 strcpy 这个函数时，就将要被复制的字符数组放置到了内存中某个不明的地址中。后续在 17 章练习 2 中会讨论这个函数的正确写法。
（ 源自：http://knking.com/books/c2/answers/c13.html ）