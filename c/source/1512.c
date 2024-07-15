/*leetcode 1512:好数对的数目*/
// 方法：暴力枚举
// 更好的解：组合计数？
#include "../utils/common.h"

int func(int *nums, int numssize) {
  int res = 0;
  for (int i = 0; i < numssize; i++) {
    for (int j = i + 1; j < numssize; j++) {
      if (nums[i] == nums[j])
        res++;
    }
  }
  return res;
}

int main() {
  int nums[] = {1, 2, 3};
  int size = sizeof(nums) / sizeof(int);
  int res = func(nums, size);
  printf("%d", res);
}
