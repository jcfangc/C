// 用递归的方式书写gcd函数

// int gcd(int m, int n)
// {
//   int big, small;
//   big = (m > n) ? m : n;
//   small = (m < n) ? m : n;

//   if (small == 0) {
//     return big;
//   }
//   else if ((big % small) == 0) {
//     return small;
//   }
//   else {
//     int temp = small;
//     small = (big % small);
//     big = temp;
//     gcd(big, small);
//   }
// }