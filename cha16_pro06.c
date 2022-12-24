// �޸ĵ� 5 �±���� 9���Ա��û��������ڶ��洢��һ�� date �ṹ������ϰ�� 5���С�����ϰ�� 5 �е� compare_dates �������ɵ���ĳ����С�

// �� 5 �±���� 9:
// ��дһ��������ʾ�û�������������ڣ�Ȼ����ʾ��һ�����ڸ��硣

#include <stdio.h>

#define LARGER 1
#define SMALLER -1
#define EQUAL 0
#define MONTHS 12

typedef struct date {
    int year;
    int month;
    int day;
} date;

int day_of_year(struct date);
int compare_dates(struct date, struct date);

int main(void)
{
    date d1, d2;

    printf("\n\t Enter first date: (dd/mm/yy) \n\t ");
    scanf(" %d/%d/%d", &d1.day, &d1.month, &d1.year);
    getchar();
    printf("\n\t Enter second date: (dd/mm/yy) \n\t ");
    scanf(" %d/%d/%d", &d2.day, &d2.month, &d2.year);
    getchar();

    if (compare_dates(d1, d2) == SMALLER) {
        printf("\n\t %.2d/%.2d/%d is earlier than %.2d/%.2d/%d.", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    }
    else if (compare_dates(d1, d2) == LARGER) {
        printf("\n\t %.2d/%.2d/%d is earlier than %.2d/%.2d/%d.", d2.day, d2.month, d2.year, d1.day, d1.month, d1.year);
    }
    else if (compare_dates(d1, d2) == EQUAL) {
        printf("\n\t Same day. ");
    }

    getchar();
    return 0;
}

int day_of_year(struct date d)
{
    const int day_of_month[MONTHS] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    const int *month = day_of_month;
    int result = 0;

    /* ��ȫ�������·ݣ����ӵ������� */
    for (; month < day_of_month + d.month - 1; month++) {
        result += (*month);
    }

    /* δ��ȫ�������·ݣ����¾����˵����� */
    return (result + d.day);
}

int compare_dates(struct date d1, struct date d2)
{
    /* �Ƚ���� */
    if (d1.year > d2.year) {
        return LARGER;
    }
    else if (d1.year < d2.year) {
        return SMALLER;
    }
    else {
        /* ͬ��Ƚ������Ⱥ� */
        if (day_of_year(d1) > day_of_year(d2)) {
            return LARGER;
        }
        else if (day_of_year(d1) < day_of_year(d2)) {
            return SMALLER;
        }
        else {
            return EQUAL;
        }
    }
}