/*leetcode 1534:统计好三元组*/
// 还是很暴力。
#include "../utils/common.h"

int func(int *arr, int size, int a, int b, int c) {
  int res = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      for (int k = j + 1; k < size; k++)
        // abs 函数
        if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
          res++;
    }
  }
  return res;
}

int main() {
  int nums[] = {1, 1, 2, 2, 3};
  int size = sizeof(nums) / sizeof(int);
  int res = func(nums, size, 0, 0, 1);
  printf("%d", res);
}
