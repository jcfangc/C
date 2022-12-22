// 请编写一个函数，要求在给定字符串作为实际参数时，此函数搜索下列所示的结构数组寻找匹配的命令名，然后调用和匹配名称相关的函数：
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RETURN_FUNC_NAME printf("\t %s is called. \n", __func__);

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);
void do_command(const char *);

struct cmd {
    char *cmd_name;
    void(*cmd_pointer)(void);
} file_cmd[] = {
    // 在初始化的时候笔者陷入一个误区，就是先定义了一些函数指针，和 cmd_pointer 类型相同的指针，再让这些指针有和下面初始化式中和 cmd_pointer 相关的部分相同的名字。再让这些指针指向了各自的函数。
    // 下面是错误范例：
    // void(*new_cmd)(void) = new（函数名）;
    // 这样做会收到初始化式需要常量表达式的警告，所以我们就应该反思指针的常量是什么？
    // 答案就是内存地址。而函数名正好可以作为内存地址。
    // 所以正确的做法就是在初始化式中写入符合函数指针类型的函数名即可。
    {"new",         new_cmd},
    {"open",        open_cmd},
    {"close",       close_cmd},
    {"close all",   close_all_cmd},
    {"save",        save_cmd},
    {"save as",     save_as_cmd},
    {"save all",    save_all_cmd},
    {"print",       print_cmd},
    {"exit",        exit_cmd}
};

int main(void)
{
    char command[10], ch, *p;

    for (;;) {
        p = command;
        // 输入命令
        printf("\n\t COMMANDS: \
            \n\t new \t\t open \
            \n\t close \t\t close all \
            \n\t save \t\t save as \
            \n\t save all \t print \
            \n\t exit \
            \n\t-----------------------------\n");
        printf("\n\t Enter a command: (exit to end) \n\t ");
        while ((ch = getchar()) != '\n' && p < command + 9) {
            *p++ = ch;
        }
        *p = '\0';

        // 执行命令
        do_command(command);
    }
}

void do_command(const char *str)
{
    // 匹配命令和输入文本
    for (int i = 0; i < (int)(sizeof(file_cmd) / sizeof(file_cmd[0])); i++) {
        if (strcmp(str, file_cmd[i].cmd_name) == 0) {
            // 很重要的一点是不能忘记最后的 ()，这是函数的重要标志。就好比 getchar 和 getchar()，是截然不同的。
            file_cmd[i].cmd_pointer();
            return;
        }
    }
    printf("\t Invalid command. \n");
}

void new_cmd(void) { RETURN_FUNC_NAME; }
void open_cmd(void) { RETURN_FUNC_NAME; }
void close_cmd(void) { RETURN_FUNC_NAME; }
void close_all_cmd(void) { RETURN_FUNC_NAME; }
void save_cmd(void) { RETURN_FUNC_NAME; }
void save_as_cmd(void) { RETURN_FUNC_NAME; }
void save_all_cmd(void) { RETURN_FUNC_NAME; }
void print_cmd(void) { RETURN_FUNC_NAME; }
void exit_cmd(void) { RETURN_FUNC_NAME; exit(EXIT_SUCCESS); }