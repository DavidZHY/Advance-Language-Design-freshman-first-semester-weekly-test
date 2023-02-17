/*计算两个整数的和

第1行是一个整数n，表示随后有n组数据。每组数据占一行，包含两个整数，用空格隔开。

输出
对每组数据输出两个整数的和，并换行。*/

#include <stdio.h>

int main() {
    int n, i, a, b;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", a + b);
    }
    return 0;
}
