/*��ĳ�������У���n֧�������ѭ��������������֧��֮�䶼Ҫ����һ��������������n/2(��)���ڵĶ�����Ի񽱡�
���ΰ��ջ��ֺ;��÷ִ�1��ʼ���������š�
���ֶ�Ķ������ο�ǰ�����������ͬ���򾻵÷ֶ�����ο�ǰ��������÷���Ȼ��ͬ����������ͬ��
���ĳ�������ж�֧����(����x֧)��������������x-1�������ټ���������
���ֹ���Ϊ����ʤһ����3�֣�ƽ�ֻ�1�֣��䲻���֡����÷�Ϊ�ܵ÷�-��ʧ�֡���3-1-0���ƣ� 

����
��һ��һ������n(2<=n<=1000��nΪż��)����ʾ�������������n�У�ÿ�б�ʾһ֧���������(����������ĸ���ֺͿո��⼸���ַ������Ȳ�����50���ַ�)�������n(n-1)/2�У�ÿ�еĸ�ʽΪname1-name2: score1-score2��ʾ���ӱ����÷֡������ڡ�:����-��ǰ����ܴ������ɿո�ÿ���÷ֲ�����100�֡�

���
�����δ�ǰ��������񽱶�������ơ�������ͬ�Ķ��飬�������ֵ���˳�������*/

#include <stdio.h>

#define N 500

int main () {
	int team [ 1001 ] [ N ] = { 0 };
	int match [ 2 ] [ N ] = { 0 };
	int n;
	int digit;
	int score1 , score2;
	char ch;
	int temp;
	scanf ( "%d\n" , &n );
	for ( int i = 0 ; i < n ; i++ ) {
		digit = 0;
		ch = getchar();
		while ( ch != '\n' ) {
			team [ i ] [ digit + 3 ] = ch;
			digit++;
			ch = getchar();
		}
		team [ i ] [ 2 ] = digit;
	}//end enter team name
	for ( int j = 0 ; j < ( n * ( n - 1 ) ) / 2 ; j++ ) {
		temp = 0;
		digit = 0;
		ch = getchar();
		while ( ch != '-' ) {
			if ( ch == ' ' ) {
				temp++;
			} else {
				temp = 0;
			}
			match [ 0 ] [ digit + 3 ] = ch;
			digit++;
			ch = getchar();
		}
		for ( int i = 0 ; i < temp + 1 ; i++ ) {
			match [ 0 ] [ digit - i + 3 ] = 0;
		}
		match [ 0 ] [ 2 ] = digit - temp;
		temp = 0;
		digit = 0;//enter name1
		while ( ch == ' ' || ch == '-' ) {
			ch = getchar();
		}//skip '-'
		while ( ch != ':' ) {
			if ( ch == ' ' ) {
				temp++;
			} else {
				temp = 0;
			}
			match [ 1 ] [ digit + 3 ] = ch;
			digit++;
			ch = getchar();
		}
		for ( int i = 0 ; i < temp + 1 ; i++ ) {
			match [ 1 ] [ digit - i + 3 ] = 0;
		}
		match [ 1 ] [ 2 ] = digit - temp;
		digit = 0;//enter name2
		score1 = 0;
		score2 = 0;
		while ( ch == ' ' || ch == ':' ) {
			ch = getchar();
		}//skip ':'
		score1 += ch - 48;
		ch = getchar();
		if ( ch >= '0' && ch <= '9' ) {
			score1 = score1 * 10 + ch - 48;
		}
		ch = getchar();
		while ( ch == ' ' || ch == '-' ) {
			ch = getchar();
		}//skip '-'
		score2 += ch - 48;
		ch = getchar();
		if ( ch >= '0' && ch <= '9' ) {
			score2 = score2 * 10 + ch - 48;
		}//end collect score
		if ( score1 < score2 ) {
			match [ 0 ] [ 0 ] = 0;
			match [ 1 ] [ 0 ] = 3;
			match [ 0 ] [ 1 ] = score1 - score2;
			match [ 1 ] [ 1 ] = score2 - score1;
		} else if ( score1 > score2 ) {
			match [ 0 ] [ 0 ] = 3;
			match [ 1 ] [ 0 ] = 0;
			match [ 0 ] [ 1 ] = score1 - score2;
			match [ 1 ] [ 1 ] = score2 - score1;
		} else {
			match [ 0 ] [ 0 ] = 1;
			match [ 1 ] [ 0 ] = 1;
			match [ 0 ] [ 1 ] = 0;
			match [ 1 ] [ 1 ] = 0;
		}//end allot data
		for ( int j = 0 ; j < n ; j++ ) {
			temp = 0;
			for ( int k = 3 ; k < N ; k++ ) {
				if ( team [ j ] [ k ] == match [ 0 ] [ k ] ) {
					
				} else {
					temp++;
				}
			}
			if ( temp == 0 ) {
				team [ j ] [ 0 ] += match [ 0 ] [ 0 ];
				team [ j ] [ 1 ] += match [ 0 ] [ 1 ];
				break;
			}
		}//upload data 1
		for ( int j = 0 ; j < n ; j++ ) {
			temp = 0;
			for ( int k = 3 ; k < N ; k++ ) {
				if ( team [ j ] [ k ] == match [ 1 ] [ k ] ) {
					
				} else {
					temp++;
				}
			}
			if ( temp == 0 ) {
				team [ j ] [ 0 ] += match [ 1 ] [ 0 ];
				team [ j ] [ 1 ] += match [ 1 ] [ 1 ];
				break;
			}
		}//upload data 2
		if ( ch != '\n' ) {
			ch = getchar();
		}
	}//end uploading data into team[][]
	for ( int i = 0 ; i < n ; i++ ) {//start requeuing
		for ( int j = 0 ; j < n - i - 1 ; j++ ) {
			if ( team [ j ] [ 0 ] < team [ j + 1 ] [ 0 ] || team [ j ] [ 0 ] == team [ j + 1 ] [ 0 ] && team [ j ] [ 1 ] < team [ j + 1 ] [ 1 ] ) {
				for ( int m = 0 ; m < N ; m++ ) {
					team [ 1000 ] [ m ] = team [ j ] [ m ];
					team [ j ] [ m ] = team [ j + 1 ] [ m ];
					team [ j + 1 ] [ m ] = team [ 1000 ] [ m ];
				}//orgnized by points
			} else if ( team [ j ] [ 0 ] == team [ j + 1 ] [ 0 ] && team [ j ] [ 1 ] == team [ j + 1 ] [ 1 ] ) {
				temp = 0;
					for ( int k = 0 ; k < team [ j ] [ 2 ] ; k++ ) {
						temp = team [ j ] [ k + 3 ] - team [ j + 1 ] [ k + 3 ];
						if ( temp != 0 ) {
							break;
						}
					}
					if ( temp > 0 ) {
						for ( int m = 0 ; m < N ; m++ ) {
							team [ 1000 ] [ m ] = team [ j ] [ m ];
							team [ j ] [ m ] = team [ j + 1 ] [ m ];
							team [ j + 1 ] [ m ] = team [ 1000 ] [ m ];
						}
					}
			}//organized by names
		}
	}
	for ( int i = 0 ; i < n / 2 ; i++ ) {
		for ( int j = 0 ; j < team [ i ] [ 2 ] ; j++ ) {
			printf ( "%c" , team [ i ] [ j + 3 ] ); 
		}
		printf ("\n");
	}
	for ( int i = n / 2 - 1 ; team [ i ] [ 0 ] == team [ i + 1 ] [ 0 ] && team [ i ] [ 1 ] == team [ i + 1 ] [ 1 ] ; i++ ) {
		for ( int j = 0 ; j < team [ i + 1 ] [ 2 ] ; j++ ) {
			printf ( "%c" , team [ i + 1 ] [ j + 3 ] ); 
		}
		printf ("\n");
	}//print out result
	return 0;
}
