/*leetcode 1281:整数的各位积和之差*/
// 要点1：类似 `0258`
#include "../utils/common.h"

int func(int num) {
  int mul = 1;
  int sum = 0;
  while (num != 0) {
    mul *= num % 10;
    sum += num % 10;
    // 抛弃被使用的最后一位，进入下一个循环。直到全部使用完毕
    num = num / 10;
  }
  return mul - sum;
}

int main() { printf("%d", func(94)); }
