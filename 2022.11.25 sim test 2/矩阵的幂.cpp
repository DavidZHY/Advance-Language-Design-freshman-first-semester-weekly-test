#include <stdio.h>

int main () {
	long long a [ 100 ] [ 100 ] = { 0 };
	long long b [ 100 ] [ 100 ] = { 0 };
	long long c [ 100 ] [ 100 ] = { 0 };
	int N , K;
	long long temp;
	char ch;
	scanf ( "%d%d" , &N , &K );
	
	for ( int i = 0 ; i < N ; i++ ) {
		for ( int j = 0 ; j < N ; j++ ) {
			scanf ( "%d" , &a [ i ] [ j ] );
			b [ i ] [ j ] = a [ i ] [ j ];
		}
	}
	K--;
	for ( int n = 0 ; n < K ; n++ ) {
		for ( int i = 0 ; i < N ; i++ ) {
			for ( int j = 0 ; j < N ; j++ ) {
				temp = 0;
				for ( int k = 0 ; k < N ; k++ ) {
					temp += a [ i ] [ k ] * b [ k ] [ j ];
				}
				c [ i ] [ j ] = temp;
			}
		}
		for ( int i = 0 ; i < N ; i++ ) {
			for ( int j = 0 ; j < N ; j++ ) {
				b [ i ] [ j ] = c [ i ] [ j ];
			}
		}
		for ( int i = 0 ; i < N ; i++ ) {
			for ( int j = 0 ; j < N ; j++ ) {
				c [ i ] [ j ] = 0;
			}
		}
	}
	for ( int i = 0 ; i < N ; i++ ) {
		for ( int j = 0 ; j < N ; j++ ) {
			printf ( "%lld " , b [ i ] [ j ] );
		}
		printf ("\n");
	}
	return 0;
} 
