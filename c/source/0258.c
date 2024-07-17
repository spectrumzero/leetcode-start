/*leetcode 0258:各位相加(数根)*/
// 要点1：取余运算：a%b=a-b(trunc(a/b))
//
// 要点2：对于任意正整数a，其数根b等于该数除以9的余数。即满足a ≡ b(mod
// 9)(读作a和b同余于9)。这一公式还可等价于a-b=km。有两种特殊情况：一是0的数根为0；二是若a为9的倍数，则其数根为9
//
// 要点3：在不知道一个数的位数的前提下，拆开一个数

#include "../utils/common.h"
#include <stdio.h>

int func(int n) {
  // 商
  int a = n / 10;
  // 余数
  int b = n % 10;
  int res = b;
  while (1) {
    if (res >= 0 && res <= 9 && a == 0) {
      return res;
    } else if (res >= 10 && a == 0) {
      a = res;
      res = 0;
    }
    // 更新余数
    b = a % 10;
    // 更新商
    a = a / 10;
    res += b;
  }
}

// 更简洁的表达
int demo1(int num) {
  int sum = 0;
  while (num >= 10) {
    sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    num = sum;
  }
  return num;
}

// 数学解法
int demo2(int num) {
  // c语言中，对于任意整数，a%b=a-b(trunc(a/b))
  return (num - 1 % 9) + 1;
}

// 更直观的写法
int demo3(int num) {
  if (num == 0) {
    return num;
  }
  return num % 9 == 0 ? 9 : num % 9;
}

int main() {
  printf("125672 各位相加，最后的个位数结果为：%d\n", func(125672));
  printf("81各位相加，最后的个位数结果为：%d\n", demo3(81));
  return 0;
}
