/*leetcode 0263:丑数*/
// 要点1：解法归根还是和231,326差不多的。但这里的demo还是很值得一看，应该是可以得到更普遍运用的思路。
#include "../utils/common.h"

bool func(int n) {
  while (n >= 1) {
    if (n == 1) {
      return true;
    } else if (n % 2 == 0) {
      n = n / 2;
      // 利用continue语句，跳过当前循环的剩余部分，并直接进入下一次的循环
      continue;
    } else if (n % 3 == 0) {
      n = n / 3;
      continue;
    } else if (n % 5 == 0) {
      n = n / 5;
      continue;
    }
    return false;
  }

  return false;
}

bool demo(int n) {
  if (n < 0)
    return false;
  // 这个数组弄得蛮巧妙的
  int factor[] = {2, 3, 5};
  for (int i = 0; i < 3; i++) {
    // 放在一个while循环里，一直除以2，除不动了就换3，换5。如果一直除得动，那么n最后一定是1，n为丑数
    while (n % factor[i] == 0)
      n = n / factor[i];
  }
  // 如果n不等于1，就不是丑数
  return n == 1;
}

int main() {
  printf("%d\n", func(1));
  printf("%d\n", demo(360));
}
