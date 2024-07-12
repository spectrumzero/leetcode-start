/*leetcode 2235:两整数相加*/
#include "../utils/common.h"

int sum(int num1, int num2) { return num1 + num2; }

int main() {
  printf("请输入要相加的两个数字:\n");
  int num1, num2;
  scanf_s("%d,%d", &num1, &num2);
  int s = sum(num1, num2);
  printf("两数相加之和为：%d", s);

  return 0;
}
