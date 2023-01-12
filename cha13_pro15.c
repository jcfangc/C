// �޸ĵ� 10 �µı���� 6��ʹ��������º�����
// int evaluate_RPN_expression(const char *expression);
// �������� expression ָ����� RPN ���ʽ��ֵ��

// �� 10 �µı���� 6��
// ��Щ�������������ǻ��յļ�������ʹ���沨����ʾ�� (Reverse Polish Notation, RPN������д��ѧ���ʽ������һ��ʾ���У�����������ڲ������ĺ�������Ƿ��ڲ������м䡣���磬���沨����ʾ���� 1 + 2 ����ʾΪ 1 2 +���� 1 + 2 * 3 ����ʾΪ 1 2 3 * +���沨�����ʽ���Ժܷ������ջ��ֵ���㷨�������Ҷ�ȡ������Ͳ���������ִ�����в��衣
// ��1��������������ʱ������ѹ��ջ�С�
// ��2�������������ʱ����ջ�е������Ĳ�������ִ�����㲢�ѽ��ѹ��ջ�С�
// ��д������沨�����ʽ��ֵ�����������Ǹ�λ�������������Ϊ +��-��*��/ �� =����������� = ʱ������ʾջ���������ջ����ʾ�û������µı��ʽ����һ���̳������У�ֱ���û�����һ���Ȳ��������Ҳ���ǲ��������ַ�Ϊֹ��

// Enter an RPN expression: 1 2 3 * + =
// Value of expression: 7
// Enter an RPN expression: 5 8 * 4 9 - / =
// Value of expression: -8
// Enter an RPN expression : q

// ���ջ�������磬������ʾ��Ϣ Expression is too complex ����ֹ�����ջ�������磨������ʽ 1 2 + +����������ʾ��Ϣ Not enough operands in expression ����ֹ 10.2 �ڵ�ջ�������ϵ���ĳ����С�ʹ�� scanf(" %c", &ch) ��ȡ������Ͳ�������


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
        //  ���ʽ��Ϣ���ࣨ������ / �ָ��� / �����ࣩ
        _Bool num = OFF, opr = OFF, blk = OFF;
        // �����ࣺ
        //  ʶ�𵽲�����
        //  ����ջ������������
        //  ����ֵѹ��ջ��
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
            // ��������Ϣ������˵����λ���ַ��Ѿ���ʶ��
            opr = OFF;
            continue;
        }

        // �ָ��ࣺ
        // �Թ���ǰ�ķָ������������Ƶ���һ�����������������Ϣȥ
        if ((*ptr) == ' ') {
            blk = ON;
            ptr++;
        }
        if (blk) {
            // �ָ�������Ϣ������˵����λ���ַ��Ѿ���ʶ��
            blk = OFF;
            continue;
        }

        // �����ࣺ
        //  ʶ����ת����
        //  ʶ�𵽵���ѹ��ջ��
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
            // ��������Ϣ������˵����λ���ַ��Ѿ���ʶ��
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