/*�õ������ʽ���ַ���������ʾ���֡����ְ�������ʽ��ʾ��ÿ������ռ5��7�У����ֺ�����֮����2���ո����

*****      *  *****  *****  *   *  *****  *****  *****  *****  *****
*   *      *      *      *  *   *  *      *          *  *   *  *   *
*   *      *      *      *  *   *  *      *          *  *   *  *   *
*   *      *  *****  *****  *****  *****  *****      *  *****  *****
*   *      *  *          *      *      *  *   *      *  *   *      *
*   *      *  *          *      *      *  *   *      *  *   *      *
*****      *  *****  *****      *  *****  *****      *  *****  *****
����
����ĵ�һ�к�һ��������k����ʾ�������ĸ��������������k�У�ÿ�ж�Ӧһ��������������һ��������x(0��x��9999)��

���
ÿ���������������x��ð��(Ӣ���ַ������)�����к����x�ĵ�����ʾ��ʽ��ÿλ����֮����2���ո�����������ĩ�пո��뱣����*/

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
