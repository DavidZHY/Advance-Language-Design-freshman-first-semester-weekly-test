/*��4��������С��������Ȼ�����������
Ҫ�󣺲���ʹ��ѭ����䡣

����
��1����һ������n����ʾ�����n�����ݡ�ÿ������ռһ�У�����4���������ÿո������

���
��ÿ�����������С���������Ľ��������֮����1���ո������*/

#include <stdio.h>

int main() {
    int n, i;
    int a, b, c, d;
    int aa = 0 , bb  = 0 , cc = 0 , dd = 0;
    scanf("%d", &n);  // ��n������
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
