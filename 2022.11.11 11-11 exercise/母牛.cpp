/*有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？

输入格式
输入一个整数n(0<n<55)。

输出格式
输出第n年母牛的数量，占一行。*/

#include <stdio.h>

int main () {
	int une , deu , tro;
	une = 0;
	deu = 0;
	tro = 0;
	int adu = 1;
	int year;
	int temp = 0;
	scanf ( "%d" , &year );
	for ( int i = 0 ; i < year - 1 ; i++ ) {
		adu += tro;
		temp = adu;
		tro = deu;
		deu = une;
		une = temp;
	}
	printf ( "%d" , une + deu + tro + adu );
	return 0;
}
