/*leetcode 0326:3的幂*/
// 要点1：0231
// 其实直接枚举也好，因式运算
#include "../utils/common.h"

bool func(int n) {
  if (n <= 0) {
    return false;
  }
  while (n > 1) {
    if (n % 3 != 0) {
      return false;
    }
    n = n / 3;
  }
  return true;
}

bool func2(int n) { return n > 0 && 1162261467 % n == 0; }

int main() { printf("%d", func2(81)); }
