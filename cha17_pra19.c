// ���дһ��������Ҫ���ڸ����ַ�����Ϊʵ�ʲ���ʱ���˺�������������ʾ�Ľṹ����Ѱ��ƥ�����������Ȼ����ú�ƥ��������صĺ�����
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
    // �ڳ�ʼ����ʱ���������һ�������������ȶ�����һЩ����ָ�룬�� cmd_pointer ������ͬ��ָ�룬������Щָ���к������ʼ��ʽ�к� cmd_pointer ��صĲ�����ͬ�����֡�������Щָ��ָ���˸��Եĺ�����
    // �����Ǵ�������
    // void(*new_cmd)(void) = new����������;
    // ���������յ���ʼ��ʽ��Ҫ�������ʽ�ľ��棬�������Ǿ�Ӧ�÷�˼ָ��ĳ�����ʲô��
    // �𰸾����ڴ��ַ�������������ÿ�����Ϊ�ڴ��ַ��
    // ������ȷ�����������ڳ�ʼ��ʽ��д����Ϻ���ָ�����͵ĺ��������ɡ�
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
        // ��������
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

        // ִ������
        do_command(command);
    }
}

void do_command(const char *str)
{
    // ƥ������������ı�
    for (int i = 0; i < (int)(sizeof(file_cmd) / sizeof(file_cmd[0])); i++) {
        if (strcmp(str, file_cmd[i].cmd_name) == 0) {
            // ����Ҫ��һ���ǲ����������� ()�����Ǻ�������Ҫ��־���ͺñ� getchar �� getchar()���ǽ�Ȼ��ͬ�ġ�
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