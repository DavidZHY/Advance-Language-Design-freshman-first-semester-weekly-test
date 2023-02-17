/*输入
?
n个整数，计算它们的平均值，保留小数点后两位。注意：输入可能是无效整数，表示为n/a。在计算平均值时，先排除掉无效整数。

输入
每个输入包含一个测试用例，第1行输入n (1≤n≤100)；第2行输入n个整数，之间用空格分隔。

输出
平均值，保留小数点后两位。如果输入全为n/a，则输出n/a*/

#include <stdio.h>

int main () {
	int n;
	int temp;
	char ch;
	int no;
	float avg = 0;
	int num;
	scanf ( "%d" , &n );
	num = n;
	getchar();
	for ( int i = 0 ; i < n ; i++ ) {
		no = 1;
		temp = 0;
		ch = getchar();
		if ( ch == 'n' ) {
			num--;
			getchar();
			getchar();
			getchar();
			continue;
		}
		if ( ch == '-' ) {
			no = -1;
			ch = getchar();
		}
		while ( ch != ' ' && ch != '\n' ) {
			temp = temp * 10 + ch - 48;
			ch = getchar();
		}
		avg += temp * no;
	}
	if ( num == 0 ) {
		printf ("n/a");
		return 0;
	}
	avg /= num;
	printf ( "%.2f" , avg );
	return 0;
}
