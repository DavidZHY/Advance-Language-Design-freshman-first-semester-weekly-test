/*����һ���������� �ж����ǲ��ǻ�����������������˳�ſ��͵��ſ���һ������������1221��12321���ǻ���������

����
��һ������һ��������n����ʾ��n�����ݡ�ÿ������Ϊһ����������

���
����ÿ�����ݣ����ǻ������������yes�������������no��*/

#include <stdio.h>

int multip ( int a , int b );
int dig ( int a , int b );

int multip ( int a , int b ) {
	int c = 1;
	for ( int i = 1 ; i <= b ; i++ ) {
		c *= a;
	}
	return c;
}

int dig ( int num , int dig ) {
	int A , tst;
	tst = multip ( 10 , dig );
	A = num / multip ( 10 , dig - 1 ) - num / multip ( 10 , dig ) * 10;
	return A;
}

int main() {
	int ttl , num , n = 0 , i = 1;//ttl:number of numbers ; num:number ; n:number of digits ; i:additional number
	int halfn , decide = 0 , A , B;
	scanf ( "%d" , &ttl );
	for ( int m = 1 ; m <= ttl ; m++ ) {
		scanf ( "%d" , &num );
		while ( num / i != 0 ) {
			n++;
			i *= 10;
		}
		for ( int k = 1 ; k <= n ; k++ ) {
			A = dig ( num , k );
			B = dig ( num , n - k + 1 );
			if ( A != B ) {
				decide++;
			}
		}
		if ( !decide ) {
			printf ("yes\n");
		} else {
			printf ("no\n");
		}
		decide = 0;
	}
}
