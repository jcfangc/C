// 根据字母评价算出GPA
#include <stdio.h>
#include <ctype.h>

float compute_GPA(char[], int);

int main(void)
{
  char ch;
  char grades[10] = { '\0' };

  printf("\n\t Input your 10 grades: ");

  int index = 0;
  // while 惯用法，再遇见换行符之前持续录入字符，遇到分隔作用的符号跳过
  while ((ch = getchar()) != '\n') {
    if (ch == ' ' || ch == ',') {
      continue;
    }
    grades[index++] = toupper(ch);
  }

  printf("\n\t GPA: %.2f ", compute_GPA(grades, 10));

  getchar();
  printf("\n\n");
  return 0;
}

float compute_GPA(char grade[], int length)
{
  int value = 0;
  
  // 等级所在的行数恰好可以用作分数计算
  char grade_value[6] = { 'F','D','C','B','A' };
  // 防止字符数组末端出现 ‘\0’，数组声明的元素数最好 +1 
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < 5; j++) {
      if (grade[i] == grade_value[j]) {
        value += j;
      }
    }
  }

  // 强制转换变量类型
  return ((float)value / (float)length);
}