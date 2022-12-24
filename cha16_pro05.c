// �޸ĵ� 5 �µı���� 8���Ա���һ������������洢ʱ�䣬�����Ԫ�ض��ǽṹ��ÿ���ṹ�������ʱ��Ͷ�Ӧ�ĵִ�ʱ�䡣��ʱ�䶼����������ʾ����ҹ��ʼ�ķ���������������һ��ѭ�����������������û�����ʱ����ӽ������ʱ�䡣

// �� 5 �±���� 8��
// ��дһ������Ҫ���û�����һ��ʱ�䣨�� 24 Сʱ�Ƶ�ʱ�ֱ�ʾ��������ѡ�����ʱ�����û�����ʱ����ӽ��ĺ��࣬��ʾ����Ӧ�����ʱ��͵ִ�ʱ�䡣

#include <stdio.h>

#define MIN_HOUR 60
#define FLIGHT_MAX 8

typedef struct depart_arrive {
    int depart_time;
    int arrive_time;
} depart_arive;

const depart_arive schadule[] = {
    {8 * MIN_HOUR + 0,      10 * MIN_HOUR + 16},
    {9 * MIN_HOUR + 43,     11 * MIN_HOUR + 52},
    {11 * MIN_HOUR + 19,    13 * MIN_HOUR + 31},
    {12 * MIN_HOUR + 47,    15 * MIN_HOUR + 0},
    {14 * MIN_HOUR + 0,     16 * MIN_HOUR + 8},
    {15 * MIN_HOUR + 45,    17 * MIN_HOUR + 55},
    {19 * MIN_HOUR + 0,     21 * MIN_HOUR + 20},
    {21 * MIN_HOUR + 45,    23 * MIN_HOUR + 58}
};
int result_depart_hour, result_depart_min, result_arrive_hour, result_arrive_min;

void give_result(depart_arive the_flight);

int main(void)
{
    // ��ȡʱ��
    int hour, min;
    printf("\n\t Enter you planning departure time (24-hour form hh:mm): \n\t ");
    scanf(" %d:%d", &hour, &min);
    getchar();
    const int time_planned = hour * MIN_HOUR + min;

    // �ҵ��ٽ�����
    int before_gap, after_gap;
    // �������
    // �������纽��
    if (time_planned < schadule[0].depart_time) {
        give_result(schadule[0]);
    }
    // ����������
    else if (time_planned > schadule[7].depart_time) {
        give_result(schadule[7]);
    }
    // ��������
    else {
        for (int i = 1; i < FLIGHT_MAX - 1; i++) {
            // �ҵ���һ���ȼƻ�ʱ�����ʱ��
            if (schadule[i].depart_time >= time_planned) {
                // �ƻ�ʱ��֮��ĺ�������ʱ��
                after_gap = schadule[i].depart_time - time_planned;
                // �ƻ�ʱ��֮ǰ�ĺ�������ʱ��
                before_gap = time_planned - schadule[i - 1].depart_time;
                // ѡȡ����ƻ�ʱ������ĺ���
                after_gap <= before_gap ? give_result(schadule[i]) : give_result(schadule[i - 1]);
                break;
            }
        }
    }

    printf("\n\t Adjacent flight: from %d:%.2d to %d:%.2d.", result_depart_hour, result_depart_min, result_arrive_hour, result_arrive_min);

    getchar();
    return 0;
}

void give_result(depart_arive the_flight)
{
    result_depart_hour = the_flight.depart_time / MIN_HOUR;
    result_depart_min = the_flight.depart_time % MIN_HOUR;
    result_arrive_hour = the_flight.arrive_time / MIN_HOUR;
    result_arrive_min = the_flight.arrive_time % MIN_HOUR;
}