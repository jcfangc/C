### 本章的 “问与答” 部分说明了利用数组取下标操作来编写 strcmp 函数的方法。请修改此函数，改用指针算数运算来编写。
***
~~~
    int strcmp(char *s, char *t)
    {
        int i;

        for (i = 0; s[i] == t[i]; i++) {
            if (s[i] == '\0') {
                return 0;
            }
        }

        return s[i] - t[i];
    }
~~~
***

<br>

参考答案：<br>
~~~
    int mystrcmp(const char *s, const char *t)
    {
        for (; *s == *t; (s++, t++)) {
            if (*s == '\0') {
                return 0;
            }
        }

        return (*s - *t);
    }
~~~