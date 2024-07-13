/*leetcode 2413:最小偶倍数*/
// 要点1：取余
// 要点2：三目运算符
#include "./../utils/common.h"

int smallestevenmultiple(int n) { return n % 2 ? (n * 2) : n; }

int main() {
  printf("输入：");
  int n;
  scanf_s("%d", &n);
  int res = smallestevenmultiple(n);
  printf("输出：%d", res);
  return 0;
}
