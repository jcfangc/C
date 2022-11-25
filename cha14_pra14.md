### 指出下面的程序在预处理后的形式。其中有几行可能会导致编译错误，请找出这些错误。
***
~~~
    #define N = 10
    #define INC(x) x+1
    #define SUB (x,y) x - y
    #define SQR(x) ((x)*(x))
    #define CUBE(x) (SQR(x)*(x))
    #define M1(x,y) x##y
    #define M2(x,y) #x #y

    int main(void)
    {
        int a[N], i, j, k, m;

    #ifdef N
        i = j;
    #else
        j = i;
    #endif

        i = 10 * INC(j);
        i = SUB(j, k);
        i = SQR(SQR(j));
        i = CUBE(j);
        i = M1(j, k);
        puts(M2(i, j));

    #undef SQR
        i = SQR(j);
    #define SQR
        i = SQR(j);

        return 0 ;
    }
~~~
***

<br>

参考答案：
|代码行|分析判断|
|:-|:-|
|#define N = 10|不需要 =，否则替换列表会变成 = 10，在程序被预处理后，<br>int a[N], i, j, k, m;<br>会变成<br>int a[= 10], i, j, k, m;<br>这显然是不对的。|
|#define INC(x) x+1|最好还是给参数变量和替换列表加上小括号。本程序经过预处理后，<br>i = 10 * INC(j);<br>会变成<br>i = 10 * j + 1;<br>运算顺序可能会和预期有所不同。|
|#define SUB (x,y) x - y|书写宏的格式有问题，包括参数的小括号和宏名之间是不应该有空格的，否则 C 会把参数理解为替换列表的一部分，在本程序预处理后，<br>i = SUB(j, k);<br>会变成<br>i = (j, k) x - y;<br>这里的逗号可能会被认为是运算符。显然这样的语句是不能通过编译的。|
|#define SQR(x) ((x)*(x))|本来应该是没有问题的。但是在后文中出现了对 SQR 宏解除定义，这意味着 SQR 最后是没有替换列表的，导致程序无法正常赋值。|
|#define CUBE(x) (SQR(x)*(x))|本来应该是没有问题的。为题同上|
|#define M1(x,y) x##y|宏的定义是没有问题的，但是对应的应用可能不太合理。在预处理后，代码行<br>i = M1(j, k);<br>会变成<br>i = jk;<br>但是我们的变量中并没有名为 jk 的变量。|
|#define M2(x,y) #x #y|宏的定义应该是没有问题的，但是宏的应用可能不太合理。在预处理后，<br>puts(M2(i, j));<br>会变为<br>puts("i""j");。<br>puts 的函数原型为 <br>int puts(const char *s);<br>此时有两个字符串字面量，但是 puts 只需要一个字符串变量。这有可能出现程序警告。|
|#ifdef N  ...  #else  ...  #endif|这边部分由于 N 已经被定义了，所以会留下第一个分支的语句，也就是 i = j;|

<br>

书作者答案：<br>
http://knking.com/books/c2/answers/c14.html