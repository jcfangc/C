### 假定 TOUPPER 定义成下面的宏：<br>#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))<br>假设 s 是一个字符串，i 是一个 int 类型变量。给出下面每个代码片段产生的输出。
***
(a)
~~~
    strcpy(s, "abcd");
    i = 0;
    putchar(TOUPPER(s[++i]));
~~~

<br>

(b)
~~~
    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));
~~~
***

<br>

参考答案：<br>
(a)
~~~
    strcpy(s, "abcd");
    i = 0;
    putchar(TOUPPER(s[++i]));
    //          ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
    // ++i             1    2        3
    // s[++i]         'b'  'c'      'd'(output:'D')
~~~
输出为字符 ‘D’。

<br>

(b)
~~~
    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));
    //          ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
    // ++i             1                         2
    // s[++i]         '1'                       '2'
~~~
输出为数字 ‘2’。

