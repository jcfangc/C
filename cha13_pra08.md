### 在执行下列语句后，字符串 str 的值是什么？<br>strcpy(str, ""tire-bouchon");<br>strcpy(&str[4], "d-or-wi");<br>strcat(str, "red?");

<br>

参考答案：<br>
tired-or-wired?<br>
这里最大的陷阱就是空字符的存在，如果没有注意空字符的存在就会误解为：<br>
~~~
    strcpy(str, ""tire-bouchon");               tire-bouchon
    strcpy(&str[4], "d-or-wi");                     d-or-wi
                                            -----------------------
                                                tired-or-win
    strcat(str, "red?");                                    red?
                                            -----------------------
                                                tired-or-winred?
~~~
然而，空字符的存在是很关键的：<br>
~~~
    strcpy(str, ""tire-bouchon");               tire-bouchon\0
    strcpy(&str[4], "d-or-wi");                     d-or-wi\0
                                            -----------------------
                                                tired-or-wi\0
    strcat(str, "red?");                                   red?\0
                                            -----------------------
                                                tired-or-wired?\0
~~~
执行 strcpy(&str[4], "d-or-wi"); 时，只有注意到了空字符的存在才能将 str 末尾的 n 进行替换，从而得到正确答案。<br>

原书作者答案：<br>
tired-or-wired?<br>
（ 源自：http://knking.com/books/c2/answers/c13.html ）
