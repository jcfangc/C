// 编写程序用来要求用户录入国际电话区号，然后在数组 country_codes 中查找它（见 16,3 节）。如果找到对应的区号，程序需要显示相应的国家名称，否则显示出错信息。
#include <stdio.h>

typedef enum bool{ FALSE, TRUE } bool;

typedef struct dialing_code {
    char *country;
    int code;
} dialing_code;

const struct dialing_code country_codes[] = {
    { "Argentina",              54 },   { "Bangladesh",             880 },
    { "Brazil",                 55 },   { "Burma(Myanmar)",         95 },
    { "China",                  86 },   { "Colombia",               57 },
    { "Congo, Dem, Rep. of",    243 },  { "Egypt",                  20 },
    { "Ethiopia",               251 },  { "France",                 33 },
    { "Germany",                49 },   { "India",                  91 },
    { "Indonesia",              62 },   { "Iran",                   98 },
    { "Italy",                  39 },   { "Japan",                  81 },
    { "Mexico",                 52 },   { "Nigeria",                234 },
    { "Pakistan",               92 },   { "Philippines",            63 },
    { "Poland",                 48 },   { "Russia",                 7 },
    { "South Africa",           27 },   { "Korea",                  82 },
    { "Spain",                  34 },   { "Sudan",                  249 },
    { "Thailand",               66 },   { "Turkey",                 90 },
    { "Ukraine",                380 },  { "United Kingdom",         44 } ,
    { "United States",          1 },    { "Vietnam",                84 }
};

bool is_dialing_code(int);

int main(void)
{
    int d_code;
    for (;;) {
        printf("\n\t----------------------------\
            \n\t DIALING CODES:\
            \n\t 54\t880\t55\t95\
            \n\t 86\t57\t243\t20\
            \n\t 251\t33\t49\t91\
            \n\t 62\t98\t39\t81\
            \n\t 52\t234\t92\t63\
            \n\t 48\t7\t27\t82\
            \n\t 34\t249\t66\t90\
            \n\t 380\t44\t1\t84\
            \n\t----------------------------");
        printf("\n\n\t Enter a dialing code: (0 to end) ");
        scanf(" %d", &d_code);
        getchar();

        if (d_code == 0) { return 0; }

        if (!is_dialing_code(d_code)) {
            printf("\t Invalid dialing code! \n");
        }
    }
}

bool is_dialing_code(int d_code)
{
    // 计算数组长度
    int len = (int)(sizeof(country_codes) / sizeof(dialing_code));

    // 遍历数组寻找匹配
    for (int i = 0; i < len; i++) {
        if (country_codes[i].code == d_code) {
            printf("\t %s\n", country_codes[i].country);
            return TRUE;
        }
    }

    // 无匹配
    return FALSE;
}

// 书作者答案：http://knking.com/books/c2/answers/c16.html