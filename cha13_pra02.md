### 假设 p 的声明如下：<br> char *p = "abc"; <br> 下列哪些函数调用是合法的？请说明每个合法函数调用的输出，并结束为什么其他是非法的。

<br>

|小题|参考答案|
|:-|:-|
|(a) putchar(p);|不合法。putchar 函数希望得到一个 int（char）的参数，而本题 p 本身是一个指向字符串的指针。即，char \* 类型。|
|(b) putchar(*p);|合法。putchar 函数会输出 p 所指向的字符，也就是 'a'。因为 (\*p) 的类型为 char，符合 putchar 的期望。同时这也意味着 (\*(p + 1))，(\*(p + 2))，(\*(p + 3)) 也都是可取的，分别输出 'b'，'c'，'\0'。|
|(c) puts(p);|合法。puts 函数得到了 char *p，作为实际参数，而 puts 本身期待的参数就是 const char * 类型的。他会输出 p 所指向的字符串，并在遇见第一个 '\0' 后输出一个换行符，结束操作。所以输出内容是：abc （换行）|
|(d) puts(*p);|不合法。puts 函数中的形式参数类型是 const char * ，而 *p 的类型则是 char。|

<br>

|原书作者答案：|
|:-|
|(a) Illegal; p is not a character.|
|(b) Legal; output is a.|
|(c) Legal; output is abc.|
|(d) Illegal; *p is not a pointer.|
|（ 源自：http://knking.com/books/c2/answers/c13.html ）|