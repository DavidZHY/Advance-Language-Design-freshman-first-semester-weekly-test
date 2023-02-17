/*计算n的阶乘末尾0的个数。

输入
第1行是一个整数N，表示随后有N组数据。每组数据占一行，包含一个整数，用空格隔开。

输出
对每组数据输出n的阶乘末尾0的个数，并换行。*/

#include <stdio.h>

int main () {
	int n , i = 0;
	long result;
	long dig , num;
	long decide = 0;
	long k;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
    	dig = 0;
    	k = 1;
    	decide = 0;
    	scanf ( "%ld" , &num );
    	do {
    		k *= 5;
    		decide = num / k;
    		dig += num / k;
    	} while ( decide != 0 );
    	printf ( "%ld\n" , dig );
    }
	return 0;
}
