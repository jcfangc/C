### 假设程序由 3 个源文件构成：main.c，f1.c 和 f2.c，此外还包括两个头文件 f1.h 和 f2.h。全部 3 给源文件都包含 f1.h，但是只有 f1.c 和 f2.c 包含 f2.h。维系程序编写 makefile。假设使用 gcc 编译器，且可执行文件明明为 demo。

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