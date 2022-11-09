### 下面的问题设计练习题 5 描述的程序。<br>(a)等程序第一次构建时，需要对那些文件进行编译？<br>(b)如果在程序构建后对 f1.c 进行了修改，那么需要对哪个（些）文件进行重新编译？<br>(c)如果在程序构建后对 f1.h 进行了修改，那么需要对哪个（些）文件进行重新编译？<br>(d)如果在程序构建后对 f2.h 进行了修改，那么需要对哪个（些）文件进行重新编译？

<br>

参考答案：
~~~
    demo: main.o f1.o f2.o
        gcc main.o f1.o f2.o -o demo
    main.o: main.c f1.h
        gcc -c main.c -o main.o
    f1.o: f1.c f1.h f2.h
        gcc -c f1.c -o f1.o
    f2.o: f2.c f1.h f2.h
        gcc -c f2.c -o f2.o
~~~

<br>

|序号|回答|
|:-|:-|
|a|第一次构建文件时，就是在上面的 makefile 文件中缩写的那样，在链接这一步之前，我们需要生成 main.o，f1.o，f2.o 这三个目标文件，也是我们所需要的所有的目标文件。这些目标文件通过对 main.c，f1.c，f2.c 这三个源文件进行编译得到，这也是所有需要编译的文件。|
|b|只有 f1.c 需要重新编译并生成目标文件 f1.o。|
|c|可以看到，所有目标文件对 f1.h 都存在依赖，所以所有目标文件都需要重新生成，即 main.c，f1.c，f2.c 这三个源文件都需要重新编译。|
|d|对 f2.h 存在以来的只有 f1.o 和 f2.o，所以生成这两个目标文件的源文件 f1.c 和 f2.c 需要重新编译。|

<br>

书作者答案：http://knking.com/books/c2/answers/c15.html<br>
(a) main.c, f1.c, and f2.c.<br>
(b) f1.c (assuming that f1.h is not affected by the change).<br>
(c) main.c, f1.c, and f2.c, since all three include f1.h.<br>
(d) f1.c and f2.c, since both include f2.h.
