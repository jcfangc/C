### 编写下面的函数：
***
~~~
    void get_extension(const char *file_name, char *extension);
~~~
file_name 指向包含文件名的字符串。函数把文件名的扩展存储在 extension 指向的字符串中。例如，如果文件名是 “memo.txt”，函数将把 “txt” 存储到 extension 指向的字符串中。如果文件名没有扩展名，函数将在 extension 指向的字符串中存储一个空字符串（仅由一个空字符构成）。在函数中使用 strlen 函数和 strcpy 函数，使其尽可能简单。
***

<br>

参考答案：<br>
~~~
    void get_extension(const char *file_name, char *extension)
    {
        // 确认是否存在扩展名
        while (*file_name != '.' && *file_name != '\0') {
            file_name++;
        }
        // 无扩展名
        if ((*file_name == '\0') || (*file_name == '.' && *(file_name + 1) == '\0')) {
            *extension = '\0';
        }
        // 存在扩展名
        else {
            strcpy(extension, (file_name + 1));
        }
    }
~~~
这里并没有用到题目用允许使用的 strlen 函数，同时也是个不安全的函数，strcpy 函数使用时有可能赋值的字符数会大于 extension 所指向的字符数组的大小。
~~~
    void get_extension(const char *file_name, char *extension)
    {
        // 定位到 '.'
        for (; *file_name != '.'; file_name++) {
            if (*file_name == '\0') {
                *extension = '\0';
                return;
            }
        }

        // '.' 之后的即为扩展名
        strcpy(extension, ++file_name);
    }
~~~
这是一个更为简短的版本，但是这依旧是不安全的，理由同上。可惜的是，两个答案都不能很好的切合题意。