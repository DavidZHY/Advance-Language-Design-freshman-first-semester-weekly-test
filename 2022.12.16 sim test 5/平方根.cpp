/*计算整数的平方根。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，包含一个整数-10000≤m≤10000。

输出
对每组数据m，计算m的平方根，精确到小数点后2位。如果m没有平方根，则输出ERROR。*/

#include <stdio.h>
#include <math.h>

int main () {
	int n;
	double num;
	float up , down;
	scanf ( "%d" , &n );
	for ( int k = 0 ; k < n ; k++ ) {
		scanf ( "%lf" , &num );
		if ( num == 0 ) {
			printf ("0.00\n");
			continue;
		}
		if ( num < 0 ) {
			printf ("ERROR\n");
			continue;
		}
		printf ( "%.2lf\n" , sqrt ( num ) );
	}
	return 0;
}
