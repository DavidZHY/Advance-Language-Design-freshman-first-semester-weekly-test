/*求1+2+…+n（0<=n<=100）的和。

输入
第1行输入一个整数n，表示从1加到n。

输出
用三种控制语句(for,while,do...while)计算1+2+…+n的和，每种控制语句计算结果占一行。*/

#include <stdio.h>

int main() {
    int n, i = 1, result = 0;
    scanf("%d", &n);
    for ( i = 1 ; i <= n ; i++ ) {
    	result += i;
    }
    printf ("%d\n" , result);
    result = 0;
    i = 1;
    while ( i <= n ) {
    	result += i;
    	i++;
    }
    printf ("%d\n" , result);
    result = 0;
    i = 1;
    do {
    	result += i;
    	i++;
    } while ( i <= n );
    printf ("%d\n" , result);
    return 0;
}
