/*leetcode 0867:转置矩阵*/
#include "../../utils/common.h"

int **transpose(int **matrix, int matrixSize, int *matrixColSize, int *returnSize,
                int **returnColumnSizes) {
  // m为原数组的row，n为原数组的col
  // matrixColSize这个数组里面存放的是对每一行中所有元素个数的记录，是整形，一共有n行，就一共有n个记录
  // 一般来说，矩阵矩阵每一行的元素个数是一样的，所以matrixcolsize[0]可以代矩阵的列数。
  int m = matrixSize, n = matrixColSize[0];
  // 首先为存放了每一行地址的指针所构成的指针型数组分配内存（外壳、大数组）
  int **transposed = malloc(sizeof(int *) * n);
  // 转置后的矩阵的大小——一般是以行为单位的。转置后的行是原先的列。
  *returnSize = n;
  // 类似的，用`*returnColumnSizes`这个数组来记录每一行的元素个数，即列数。其实我也想不明白为什么要这么麻烦。
  *returnColumnSizes = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    // 前面为矩阵的整个框架分配了内存，但是对于二维数组的分配内存来说，还需要为每一行，为每个整数数组分配内存，而不仅仅是指针型数组。总之，不仅仅是行指针（指针数组），
    // 还要每一行的列指针（整形数组），即要为一行分配存放m个整数的空间，一共n行，就是n*m
    transposed[i] = malloc(sizeof(int) * m);
    // 这里则记录下这一行的列数
    (*returnColumnSizes)[i] = m;
  }
  // 转置矩阵，原有矩阵的元素matrix[i][j]的位置在新矩阵的newmatrix[j][i]上。一般是从原矩阵的逻辑来遍历赋值的。
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      transposed[j][i] = matrix[i][j];
    }
  }
  return transposed;
}
