### 按照下述要求分别修改 read_line 函数。<br> (a) 在开始存储输入字符前跳过空白字符。<br> (b) 在遇到第一个空白字符时停止读入。提示：调用 isspace 函数（→23.5节）来检查字符是否为空白字符。<br> (c) 在遇到第一个换行符时停止读入，然后把换行符存储到字符串中。<br> (d) 把没有空间存储的字符留下以后备用。

<br>

参考答案：<br>
这里我们把本章程序 remind.c 中的 read_line 作为原型。
~~~
    int read_line(char str[], int len)
    {
        char ch;
        int i = 0;

        while ((ch = getchar()) != '\n') {
            if (i < len) {
                str[i++] = ch;
            }
        }

        str[i] = '\0';
        return i;
    }
~~~

<br>

(a) 在开始存储输入字符前跳过空白字符。<br>
~~~
    int read_line(char str[], int len)
    {
        char ch;
        int i = 0;

        // (a) 在开始存储输入字符前跳过空白字符。
        while (isspace(ch = getchar())) {
            ;
        }

        do {
            if (i < len) {
                str[i++] = ch;
            }
        } while ((ch = getchar()) != '\n');

        str[i] = '\0';
        return i;
    }
~~~

<br>

(b) 在遇到第一个空白字符时停止读入。提示：调用 isspace 函数（→23.5节）来检查字符是否为空白字符。<br>
~~~
    int read_line(char str[], int len)
    {
        char ch;
        int i = 0;

        while ((ch = getchar()) != '\n') {
            (b) 在遇到第一个空白字符时停止读入。提示：调用 isspace 函数（→23.5节）来检查字符是否为空白字符。
            if (isspace(ch)) {
                str[i] = '\0';
                return i;
            }
            else if (i < len) {
                str[i++] = ch;
            }
        }

        str[i] = '\0';
        return i;
    }
~~~

<br>

(c) 在遇到第一个换行符时停止读入，然后把换行符存储到字符串中。<br>
~~~
    int read_line(char str[], int len)
    {
        char ch;
        int i = 0;

        while ((ch = getchar()) != '\n') {
            if (i < len) {
                str[i++] = ch;
            }
        }

        str[i++] = '\n';
        str[i] = '\0';
        return i;
    }
~~~

<br>

(d) 把没有空间存储的字符留下以后备用。<br>
~~~
    int read_line(char str[], int len)
    {
        char ch;
        int i = 0;

        while (i < len) {
            ch = getchar();
            if (i < len) {
                str[i++] = ch;
            }
        }

        str[i] = '\0';
        return i;
    }
~~~
这里主要想说一下小题（d）。题目说留下备用的意思应该就是类似于 scanf 函数的操作，将无法录入的信息放回原处，留待下一次录入。这里要注意保证只有录入的信息才被 getchar 函数使用即可。否则，没有录入的信息一但被 getchar 函数使用过，就会被视作已经被读取了。

<br>

原书作者答案：<br>
(a) 在开始存储输入字符前跳过空白字符。<br>
~~~
    int read_line(char str[], int n)
    {
        int ch, i = 0;

        while ((ch = getchar()) != '\n')
            if (i == 0 && isspace(ch))
                ;   /* ignore */
            else if (i < n)
                str[i++] = ch;
        str[i] = '\0';
        return i;
    }
~~~

<br>

(b) 在遇到第一个空白字符时停止读入。提示：调用 isspace 函数（→23.5节）来检查字符是否为空白字符。<br>
~~~
    int read_line(char str[], int n)
    {
        int ch, i = 0;

        while (!isspace(ch = getchar()))
            if (i < n)
                str[i++] = ch;
        str[i] = '\0';
        return i;
    }
~~~

<br>

(c) 在遇到第一个换行符时停止读入，然后把换行符存储到字符串中。<br>
~~~
    int read_line(char str[], int n)
    {
        int ch, i = 0;

        do {
            ch = getchar();
            if (i < n)
                str[i++] = ch;
        } while (ch != '\n');
        str[i] = '\0';
        return i;
    }
~~~
原作者的这段程序就给我很妙的感觉，用 do 循环最后才测试条件的特点，巧妙的把 \n 录入到了字符串中。

<br>

(d) 把没有空间存储的字符留下以后备用。<br>
~~~
    int read_line(char str[], int n)
    {
        int ch, i;

        for (i = 0; i < n; i++) {
            ch = getchar();
            if (ch == '\n')
                break;
            str[i] = ch;
        }
        str[i] = '\0';
        return i;
    }
~~~
（ 源自：http://knking.com/books/c2/answers/c13.html ）