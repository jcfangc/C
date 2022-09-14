// 下列计算三角形面积的函数有两处错误，找出这些错误，并且说明修改他们的方法。（提示：公式中没有错误）

double triangle_area(double base, height)
double product;
{
  product = base * height;
  return product / 2;
}


// 参考答案：

double triangle_area(double base, double height)
{
  double product;
  product = base * height;
  return product / 2;
}