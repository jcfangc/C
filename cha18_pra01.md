### ��ָ�����������Ĵ洢���ͣ������޶���������˵�������������ͳ�ʼ��ʽ��
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

�ο��𰸣�<br>
|���|����|�洢����|�����޶���|����˵����|������|��ʼ��ʽ|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|(a)|static char **lookup(int level);|static|/|char|\*\*lookup(int level);|/|
|(b)|volatile unsigned long io_flags;|auto(Ĭ��)|volatile|unsigned long|io_flags|/|
|(c)|extern char \*file_name[MAX_FILES], path[];|extern|/|char|\*file_name[MAX_FILES] �� path[]|/|
|(d)|static const char token_buf[] = "";|static|const|char|token_buf[]|"" �� {��\0��}|
