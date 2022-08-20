#include <stdio.h>
#include <ctype.h>

int main()
{
    int input_hour, input_minute, time, picked_min, pickedtime, picked_hour, picked_landingmin, pickedlandingtime, picked_landinghour;
    char ap_judge1, ap_judge2;

    // 分别用用分钟记录时间，自午夜12点开始
    int takeofftime[8] = { 8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45 };
    int landingtime[8] = { 10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60, 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58 };

    // 录入时间 12 小时制
    printf("\n\t Enter your time: (xx:xx am/pm)");
    scanf("%d:%d", &input_hour, &input_minute);
    // 吃掉多余的回车符
    getchar();

    // 用这两个参数来了解用户输入的是 am 还是 pm
    ap_judge1 = getchar();
    // judge2 是为了防止用户根据书写习惯在时间和 ampm 中间加入了空格的备用
    ap_judge2 = getchar();

    // 根据 ap_judge1 或 2 的内容来判断是否需要增加 12 个小时计时
    if ((toupper(ap_judge1) == 'A' || (toupper(ap_judge2)) == 'A')) {
        time = input_hour * 60 + input_minute;
    }
    else if ((toupper(ap_judge1) == 'P' || (toupper(ap_judge2)) == 'P')) {
        time = (input_hour + 12) * 60 + input_minute;
    }
    else {
        time = input_hour * 60 + input_minute;
    }

    // 当计算出来的 24时制 的时间超过最晚的航班 就打印这条信息
    if (time > (21 * 60 + 45)) {
        printf("\n\t Please go and take the flights tomorrow. ");
        getchar();
        printf("\n\n");
        return 0;
    }

    // 计算结果和时间表上的时间作比较，遍历每一个起飞时间，直到找到合适的时间
    for (int i = 7; i >= 0; i--) {
        if (time >= takeofftime[i]) {
            pickedtime = takeofftime[i + 1];
            pickedlandingtime = landingtime[i + 1];
            break;
        }
    }

    // 在找到适当的起飞降落时间之后，转换成 24h制
    picked_min = pickedtime % 60;
    picked_hour = (pickedtime - picked_min) / 60;
    picked_landingmin = pickedlandingtime % 60;
    picked_landinghour = (pickedlandingtime - picked_landingmin) / 60;

    // 输出结果
    printf("\n\t Your fittable flight is taking off at %d:%2.2d ", picked_hour, picked_min);
    printf("\n\t It will land at %d:%2.2d ", picked_landinghour, picked_landingmin);

    getchar();
    printf("\n\n");
    return 0;
}