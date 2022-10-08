// 希望可以用该程序实现 RPN 逆波兰算式的计算

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define TOP 0

// 外部变量
int stack_index = 0;

// 说明：向栈中压入数，希望的实参是 1代表栈的数组 2数组大小 3压入的数
// 返回值：目前栈中最大的索引
int push(int[], int, int);

// 说明：向栈中弹出数，希望的实参是 1代表栈的数组 2数组大小 3栈的最大索引
// 返回值：栈顶数
int pop(int[], int, int);

int main(void)
{
    char ch;
    int stack_content[STACK_SIZE] = { 0 };
    int result;
    int var_1, var_2;

    for (;;) {
        printf("\n\t Enter a RPN calculation: (press 'q' to end) ");

        while ((ch = getchar()) != '\n') {
            switch (ch) {
            case '0':
                push(stack_content, STACK_SIZE, 0);
                break;
            case '1':
                push(stack_content, STACK_SIZE, 1);
                break;
            case '2':
                push(stack_content, STACK_SIZE, 2);
                break;
            case '3':
                push(stack_content, STACK_SIZE, 3);
                break;
            case '4':
                push(stack_content, STACK_SIZE, 4);
                break;
            case '5':
                push(stack_content, STACK_SIZE, 5);
                break;
            case '6':
                push(stack_content, STACK_SIZE, 6);
                break;
            case '7':
                push(stack_content, STACK_SIZE, 7);
                break;
            case '8':
                push(stack_content, STACK_SIZE, 8);
                break;
            case '9':
                push(stack_content, STACK_SIZE, 9);
                break;
            case '+':
                var_1 = pop(stack_content, STACK_SIZE, stack_index);
                var_2 = pop(stack_content, STACK_SIZE, stack_index);
                push(stack_content, STACK_SIZE, ((int)(var_1 + var_2)));
                break;
            case '-':
                var_1 = pop(stack_content, STACK_SIZE, stack_index);
                var_2 = pop(stack_content, STACK_SIZE, stack_index);
                // 由于 1-2 在 RPN 中写作 1 2 -，所以栈中 1 首先被压入 2 其次，因此在弹出数据时 2 会被首先弹出，1 则随后。
                // 为了还原正确的算式，我们需要将后被弹出的数据作为被减数，先被弹出的数据作为减数。
                push(stack_content, STACK_SIZE, ((int)(var_2 - var_1)));
                break;
            case '*':
                var_1 = pop(stack_content, STACK_SIZE, stack_index);
                var_2 = pop(stack_content, STACK_SIZE, stack_index);
                push(stack_content, STACK_SIZE, ((int)(var_1 * var_2)));
                break;
            case '/':
                var_1 = pop(stack_content, STACK_SIZE, stack_index);
                if (var_1 == 0) {
                    printf("\n\t Divided by 0. Program ends. ");
                    getchar(); // '\n'
                    getchar(); // end program
                    return 1;
                }
                var_2 = pop(stack_content, STACK_SIZE, stack_index);
                // 由于 1/2 在 RPN 中写作 1 2 /，所以栈中 1 首先被压入 2 其次，因此在弹出数据时 2 会被首先弹出，1 则随后。
                // 为了还原正确的算式，我们需要将后被弹出的数据作为被除数，先被弹出的数据作为除数。
                push(stack_content, STACK_SIZE, ((int)((float)var_2 / (float)var_1)));
                break;
            case '=':
                result = pop(stack_content, STACK_SIZE, stack_index);
                if (stack_index) {
                    printf("\n\t Components left. Program ends.");
                    getchar(); // '\n'
                    getchar(); // end program
                    return 1;
                }
                else {
                    printf("\t Result: %d \n", result);
                    break;
                }
            case ' ': break;
            case 'q':
            case 'Q':
                getchar(); // end program
                return 0;
            default:
                printf("\n\t Invalid Input. Program ends.");
                getchar(); // '\n'
                getchar(); // end program
                return 1;
            }
        }
    }
}

int push(int arr[], int size, int num)
{
    // 将栈元素向下挤压，留出空位
    if (stack_index > TOP && stack_index < size) {
        for (int i = stack_index - 1; i >= TOP; i--) {
            arr[i + 1] = arr[i];
        }
    }
    else if (stack_index == size) {
        printf("\n\t Stack overflow. Program ends. ");
        while (getchar() != '\n') {
            ;
        }
        getchar(); // end program
        exit(EXIT_FAILURE);
    }

    // 压入新元素
    arr[TOP] = num;
    stack_index++;

    // 返回目前index
    return stack_index;
}

int pop(int arr[], int size, int index)
{
    int popnum = arr[TOP];

    // 元素移动
    if (stack_index > TOP && stack_index < STACK_SIZE) {
        for (int i = TOP; i < stack_index; i++) {
            arr[i] = arr[i + 1];
        }
    }
    else if (stack_index == TOP) {
        printf("\n\t Stack underflow. Program ends. ");
        getchar(); // '\n'
        getchar(); // end program
        exit(EXIT_FAILURE);
    }

    // 返回弹出元素
    stack_index--;
    return popnum;
}