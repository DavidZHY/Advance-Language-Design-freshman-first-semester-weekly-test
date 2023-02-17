/*将4个整数从小到大排序，然后依次输出。
要求：不能使用循环语句。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，包含4个整数，用空格隔开。

输出
对每组数据输出从小到大排序后的结果，整数之间用1个空格隔开。*/

#include <stdio.h>

int main() {
    int n, i;
    int a, b, c, d;
    int aa = 0 , bb  = 0 , cc = 0 , dd = 0;
    scanf("%d", &n);  // 有n组数据
    for (i = 0; i < n; i++) {
    	aa = 0;
    	bb = 0;
    	cc = 0;
    	dd = 0;
        scanf ( "%d%d%d%d" , &a , &b , &c , &d );
        //1st
        if ( a >= b && a >= c && a >= d ) {
        	aa = a;
        	a = 0;
        } else if ( b >= a && b >= c && b >= d ) {
        	aa = b;
        	b = 0;
        } else if ( c >= b && c >= a && c >= d ) {
        	aa = c;
        	c = 0;
        } else if ( d >= b && d >= c && d >= a ) {
        	aa = d;
        	d = 0;
        }
        //2nd
        if ( a >= b && a >= c && a >= d ) {
        	bb = a;
        	a = 0;
        } else if ( b >= a && b >= c && b >= d ) {
        	bb = b;
        	b = 0;
        } else if ( c >= b && c >= a && c >= d ) {
        	bb = c;
        	c = 0;
        } else if ( d >= b && d >= c && d >= a ) {
        	bb = d;
        	d = 0;
        }
        //3rd
        if ( a >= b && a >= c && a >= d ) {
        	cc = a;
        	a = 0;
        } else if ( b >= a && b >= c && b >= d ) {
        	cc = b;
        	b = 0;
        } else if ( c >= b && c >= a && c >= d ) {
        	cc = c;
        	c = 0;
        } else if ( d >= b && d >= c && d >= a ) {
        	cc = d;
        	d = 0;
        }
        //4th
        if ( a >= b && a >= c && a >= d ) {
        	dd = a;
        	a = 0;
        } else if ( b >= a && b >= c && b >= d ) {
        	dd = b;
        	b = 0;
        } else if ( c >= b && c >= a && c >= d ) {
        	dd = c;
        	c = 0;
        } else if ( d >= b && d >= c && d >= a ) {
        	dd = d;
        	d = 0;
        }
        printf ( "%d %d %d %d\n" , dd , cc , bb , aa );
    }
    

    return 0;
}
