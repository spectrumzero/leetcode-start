/*leetcode 1470:重新排列数组*/
// 要点：其实只是奇偶性的另一种表达方式。另外2i,2i+1是可以穷尽所有整数的。
#include "../utils/common.h"

int *func(int *nums, int numsize, int n) {
  int *res = (int *)malloc(sizeof(int) * numsize);
  int x = 0;
  int y = n;
  for (int i = 0; i < numsize; i++) {
    if (i % 2 == 0) {
      res[i] = nums[x++];
    } else {
      res[i] = nums[y++];
    }
  }
  return res;
}

int *demo(int *nums, int numsSize, int n, int *returnSize) {
  int *ans = (int *)malloc(sizeof(int) * n * 2);
  // 2i,2i+1 = 所有数，最初想复杂了
  for (int i = 0; i < n; i++) {
    ans[2 * i] = nums[i];
    ans[2 * i + 1] = nums[i + n];
  }
  *returnSize = n * 2;
  return ans;
}

int main() {
  int nums[] = {2, 3, 4, 1, 5, 6, 9, 11};
  int numsize = sizeof(nums) / sizeof(int);
  int n = numsize / 2;
  int *res = func(nums, numsize, n);
  printf("打印转变后的数组: [ ");
  printarray(res, numsize);
  // demo
  int returnsize = 0;
  int *arr = demo(nums, numsize, n, &returnsize);
  printf("打印转变后的数组: [ ");
  printarray(res, returnsize);
  return 0;
}
