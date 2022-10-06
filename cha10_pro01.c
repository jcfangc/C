// 修改 10.2 节的栈示例使它存储字符而不是整数。接下来，增加 main 函数，用来要求用户输入一串圆括号或花括号，然后指出它们之间的嵌套是否正确:

// Enter parenteses and/or braces:((){}{()})
// Parenteses/braces are nested properly

// 提示：读入左圆括号或左花括号时，把它们像字符一样压入栈中。当读入右圆括号或右花括号时， 把栈顶的项弹出，并且检查弹出项是否是匹配的圆括号或花括号。（如果不是，那么圆括号或花括号嵌套不正确。）当程序读入换行符时，检查栈是否为空。如果为空，那么圆括号或花括号匹配：如果 栈不为空（或者如果曾经调用过 stack_ underflow 函数），那么圆括号或花括号不匹配。如果调用 stack_overflow 函数，程序显示信息 Stack overflow，并且立刻终止。

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

// 清空栈的函数
void make_empty(void);
// 确认栈是否清空的函数，返回值是布尔值，当栈被清空时应该返回真值
_Bool is_empty(void);
// 确认栈是否装满的函数，返回值是布尔值，当栈被装满时应该返回真值
_Bool is_full(void);
// 将一个字符压入栈中，期待的实际参数是字符型
void push(char);
// 将一个字符弹出栈顶，返回值是字符型
char pop(void);
// 压入的字符数量超过了栈设置的上限，提示并结束程序
void stack_overflow(void);
// 栈已经被情况但仍被要求弹出数据时提示并结束程序
void stack_underflow(void);

int main(void)
{
    char input;

    printf("\n\t Enter parentheses and/or braces: ");

    // 先清空栈
    make_empty();
    if (is_empty()) {
        // 输入条件不用检测是否栈已经满了是因为在真正输入的函数中已经添加了检测的动作机制
        while ((input = getchar()) != '\n') {
            if (input == '(' || input == '{') {
                push(input);
            }
            else if (input == ')') {
                if ('(' != pop()) {
                    printf("\n\t Parantheses/braces are not nested properly. ");
                }
            }
            else if (input == '}') {
                if ('{' != pop()) {
                    printf("\n\t Parantheses/braces are not nested properly. ");
                }
            }
            else {
                ; // 用于跳过和括号无关的内容
            }
        }
        if (input == '\n') {
            if (is_empty()) {
                printf("\n\t Parantheses/braces are nested properly. ");
            }
            else if (!is_empty()) {
                printf("\n\t Parantheses/braces are not nested properly. ");
            }
        }
    }

    getchar();
    printf("\n\n");
    return 0;
}

void make_empty(void)
{
    top = 0;
}

_Bool is_empty(void)
{
    return (top == 0);
}

_Bool is_full(void)
{
    return (top == STACK_SIZE);
}

void push(char ch)
{
    if (is_full()) {
        stack_overflow();
    }
    else {
        contents[top++] = ch;
    }
}

char pop(void)
{
    if (is_empty()) {
        stack_underflow();
    }
    else {
        return contents[--top];
    }
}

void stack_overflow(void)
{
    printf("\n\t Pushing is banned. The content is full.");

    getchar();
    printf("\n\n");
    exit(0);
}

void stack_underflow(void)
{
    printf("\n\t Popping is banned. The contents is empty.");
    printf("\n\t Parantheses/braces are not nested properly. ");

    getchar();
    printf("\n\n");
    exit(0);
}