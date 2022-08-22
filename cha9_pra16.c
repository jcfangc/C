// 请采用精简 power 函数的方法来简化 fact 函数。

// int fact(int n) 
// {
//   if (n <= 1) {
//     return 1;
//   }
//   else {
//     return n * fact(n - 1);
//   }
// }

// 书本 9.6 （递归）中提到：通过把条件表达式放入 return 语句中的方法可以精简 power 函数。

// 参考答案如下：

// int fact(int n)
// {
//   return (n <= 1) ? 1 : (n * fact(n - 1));
// }