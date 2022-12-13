### 利用 13.6 节中的方法来精简 13.4 节中的 count_space 函数。具体而言要用 while 循环替换 for 语句。
***
原 13.4 节中的 count_space 函数：
~~~
    int count_space(const char s[])
    {
        int count = 0, i;

        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ') {
                count++;
            }
        }

        return count;
    }
~~~
***

<br>

参考答案：<br>
~~~
    int count_space(const char str[])
    {
        int count = 0;

        while (*str != 0) {
            str++;
            if (*str == ' ') {
                count++;
            }
        }

        return count;
    }
~~~

<br>

这里 13.6 的方法应该特指这一小节中的惯用法，这里我们再回顾一下。<br>

↓ 惯用法一：搜索字符串结尾的空字符，最终让 s 指向了空字符。<br>
~~~
    while (*s) {
        s++;
    }
~~~
↓ 惯用法二：搜索字符串结尾的空字符，最终让 s 指向了空字符之后的位置。<br>
~~~
    while (*s++) {
        ;
    }
~~~
↑ ↑ 这两个惯用法的可行性主要来源于空字符的 ASCII 值恰好为零这一特点。<br>
↓ 惯用法三：字符串复制。
~~~
    while (*p++ = *s2++) {
        ;
    }
~~~
↑ 这个惯用法可以行得通是因为 “圆括号中的主要运算符是赋值运算符，所以 while 语句会测试赋值表达式的值，也就是测试复制的字符。除空字符之外的所有字符的测试结果都为真，因此，循环只有在复制空字符后才会终止。而且由于循环是在赋值之后终止，所以不需要单独使用一条语句来在新字符串末尾添加空字符。”<br>
这里还有原书作者答案可以进行参考：http://knking.com/books/c2/answers/c13.html
~~~
    int count_spaces(const char *s)
    {
        int count = 0;

        while (*s)
            if (*s++ == ' ')
                count++;
        return count;
    }
~~~