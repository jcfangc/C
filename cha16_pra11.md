### 假如 s 是如下结构：
***
~~~
    struct {
        double a;
        union {
            char b[4];
            double c;
            int d;
        } e;
        char f[4];
    } s;
~~~
如果 char 类型值占有 1 个字节，int 类型值占有 4 个字节，而 double 类型值占有 8 个字节，那么 C 编译器将为 s 分配多大的内存空间？（假设编译器没有在成员之间留有 “空洞”。）
***

<br>

参考答案：<br>
struct 会为每个成员都分配各自的内存，但是 union 只会根据其中的一个最大的类型的成员所需的内存大小分配内存。所以，总共分配的字节数是 8(double a) + 8(union {... double c ...} e) + 4(char f[4]) = 20

<br>

书作者答案：http://knking.com/books/c2/answers/c16.html<br>
The a member will occupy 8 bytes, the union e will take 8 bytes (the largest member, c, is 8 bytes long), and the array f will require 4 bytes, so the total space allocated for s will be 20 bytes.