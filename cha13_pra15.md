### 函数 f 如下所示：
***
~~~
    int f(char *s, char *t)
    {
        char(*p1), (*p2);

        for (p1 = s; *p1; p1++) {
            for (p2 = t; *p2; p2++) {
                if (*p1 == *p2) {
                    break;
                }
            }
            if ((*p2) == '\0') {
                break;
            }
        }
        return (p1 - s);
    }
~~~
(a) f("abcd", "babc") 的值是多少？<br>
(b) f("abcd", "bcd") 的值是多少？<br>
(c) 当传递两个字符串 s 和 t 时，函数 f 的返回值一般是什么？
***

<br>

参考答案：<br>
|题号|回答|
|:-|:-|
|(a)|3|
|(b)|0|
|(c)|第一个没有出现在 t 中的 s 的字母在数组 s 中的位置|

（ 原文链接：http://knking.com/books/c2/answers/c13.html ）