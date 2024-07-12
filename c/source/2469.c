/*leetcode 2469:温度转换*/
/*要点：
 * 1,不能返回一个局部变量的地址（内存被释放后就不能用这个地址访问），所以需要malloc
 * 2,双精度对应的打印/读取提示符：%lf
 * 3,scanf函数利用空白字符、制表符、换行符等来确定读取的结束。
 * 4,leetcode提交只提交函数实现，不要求自己写输入输出函数。返回其需要的东西（例如size）即可。
 */
#include "./../utils/common.h"

double *transform(double *celsius) {
  double kelvin = *celsius + 273.15;
  double fahrenheit = *celsius * 1.80 + 32.00;
  double *ans = (double *)malloc(sizeof(double) * 2);
  ans[0] = kelvin;
  ans[1] = fahrenheit;
  return ans;
}

int main() {
  printf("输入：");
  double cels;
  scanf_s("%lf", &cels);
  double *res = transform(&cels);
  printf("输出：[%lf,%lf]\n", res[0], res[1]);
  printf("%lf 摄氏度：转化为开氏度为 %lf，转化为华氏度是 %lf", cels, res[0], res[1]);
  free(res);
  return 0;
}
