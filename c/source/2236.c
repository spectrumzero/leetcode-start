/*leetcode 2236:判断根节点是否等于子节点之和*/
// 要点：对于指针所指向的地址，必须显示分配内存

#include "./../utils/common.h"

typedef struct treenode {
  struct treenode *left;
  struct treenode *right;
  int val;
} treenode;

bool checktree(struct treenode *root) {
  return root->val == root->right->val + root->left->val ? true : false;
}

treenode *newnode(int num1, int num2, int num3) {
  treenode *root = (treenode *)malloc(sizeof(treenode));
  // 对于指针所指向的地址，必须显示分配内存
  root->left = (treenode *)malloc(sizeof(treenode));
  root->right = (treenode *)malloc(sizeof(treenode));
  root->val = num1;
  root->left->val = num2;
  root->right->val = num3;
  return root;
}

int main() {
  treenode *r = newnode(7, 2, 1);
  if (checktree(r)) {
    printf("根节点等于两个子节点值之和\n");
  } else {
    printf("根节点不等于两个子节点值之和\n");
  }
  return 0;
}
