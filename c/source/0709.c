/*leetcode 709:转换成小写字母*/
// 要点1: 按位或运算：两个操作数对应的位有任何一个是1，则结果是1；否则是0。
// a = 5;    // 5的二进制表示是 00000101
// b = 3;    // 3的二进制表示是 00000011
// a |= b;   // 结果是          00000111（十进制 7）
//
// 要点2: 大写字母和小写字母之间的关系：
// 在ascii码表中，大写字母和小写字母的二进制数表示的区别在于第五位（从右往左数）。对于这个区间范围的数，调整第五位为0或1(加32，或减32)即可完成转换。
// (A)65 (01000001) | 32 (00100000) = (a)97 (01100001)
//
// 要点3：字符型变量：
// 在c语言中，字符实际上是以整数的形式——即ascii码的形式来存储的。由于ASCII码是标准化的整数值，因此可以直接在代码中使用这些整数来表示字符
#include "../utils/common.h"

char *uppertolower(char *s) {
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (s[i] >= 65 && s[i] <= 90) {
      // `按位或`运算:
      s[i] |= 32;
      // 也可以直接用到c标准库中的函数
      // s[i] = tolower(s[i]);
    }
  }
  return s;
}

char *lowertoupper(char *s) {
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (s[i] >= 97 && s[i] <= 122) {
      // 反过来，则是用到按位异或运算
      s[i] ^= 32;
      // 也可以直接用到c标准库中的函数
      // s[i] = toupper(s[i]);
    }
  }
  return s;
}

int main() {
  char *a = "hello WorLd FLDfjfjlajJLFJAl";
  printf("初始：%s\n", a);
  uppertolower(a);
  printf("小写：%s\n", a);
  lowertoupper(a);
  printf("大写：%s", a);
}
