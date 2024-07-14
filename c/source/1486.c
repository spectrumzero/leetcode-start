/*leetcode 1486:数组异或操作*/
// 要点：对异或的理解。
// 异或hash,exclusive or:
//
// A | B | A XOR B
//---------------
// 0 | 0 |   0
// 0 | 1 |   1
// 1 | 0 |   1
// 1 | 1 |   0
//
// 相应位上的两个值不同时，结果为1；相同时，结果为0
// a^b的结果，就是将a和b这两个十进制（也可以是别的进制）数，转换成二进制，然后做比较，最终得出十进制的结果。
// x^0 = x
// x^x = 0
// x^y = y^x
// (x^y)^z = x^(y^z)
// x^y^y = x
// ∀ x ∈ Z，有4x^(4x+1)^(4x+2)^(4x+3) = 0
#include "../utils/common.h"

int xoroperation(int n, int start) {
  // 数组一般是静态数组，即数组的长度也应该是常量表达式。malloc用以动态数组的创建。
  int *nums = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    nums[i] = start + 2 * i;
  }
  int res = nums[0];
  if (n == 1) {
    printf("数组nums 为[%d],按位异或运算后得到的结果为%d", res, res);
    return res;
  }
  printf("数组nums 为[ ");
  for (int i = 0; i < n - 1; i++) {
    printf("%d,", nums[i]);
  }
  for (int i = 1; i < n; i++) {
    res ^= nums[i];
  }
  printf("%d ],按位异或运算后得到的结果为 %d", nums[n - 1], res);
  return res;
}

int main() {
  xoroperation(8, 3);
  return 0;
}
