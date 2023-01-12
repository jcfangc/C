// 修改第 10 章的编程题 6，使其包含如下函数：
// int evaluate_RPN_expression(const char *expression);
// 函数返回 expression 指向的是 RPN 表达式的值。

// 第 10 章的编程题 6：
// 有些计算器（尤其是惠普的计算器）使用逆波兰表示法 (Reverse Polish Notation, RPN）来书写数学表达式。在这一表示法中，运算符放置在操作数的后面而不是放在操作数中间。例如，在逆波兰表示法中 1 + 2 将表示为 1 2 +，而 1 + 2 * 3 将表示为 1 2 3 * +。逆波兰表达式可以很方便地用栈求值。算法从左向右读取运算符和操作数，并执行下列步骤。
// （1）当遇到操作数时，将其压入栈中。
// （2）当遇到运算符时，从栈中弹出它的操作数，执行运算并把结果压入栈中。
// 编写程序对逆波兰表达式求值。操作数都是个位的整数，运算符为 +、-、*、/ 和 =。遇到运算符 = 时，将显示栈顶项，随后清空栈并提示用户计算新的表达式。这一过程持续进行，直到用户输入一个既不是运算符也不是操作数的字符为止：

// Enter an RPN expression: 1 2 3 * + =
// Value of expression: 7
// Enter an RPN expression: 5 8 * 4 9 - / =
// Value of expression: -8
// Enter an RPN expression : q

// 如果栈出现上溢，程序将显示消息 Expression is too complex 并终止。如果栈出现下溢（例如表达式 1 2 + +），程序将显示消息 Not enough operands in expression 并终止 10.2 节的栈代码整合到你的程序中。使用 scanf(" %c", &ch) 读取运算符和操作数。


#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define ON 1
#define OFF 0

float stack_1[STACK_SIZE / 2] = { 0 };
float *top = stack_1;

int read_line(char[], int);
int evaluate_RPN_expression(const char *);
int push(float);
float pop();

int main(int argc, char *argv[])
{
    char content[STACK_SIZE] = "";

    printf("\n\t Enter an RPN expression: \
    \n\t (number saperated by space and end with =) \n\n\t ");
    read_line(content, STACK_SIZE);

    printf("\n\t RESULT: %d ", evaluate_RPN_expression(content));

    getchar();
    return 0;
}

int read_line(char str[], int len)
{
    char ch;
    char *p = str;

    while (((ch = getchar()) != '\n') && (p < str + len)) {
        *p++ = ch;
    }

    *p = '\0';
    return (int)(p = str);
}

int evaluate_RPN_expression(const char *expression)
{
    const char *ptr = expression;
    char numbers[11] = "1234567890";
    char operators[6] = "+-*/=";
    float operand;
    char operand_ch[20];

    for (;;) {
        //  表达式信息分类（数字类 / 分隔类 / 符号类）
        _Bool num = OFF, opr = OFF, blk = OFF;
        // 符号类：
        //  识别到操作符
        //  弹出栈顶两个数计算
        //  计算值压回栈中
        for (int i = 0; i < 5; i++) {
            if ((*ptr) == operators[i]) {
                opr = ON;
                float x, y;
                switch (i) {
                    case 0:
                        x = pop();
                        y = pop();
                        push(x + y);
                        break;
                    case 1:
                        x = pop();
                        y = pop();
                        push(y - x);
                        break;
                    case 2:
                        x = pop();
                        y = pop();
                        push(x * y);
                        break;
                    case 3:
                        x = pop();
                        y = pop();
                        if (x) {
                            push(y / x);
                        }
                        else {
                            printf("\n\t %.2f is not allowed to be denominator. \
                        \n\t press any key to end... ", x);
                            getchar();
                            exit(EXIT_FAILURE);
                        }
                        break;
                    case 4:
                        return (int)(pop());
                        break;
                    default:
                        printf("\n\t Wrong mark \
                        \n\t press any key to end... ");
                        getchar();
                        exit(EXIT_FAILURE);
                }
                ptr++;
                break;
            }
        }
        if (opr) {
            // 符号型信息被处理，说明该位置字符已经被识别
            opr = OFF;
            continue;
        }

        // 分隔类：
        // 略过当前的分隔符将程序流推到下一个数字类或符号类的信息去
        if ((*ptr) == ' ') {
            blk = ON;
            ptr++;
        }
        if (blk) {
            // 分隔符型信息被处理，说明该位置字符已经被识别
            blk = OFF;
            continue;
        }

        // 数字类：
        //  识别数转化数
        //  识别到的数压入栈中
        int ch_count = 0;
        int all_tried = 0;
        for (int i = 0; i < 10; i++) {
            num = ON;
            if ((*ptr) == numbers[i]) {
                operand_ch[ch_count++] = *ptr++;
                all_tried = 0;
                i = 0;
                continue;
            }
            else {
                all_tried++;
                if (all_tried == 9) {
                    operand_ch[ch_count] = '\0';
                    operand = (float)atof(operand_ch);
                    push(operand);
                    break;
                }
            }
        }
        ch_count = 0;
        if (num) {
            // 数字型信息被处理，说明该位置字符已经被识别
            num = OFF;
            continue;
        }
    }
}

int push(float num)
{
    (*top++) = num;
    return (int)(top - stack_1);
}

float pop()
{
    return (*--top);
}