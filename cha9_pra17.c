// 请重新编写 fact 函数，使得编写后的函数不再有递归。

// int fact(int n) 
// {
//   if (n <= 1) {
//     return 1;
//   }
//   else {
//     return n * fact(n - 1);
//   }
// }

// 参考答案：

// int fact(int n)
// {
//   int product = 1;

//   for (; n >= 1; n--) {
//     product *= n;
//   }

//   return product;
// }