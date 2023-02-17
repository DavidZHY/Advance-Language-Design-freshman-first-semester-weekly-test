/*将一个三位正整数的个位，十位，百位分离开，分别依次输出

输入
第1行是一个整数n，表示随后有n组数据。
每组数据占一行，包含一个整数。

输出
如果输入的整数是三位正整数，则按照个位、十位、百位的顺序输出各位数字，中间用逗号隔开；否则输出字符串“illegal”。*/

#include <stdio.h>

int main () {
	int num , une , dix , hun , n;
	scanf ( "%d" , &n );
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &num );
		if ( num < 100 || num > 999  ) {
			printf ("illegal\n");
		} else {
			hun = num / 100;
			num %= 100;
			dix = num / 10;
			num %= 10;
			une = num;
			printf ( "%d,%d,%d\n" , une , dix , hun );
		}
	}
	return 0;
}
