/*用点阵的形式在字符界面上显示数字。数字按如下形式显示。每个数字占5列7行，数字和数字之间用2个空格隔开

*****      *  *****  *****  *   *  *****  *****  *****  *****  *****
*   *      *      *      *  *   *  *      *          *  *   *  *   *
*   *      *      *      *  *   *  *      *          *  *   *  *   *
*   *      *  *****  *****  *****  *****  *****      *  *****  *****
*   *      *  *          *      *      *  *   *      *  *   *      *
*   *      *  *          *      *      *  *   *      *  *   *      *
*****      *  *****  *****      *  *****  *****      *  *****  *****
输入
输入的第一行含一个正整数k，表示测试例的个数，后面紧接着k行，每行对应一个测试例，包含一个正整数x(0≤x≤9999)。

输出
每个测试例，先输出x和冒号(英文字符，半角)，换行后输出x的点阵显示形式，每位数字之间用2个空格隔开。如果行末有空格，请保留。*/

#include <stdio.h>

#define COLUMN 30
#define LINE 7

int main () {
	int l;
	int num , number;
	int temp;
	int digit [ 4 ];
	int a [ COLUMN ] [ LINE ];
	scanf ( "%d" , &l );
	for ( int k = 0 ; k < l ; k++ ) {
		for ( int i = 0 ; i < 4 ; i++ ) {
			digit [ i ] = 10;
		}//initialize array
		scanf ( "%d" , &num );
		number = num;
		if ( num == 0 ) {
			digit [ 3 ] = 0;
		}
		for ( int i = 3 ; num != 0 ; i-- ) {
			digit [ i ] = num % 10;
			num /= 10;
		}//end enter number
		temp = 0;
		while ( digit [ temp ] == 10 ) {
			temp++; 
		}
		printf ( "%d:\n" , number );
		for ( int i = temp ; i < 4 ; i++ ) {
			switch ( digit [ i ] ) {
				case 1: {
					printf ("    *");
					break;
				}
				case 4: {
					printf ("*   *");
					break;
				}
				default: {
					printf ("*****");
				}
			}
			if ( i != 3 ) {
				printf ("  ");
			}
		}
		printf("\n");//line1
		for ( int j = 0 ; j < 2 ; j++ ) {
			for ( int i = temp ; i < 4 ; i++ ) {
				switch ( digit [ i ] ) {
					case 0: {
						printf ("*   *");
						break;
					}
					case 4: {
						printf ("*   *");
						break;
					}
					case 8: {
						printf ("*   *");
						break;
					}
					case 9: {
						printf ("*   *");
						break;
					}
					case 5: {
						printf ("*    ");
						break;
					}
					case 6: {
						printf ("*    ");
						break;
					}
					default: {
						printf ("    *");
					}
				}
				if ( i != 3 ) {
					printf ("  ");
				}
			}
			printf("\n");
		}//line2&3
		for ( int i = temp ; i < 4 ; i++ ) {
			switch ( digit [ i ] ) {
				case 1: {
					printf ("    *");
					break;
				}
				case 7: {
					printf ("    *");
					break;
				}
				case 0: {
					printf ("*   *");
					break;
				}
				default: {
					printf ("*****");
				}
			}
			if ( i != 3 ) {
				printf ("  ");
			}
		}
		printf("\n");//line4
		for ( int j = 0 ; j < 2 ; j++ ) {
			for ( int i = temp ; i < 4 ; i++ ) {
				switch ( digit [ i ] ) {
					case 0: {
						printf ("*   *");
						break;
					}
					case 6: {
						printf ("*   *");
						break;
					}
					case 8: {
						printf ("*   *");
						break;
					}
					case 2: {
						printf ("*    ");
						break;
					}
					default: {
						printf ("    *");
					}
				}
				if ( i != 3 ) {
					printf ("  ");
				}
			}
			printf("\n");
		}//line5&6
		for ( int i = temp ; i < 4 ; i++ ) {
			switch ( digit [ i ] ) {
				case 1: {
					printf ("    *");
					break;
				}
				case 7: {
					printf ("    *");
					break;
				}
				case 4: {
					printf ("    *");
					break;
				}
				default: {
					printf ("*****");
				}
			}
			if ( i != 3 ) {
				printf ("  ");
			}
		}
		printf ("\n");//line7
	}
	return 0;
}
