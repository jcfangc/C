### 下列循环希望删除链表中的全部节点，并且释放它们的内存。但是，此循环有错误。请解释错误是什么并说明如何修正错误。
***
~~~
    for (p = first; p != NULL; p = p->next) {
        free(p);
    }
~~~
***

<br>

参考答案：<br>
当 first 为非空指针时，此时可以进入循环体，释放了当前 p 的内存空间并到达循环体尾部，需要重新检测循环条件。但是此时 p 被释放了内存空间，这意味着悬空指针 p 不能进行条件的判定。退一步说，哪怕 p 通过判定，由于 p 被释放了内存，此时 p = p->next 也没有了意义。综上，更改如下：
~~~
    for (node *pre = NULL, *cur = first; cur != NULL; pre = cur, cur = cur->next) {
        if (pre == NULL) {
            continue;
        }
        if (cur->next == NULL) {
            // 为了 cur != NULL 有意义，不可以直接释放 cur，在这里先将 cur 转移至下一节点
            cur = cur->next;
            // 由 pre->next 代替 cur 进行当前节点的释放
            free(pre->next);
            // 删除前节点
            free(pre);
            // 此时不可以再进行到循环尾，因为 cur = cur->next 的存在，会导致 cur 指向空指针的下一个内存位置，内存溢出
            break;
        }
        free(pre);
    }
~~~

<br>

书作者答案链接：<br>
~~~
    struct node *temp;

    p = first;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
~~~
http://knking.com/books/c2/answers/c17.html

<br>

可以明显看出笔者的代码量是远远超出书作者提供的答案的。笔者在自己编写代码时也发现由于逻辑上有很多不严谨的地方，在进入循环体之后，出现了种种意料之外的错误，然后根据错误添加打了补丁，每一个注释都体现了笔者的错误原因。而且笔者的代码在面对只有一个节点的链表会出现无法正常删除节点的情况。总而言之，书作者的答案要好得多。