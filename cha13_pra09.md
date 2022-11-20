### 在执行下列语句后，字符串 s1 的值是什么？
***
~~~
    strcpy(s1, "computer");
    strcpy(s2, "science");
    if (strcmp(s1, s2) < 0)
        strcat(s1, s2);
    else
        strcat(s2, s1);
    s1[strlen(s1) - 6] = '\0';
~~~
***

<br>

参考答案：computers<br>
~~~
    strcpy(s1, "computer");
    strcpy(s2, "science");
~~~
以上两个语句分别让 s1 和 s2 分别先后被赋予 computer\0 和 science\0 的内容。
~~~
    if (strcmp(s1, s2) < 0)
        strcat(s1, s2);
    else
        strcat(s2, s1);
~~~
以上的 if else 语句使得 s1 之后衔接了 s2 的内容。当前 s1 的内容为 computerscience\0，s2 的内容为 science。
~~~
    s1[strlen(s1) - 6] = '\0';
~~~
这里的索引是 9，将 str 中添加了一个空字符，也因此覆盖掉了字母 c。最终，s1 的内容为 computers\0cience\0。当然，当使用 s1，如打印出来的时候，会显示 s1 为 computers。