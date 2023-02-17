/*已知nn个人（以编号1,2,3,...,n1,2,3,...,n分别表示）围坐在一张圆桌周围。从编号为kk的人开始报数，数到mm的那个人出列；他的下一个人又从11开始报数，数到mm的那个人又出列；依此规律重复下去，直到圆桌只剩下2个人，请问这两个人的编号分别是多少？

输入
依次输入n,k,mn,k,m。以空格隔开。1 ≤k1≤k； 2 ≤m ≤n ≤1002≤m≤n≤100

输出
剩余两个满足描述条件的编号。以空格隔开。其中两个编号的顺序为从小到大排序。*/

#include <stdio.h>

int main () {
	int total/*num of personnel*/ , startnum/*start number*/ , T/*circle time*/;
	int remain , currentnum , i = 0 , count = 0;
	int a[101] = {0};
	int temp;
	scanf ( "%d%d%d" , &total , &startnum , &T );
	remain = total;
	currentnum = startnum - 1;
	for ( i = 0 ; i < total ; i++ ) {
		a[i] = i + 1;
	}
	while ( remain > 2 ) {
		currentnum += T;
		while ( currentnum > remain ) {
			currentnum -= remain;
		}
		for ( i = currentnum - 1 ; i < remain ; i++ ) {
			a[i] = a[ i + 1 ];
		}
		currentnum--;
		remain--; 
	}
	for ( i = 0 ; i < 2 ; i++ ) {
		for ( int j = 0 ; j < 2 - i - 1 ; j++ ) {
			if ( a [ j + 1 ] < a [ j ] ) {
				temp = a [ j + 1 ];
				a [ j + 1 ] = a [ j ];
				a [ j ] = temp;
				temp = 0;
			}
		}
	}
	for ( i = 0 ; i < 4 ; i++ ) {
		if ( a[i] ) {
			printf ( "%d " , a[i] );
		}
	}
	return 0;
}
