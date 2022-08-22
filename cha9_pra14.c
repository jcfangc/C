// 如果数组 a 的所有元素的值都为 0， 那么下列函数返回 true； 如果数组的所有元素都是非零的，则函数返回 false。可惜的是，此函数有错误。找出错误并说明修改它的方法。
// bool has_zero(int a[], int n)
// {
//   int i;
  
//   for (i = 0; i < n; i++)
//     if (a[i] == 0)
//       return true;
//     else
//       return false;
// }


// 参考答案：
// 根据题意，是希望数组中的所有元素都是 零 或 非零，确定后再返回结果。原代码错误在于数组历遍的过程中每一个元素都进行了判断，并返回了结果。
// 修改如下。


// bool has_zero(int a[], int n)
// {
//   int i;
//   int zero_number = 0;
  
//   for (i = 0; i < n; i++) {
//     if (a[i] == 0) {
//       ++zero_number;
//     }
//     else {
//       --zero_number;
//     }
//   }
//   // 只有 zero_number 的绝对值等于数组长度时，数组才是全零 或 全非零的。
//   if (zero_number == n) {
//     return true;
//   }
//   else if (-zero_number == n) {
//     return false;
//   }
//   else {
//     exit(EXIT_SUCCESS)
//   }
// }