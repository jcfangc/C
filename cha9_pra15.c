// 下面这个（相当混乱的）函数找出三个数的中间数。重新编写函数，使得它只有一条 return 语句。
// double median(double x, double y, double z)
// {
//   if (x <= y)
//     if (y <= z) return y;
//     else if (x <= z) return z;
//     else return x;
//   if (z <= y) return y;
//   if (x <= z) return x;
//   return z;
// }



// 完成这道题，可以先简单梳理一下原题中的程序：
// double median(double x, double y, double z)
// {
//   if (x <= y) {
//     if (y <= z) { // x <= y <= z
//       return y;
//     }
//     else if (x <= z) { // 可以运行到这里说明上面的 (y <= z) 条件是假值，即 z < y。
//       return z;
//     }
//     else { // 排除法，三个数中另外两个都不是中间数。
//       return x;
//     }
//   }
//   if (z <= y) { 
//     // 程序运行至此，这能说明一开始的条件 (x <= y) 不成立。即， x > y。
//     return y; 
//   }
//   if (x <= z) { // 同理，此时 (z <= y) 和 (x <= y) 都不成立。即 z > y，x > y。中间数只可能是 x 或 z。
//     return x;
//   }
//   return z; // 排除法，三个数中另外两个都不是中间数。
// }


// 参考答案：


// double median(double x, double y, double z)
// {
//   double mid;
//   if ((x <= y) && (y <= z)) {
//     mid = y;
//   }
//   else if ((z <= y) && (y <= x)) {
//     mid = y;
//   }
//   else if ((z <= x) && (x <= y)) {
//     mid = x;
//   }
//   else if ((y <= x) && (x <= z)) {
//     mid = x;
//   }
//   else if ((x <= z) && (z <= y)) {
//     mid = z;
//   }
//   else if ((y <= z) && (z <= x)) {
//     mid = z;
//   }

//   return mid;
// }


// 相较于参考答案，原题中的程序有一个明显的优点，就是避免了重复比较。而参考答案虽然完成了题目要求，也更加一目了然，但是却需要重复比较。


// double median(double x, double y, double z)
// {
//   double median;
//   if (x <= y) {
//     if (y <= z) { // x <= y <= z
//       median = y;
//     }
//     else if (x <= z) { // 可以运行到这里说明上面的 (y <= z) 条件是假值，即 z < y。
//       median = z;
//     }
//     else { // 排除法，三个数中另外两个都不是中间数。
//       median = x;
//     }
//   }
//   if ((x > y) && (z <= y)) {
//     // 程序运行至此，这能说明一开始的条件 (x <= y) 不成立。即， x > y。
//     median = y;
//   }
//   if ((z > y) && (x > y) && (x <= z)) { // 同理，此时 (z <= y) 和 (x <= y) 都不成立。即 z > y，x > y。中间数只可能是 x 或 z。
//     median = x;
//   }
//   else if ((z > y) && (x > y) && (x > z)) {
//     median = z; // 排除法，三个数中另外两个都不是中间数。
//   }

//   return median;
// }


// 上面这一段函数在没有大幅度更改原有函数的基础上依旧满足题意

// 测试部分，可以随意更换以上两种函数进行测试
#include <stdio.h>

double median(double, double, double);

int main(void)
{
  double x, y, z;

  // 需要注意的是 float 和 double 在内存中存储数据的方式是不同的 float - %f 和 double - %lf 的搭配不可交换
  printf("\n\t Input a numbers: ");
  scanf("%lf", &x);
  getchar();
  printf("\n\t Input a numbers: ");
  scanf("%lf", &y);
  getchar();
  printf("\n\t Input a numbers: ");
  scanf("%lf", &z);
  getchar();

  printf("\n\t %lf", median(x, y, z));

  getchar();
  printf("\n\n");
  return 0;
}

double median(double x, double y, double z)
{
  double median;
  if (x <= y) {
    if (y <= z) { // x <= y <= z
      median = y;
    }
    else if (x <= z) { // 可以运行到这里说明上面的 (y <= z) 条件是假值，即 z < y。
      median = z;
    }
    else { // 排除法，三个数中另外两个都不是中间数。
      median = x;
    }
  }
  if ((x > y) && (z <= y)) {
    // 程序运行至此，这能说明一开始的条件 (x <= y) 不成立。即， x > y。
    median = y;
  }
  if ((z > y) && (x > y) && (x <= z)) { // 同理，此时 (z <= y) 和 (x <= y) 都不成立。即 z > y，x > y。中间数只可能是 x 或 z。
    median = x;
  }
  else if ((z > y) && (x > y) && (x > z)) {
    median = z; // 排除法，三个数中另外两个都不是中间数。
  }

  return median;
}