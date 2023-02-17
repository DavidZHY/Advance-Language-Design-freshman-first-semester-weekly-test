/*有n个整数，计算它们的平均值。

输入
每个输入包含一个测试用例，第1行输入n (1≤n≤100)；第2行输入n个整数，之间用空格分隔。

输出
平均值，保留小数点后两位。*/

#include <stdio.h>

int main () {
	int n;
	int temp;
	float avg = 0;
	scanf ( "%d" , &n );
	for ( int k = 0 ; k < n ; k++ ) {
		scanf ( "%d" , &temp );
		avg += temp;
	}
	avg /= n;
	printf ( "%.2f" , avg );
	return 0;
}
