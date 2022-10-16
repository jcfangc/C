### 编写下列函数：
### void split_time(long total_sec, int *hr, int *min, int *sec);
### total_sec 是以从午夜计算的秒数计算时间。hr、min 和 sec都是指向变量的指针，这些变量在函数中分别存储小时（0-23）、分钟（0-59）和秒（0-59）为单位的等价时间。

<br>

#### 参考答案：
~~~
    void split_time(long total_sec, int *hr, int *min, int *sec)
    {
        if (total_sec <= 86400) {
            *hr = (total_sec / (60 * 60));
            *min = ((total_sec - (*hr * 3600)) / 60);
            *sec = ((total_sec - (*hr * 3600)) - (*min * 60));

        }
        else {
            printf("\n\t Invalid Total Second(s).");
        }
    }
~~~