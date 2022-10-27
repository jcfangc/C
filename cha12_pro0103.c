// (a) 编写程序读一条信息，然后逆序打印出这条信息：

// Enter a message: Don't get mad, get even.
// Reversal is: .neve teg ,dam teg t'noD

// 提示：一次读取信息中的一个字符（用 getchar 函数），并且把这些字符存储在数组中，当数组满了或者读到字符 ‘\n’ 时停止读操作。
// (b) 修改上述程序，用指针代替整数来跟踪数组中的当前位置

// 编程题 3：请利用数组名可以用作指针的事实简化编程题 1 的（b）程序。
// 参考答案如下：


#include <stdio.h>

#define MAX_LEN 30

int main(void)
{
    char ch;
    char message[MAX_LEN];
    char(*here);

    here = message;

    printf("\n\t Enter a message: ");
    while ((ch = getchar()) != '\n') {
        if (here == message + MAX_LEN) {
            break;
        }
        *here++ = ch;
    }

    printf("\n\t Reversal is: ");
    for (; here >= message;) {
        printf("%c", *--here);
    }

    getchar();
    return 0;
}


// 原书作者答案：
// 编程题 1：

// #include <stdio.h>

// #define MSG_LEN 80     /* maximum length of message */

// int main(void)
// {
//     char msg[MSG_LEN], *p;

//     printf("Enter a message: ");
//     for (p = &msg[0]; p < &msg[MSG_LEN]; p++) {
//         *p = getchar();
//         if (*p == '\n')
//             break;
//     }

//     printf("Reversal is: ");
//     for (p--; p >= &msg[0]; p--)
//         putchar(*p);
//     putchar('\n');

//     return 0;
// }


// 编程题 3：

// #include <stdio.h>

// #define MSG_LEN 80     /* maximum length of message */

// int main(void)
// {
//     char msg[MSG_LEN], *p;

//     printf("Enter a message: ");
//     for (p = msg; p < msg + MSG_LEN; p++) {
//         *p = getchar();
//         if (*p == '\n')
//             break;
//     }

//     printf("Reversal is: ");
//     for (p--; p >= msg; p--)
//         putchar(*p);
//     putchar('\n');

//     return 0;
// }