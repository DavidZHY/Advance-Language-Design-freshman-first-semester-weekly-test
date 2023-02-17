/*求一组数据中绝对值最大的数输出。

输入
每行输入包含一个测试用例，第一个整数m(1<=m<=20)，表示随后有m个整数(能够用32位整数表示)，各数之间用空格分隔。

输出
每组输出占一行，输出绝对值最大的数。(不考虑最大值对应多个输入的情况)*/

#include <stdio.h>

int main () {
	int n;
	long long a;
	long long max = 0;
	int no , maxno;
	scanf ( "%d" , &n );
	for ( int i = 0 ; i < n ; i++ ) {
		no = 1;
		scanf ( "%lld" , &a );
		if ( a < 0 ) {
			a *= -1;
			no = -1;
		}
		if ( a > max ) {
			max = a;
			maxno = no;
		}
	} 
	printf ( "%lld" , max * maxno );
	return 0;
}
