### 请指出下列声明的存储类型，类型限定符，类型说明符，声明符和初始化式。
***
~~~
    // (a)
    static char **lookup(int level);
    // (b)
    volatile unsigned long io_flags;
    // (c)
    extern char *file_name[MAX_FILES], path[];
    // (d)
    static const char token_buf[] = "";
~~~
***

<br>

参考答案：<br>
|题号|声明|存储类型|类型限定符|类型说明符|声明符|初始化式|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|(a)|static char **lookup(int level);|static|/|char|\*\*lookup(int level);|/|
|(b)|volatile unsigned long io_flags;|auto(默认)|volatile|unsigned long|io_flags|/|
|(c)|extern char \*file_name[MAX_FILES], path[];|extern|/|char|\*file_name[MAX_FILES] 和 path[]|/|
|(d)|static const char token_buf[] = "";|static|const|char|token_buf[]|"" 或 {‘\0’}|
