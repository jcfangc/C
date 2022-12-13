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
|题号|回答|
|:-|:-|
|(a)|3|
|(b)|0|
|(c)|第一个没有出现在 t 中的 s 的字母在数组 s 中的位置|

（ 原文链接：http://knking.com/books/c2/answers/c13.html ）