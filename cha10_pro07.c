// 在chapter 8 practice 6中
// 关于七段码显示数字的顺序
//       0
//      ——
//    1| 2|3
//      ——
//    4| 5|6
//      ——

#include <stdio.h>

#define MAX_DIGITS 10

void clear_digits_array(void);
// 第一个形式参数应该输入相应的需要录入的数字，第二个形式参数应该输入和位数相关的数字
void process_digit(int, int);
void print_digits_array(void);

const int segments[10][7] = {
    {1, 1, 0, 1, 1, 1, 1}, // 0
    {0, 0, 0, 1, 0, 0, 1}, // 1
    {1, 0, 1, 1, 1, 1, 0}, // 2
    {1, 0, 1, 1, 0, 1, 1}, // 3
    {0, 1, 1, 1, 0, 0, 1}, // 4
    {1, 1, 1, 0, 0, 1, 1}, // 5
    {1, 1, 1, 0, 1, 1, 1}, // 6
    {1, 0, 0, 1, 0, 0, 1}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9
};

char digits[3][4 * MAX_DIGITS];

int main(void)
{
    // digit 变量用于记录用户输入的是第几位数，注意和 process_digit 的第一个形式函数相区别
    // 这里的 digit 相当于 process_digit 中 position 的作用
    int digit = 0;
    char store_num_char[MAX_DIGITS + 1] = { '\0' }, ch;
    int store_num_int[MAX_DIGITS];

    // 清空用于存贮段码字的数组，或者说初始化数组
    clear_digits_array();

    // 引导用户输入
    printf("\n\t Enter a number (less than %d digits): ", MAX_DIGITS);

    // 首先将用户输入的数字先放入普通数组中进行缓存和统计
    for (; ((ch = getchar()) != '\n') && (digit < MAX_DIGITS); digit++) {
        store_num_char[digit] = ch;
    }
    // 由于最后一次哪怕不执行循环体，也会检查循环条件，此后 digit 会自动加一

    // 将字符型数组转化为 int 型
    for (int i = 0; i < digit; i++) {
        switch (store_num_char[i]) {
        case'0':
            store_num_int[i] = 0;
            break;
        case'1':
            store_num_int[i] = 1;
            break;
        case'2':
            store_num_int[i] = 2;
            break;
        case'3':
            store_num_int[i] = 3;
            break;
        case'4':
            store_num_int[i] = 4;
            break;
        case'5':
            store_num_int[i] = 5;
            break;
        case'6':
            store_num_int[i] = 6;
            break;
        case'7':
            store_num_int[i] = 7;
            break;
        case'8':
            store_num_int[i] = 8;
            break;
        case'9':
            store_num_int[i] = 9;
            break;
        default:
            break;
        }
    }

    // 接下来将 store_num_int 中的元素依次传入 process_digit 中转换为段码，存入 digits 中
    for (int i = 0; i < digit; i++) {
        process_digit(store_num_int[i], i);
    }

    // 打印段码数组 digits
    print_digits_array();

    getchar();
    return 0;
}

void clear_digits_array(void)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (4 * MAX_DIGITS); j++) {
            digits[i][j] = '\0';
        }
    }
}

void process_digit(int digit, int position)
{
    // 根据输入的数字，形成段码字
    // 首先决定段码字第一行中间位置，其他两个位置在任何情况下都不会有除了空字符之外的特殊显示
    if (segments[digit][0]) {
        digits[0][(position * 4) + 1] = '_';
    }
    // 其次确认第二行三个段码的位置
    if (segments[digit][1]) {
        digits[1][position * 4] = '|';
    }
    if (segments[digit][2]) {
        digits[1][(position * 4) + 1] = '_';
    }
    if (segments[digit][3]) {
        digits[1][(position * 4) + 2] = '|';
    }
    // 最后是第三行的三个段码的位置
    if (segments[digit][4]) {
        digits[2][position * 4] = '|';
    }
    if (segments[digit][5]) {
        digits[2][(position * 4) + 1] = '_';
    }
    if (segments[digit][6]) {
        digits[2][(position * 4) + 2] = '|';
    }
}

void print_digits_array(void)
{
    int blank_note_counter;
    // 按照结构顺序打印数组
    for (int row = 0; row < 3; row++) {
        printf("\n\t ");
        for (int i = 0; i < (MAX_DIGITS * 4); i++) {
            // 鉴于数字 1 的第一行都是空字符，我们使用 digits 第二行进行检测后续是否仍有未完的数字部分需要打印。
            if (digits[1][i] == '\0') {
                blank_note_counter += 1;
                if (blank_note_counter == 5) {
                    // 当 blank_note_counter 计数达到5个时，似乎可以确定用户输入的数字已经没有多余的了
                    break;
                }
            }
            else {
                // 一旦检测到非空字符，需要重新计数
                blank_note_counter = 0;
            }
            printf("%c", digits[row][i]);
        }
    }
}