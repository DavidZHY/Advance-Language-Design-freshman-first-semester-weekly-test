/*����һ���ı���ͳ���м���ִ������Ļ�������������������12321��1221������˳���������ͬ��ʮ�����޷��������������Ƿ��ţ���������Ϊ2��������0��ʼ�����⣬����������һ���֣���abc1232abc�е�232����һ������������(���ݿ��ܳ���32λ)

����
��������Ϊһ���ı������ܰ��������У�ֱ���ļ�ĩβΪֹ����ֻ��һ�����������

���
����ÿһ���������ݣ�������ִ������Ļ������������ֵĴ���������ж���������ִ�С���������ÿ����ռһ�С����û�У� ���None��*/

#include <stdio.h>
#include <string.h>

struct numbers {
	int num [ 100 ] = { 0 };
	int digit = 0;
	int times = 0;
} num [ 100 ] ;

int main () {
	char a [ 10000 ] = { 0 };
	int b [ 100 ] [ 100 ] = { 0 };
	char ch;
	int ttnum; 
	int temp;
	int maxtime = 0;
	int length = 0;
	ch = getchar();
	while ( ch != EOF ) {
		a [ length ] = ch;
		ch = getchar();
		length++;
	}//end input array
	temp = 0;
	for ( int i = 0 ; i < length - 1 ; i++ ) {
		if ( a [ i ] > '0' && a [ i ] <= '9' && a [ i + 1 ] >= '0' && a [ i + 1 ] <= '9' ) {
			for ( int j = 0 ; a [ j + i ] >= '0' && a [ j + i ] <= '9' ; j++ ) {
				num [ temp ] . num [ j ] = a [ j + i ] - 48;
				num [ temp ] . digit++;
			}
			i += num [ temp ] . digit;
			temp++;
		} else {
			
		}
	}//end extract numbers
	ttnum = temp;
	for ( int i = 0 ; i < ttnum ; i++ ) {
		temp = 0;
		for ( int j = 0 ; j < num [ i ] . digit ; j++ ) {
			if ( num [ i ] . num [ j ] != num [ i ] . num [ num [ i ] . digit - j - 1 ] ) {
				temp = 1;
				break;
			}
		}
		if ( temp ) {
			num [ i ] . times = -100;
		}
	}
	for ( int i = 0 ; i < ttnum ; i++ ) {
		for ( int j = i ; j < ttnum ; j++ ) {
			temp = 0;
			if ( num [ i ] . digit == num [ j ] . digit ) {
				for ( int k = 0 ; k < num [ i ] . digit ; k++ ) {
					if ( num [ i ] . num [ k ] != num [ j ] . num [ k ] ) {
						temp = 1;
						break;
					}
				}
				if ( !temp ) {
					num [ i ] . times++;
				}
			}
			if ( num [ i ] . times > maxtime ) {
				maxtime = num [ i ] . times;
			}
		}
	}//end calculate time & get max time
	temp = 0;
	for ( int i = 0 ; i < ttnum ; i++ ) {
		if ( num [ i ] . times == maxtime ) {
			num [ temp ] . times = num [ i ] . times;
			num [ temp ] . digit = num [ i ] . digit;
			for ( int j = 0 ; j < 100 ; j++ ) {
				num [ temp ] . num [ j ] = num [ i ] . num [ j ];
			}
			temp++;
		}
	}//end distinguish plina
	ttnum = temp;
	for ( int i = 0 ; i < ttnum ; i++ ) {
		for ( int j = 0 ; j < ttnum - i - 1 ; j++ ) {
			temp = 0;
			if ( num [ j ] . digit > num [ j + 1 ] . digit ){
				temp = 1;
			} else if ( num [ j ] . digit == num [ j + 1 ] . digit ) {
				for ( int k = 0 ; k < num [ j ] . digit ; j++ ) {
					if ( num [ j ] . num [ k ] != num [ j ] . num [ k ] ) {
						if ( num [ j ] . num [ k ] > num [ j ] . num [ k ] ) {
							temp = 1;
							break;
						}
					}
				}
			}//end judge switch
			if ( temp ) {
				temp = num [ j ] . digit;
				num [ j ] . digit = num [ j + 1 ] . digit;
				num [ j + 1 ] . digit = temp;
				for ( int k = 0 ; k < 100 ; k++ ) {
					temp = num [ j ] . num [ k ];
					num [ j ] . num [ k ] = num [ j + 1 ] . num [ k ];
					num [ j + 1 ] . num [ k ] = temp;
				}
			}
		}
	}//end switch
	if ( num [ 0 ] . times < 0 ) {
		printf ("None");
		return 0;
	}
	for ( int i = 0 ; i < ttnum ; i++ ) {
		for ( int j = 0 ; j < num [ i ] . digit ; j++ ) {
			printf ( "%d" , num [ i ] . num [ j ] );
		}
		printf ( " %d" , num [ i ] . times );
		printf ("\n");
	}
	return 0;
}
