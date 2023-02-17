/*请编写一个程序，找到一维整数数组中所有不相同的数的个数。
提示：先将数组进行排序，然后再从排序好的数组里找出不相同的数。

输入
第1行是一个整数n，表示随后有n组数据。
每组数据占2行，第1行是1个整数num，代表数组元素个数，第2行是数组的元素。

输出
对每组数据，输出数组中不相同的数的个数，并换行。*/

#include <stdio.h>

int main() {
	int ttl;//count
	int a [ 20 ] = { 0 };//group
	int numnum /*number of number*/ , result = 0 , i;
	int temp;//requeue:
	scanf ( "%d" , &ttl );
	for ( int m = 1 ; m <= ttl ; m++ ) {
		scanf ( "%d" , &numnum );
		for (i = 0; i < numnum ; i++) {
	        scanf( "%d", &a [ i ] );
	    }
		//finish enter
		for ( i = 0 ; i < numnum - 1 ; i++ ) {
			for ( int j = 0 ; j < numnum - i - 1; j++ ) {
				if ( a [ j + 1 ] < a [ j ] ) {
					temp = a [ j + 1 ];
					a [ j + 1 ] = a [ j ];
					a [ j ] = temp;
					temp = 0;
				}
			}
		}//finish requeue
		i = 0;
		while ( i <= numnum - 2 ) {
			if ( a [ i ] != a [ i + 1 ] ) {
				result++;
			}
			i++;
		}
		printf ( "%d\n" , result + 1 );
		result = 0;
	}
	return 0;
}
