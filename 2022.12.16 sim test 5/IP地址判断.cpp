/*合法的IP地址是这样的形式：

   A.B.C.D
其中A、B、C、D均为位于[0, 255]中的整数。为了简单起见，我们规定这四个整数中不会有前导零存在，如001这种情况。请编写程序判断IP地址的合法性。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，为一个待判断合法性的IP地址。

输出
对每组数据，如果是合法的IP地址，输出yes，否则输出no*/

#include <stdio.h>
#include <string.h>

int main () {
	int n;
	int decide;
	int num;
	int temp;
	int point;
	char ch = '\0';
	char a [ 100 ];
	scanf ( "%d" , &n );
	getchar();
	for ( int k = 0 ; k < n ; k++ ) {
		decide = 1;
		point = 0;
		for ( int i = 0 ; i < 20 ; i++ ) {
			a [ i ] = '\0';
		}
		do {
			ch = getchar();
			if ( ch == EOF ) {
				return 0;
			}
			a [ point ] = ch;
			point++;
		} while ( ch != '\n');
		point = 0;
		for ( int i = 0 ; i < 4 ; i++ ) {
			if ( a [ point ] < '0' || a [ point ] > '9' || a [ point ] == '.' || a [ point ] == '\n' ) {
				decide = 0;
			}
			num = 0;
			while ( a [ point ] != '.' && a [ point ] != '\n' ) {
				if ( a [ point ] < '0' || a [ point ] > '9' ) {
					decide = 0;
					break;
				}
				num *= 10;
				num += a [ point ] - 48;
				point++;
			}
			if ( num > 255 || num < 0 ) {
				decide = 0;
			}
			point++;
		}
		temp = 0;
		for ( int i = 0 ; i < strlen ( a ) ; i++ ) {
			if ( a [ i ] == '.' ) {
				temp++;
			}
		}
		if ( temp != 3 ) {
			decide = 0;
		}
		if ( decide ) {
			printf ("yes\n");
		} else {
			printf ("no\n");
		}	
	}
	return 0;
}
