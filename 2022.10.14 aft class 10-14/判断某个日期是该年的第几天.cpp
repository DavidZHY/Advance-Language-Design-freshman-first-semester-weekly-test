/*����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿

����
��1����һ������n����ʾ�����n�����ݡ�ÿ������ռһ�У�����3������year��month��day���Կո������

���
��ÿ�����������һ������һ��ĵڼ��죬�����С�*/

#include <stdio.h>

void common ( int m , int d );
void lunar ( int m , int d );

void common ( int m , int d ) {
	int total = 0;
	switch ( m ) {
		case 1 : {
			total += 0;
			break;
		}
		case 2 : {
			total += 31;
			break;
		}
		case 3 : {
			total += 59;
			break;
		}
		case 4 : {
			total += 90;
			break;
		}
		case 5 : {
			total += 120;
			break;
		}
		case 6 : {
			total += 151;
			break;
		}
		case 7 : {
			total += 181;
			break;
		}
		case 8 : {
			total += 212;
			break;
		}
		case 9 : {
			total += 243;
			break;
		}
		case 10 : {
			total += 273;
			break;
		}
		case 11 : {
			total += 304;
			break;
		}
		case 12 : {
			total += 334;
			break;
		}
		default : {
			break;
		}
	}
	total += d;
	printf ( "%d\n" , total );
}

void lunar ( int m , int d ) {
	int total = 0;
	switch ( m ) {
		case 1 : {
			total += 0;
			break;
		}
		case 2 : {
			total += 31;
			break;
		}
		case 3 : {
			total += 60;
			break;
		}
		case 4 : {
			total += 91;
			break;
		}
		case 5 : {
			total += 121;
			break;
		}
		case 6 : {
			total += 152;
			break;
		}
		case 7 : {
			total += 182;
			break;
		}
		case 8 : {
			total += 213;
			break;
		}
		case 9 : {
			total += 244;
			break;
		}
		case 10 : {
			total += 274;
			break;
		}
		case 11 : {
			total += 305;
			break;
		}
		case 12 : {
			total += 335;
			break;
		}
		default : {
			break;
		}
	}
	total += d;
	printf ( "%d\n" , total );
}

int main () {
	int num , y , m , d;
	scanf ( "%d" , &num );
	for ( int i = 1 ; i <= num ; i++ ) {
		scanf ( "%d%d%d" , &y , &m , &d );
		if ( y % 100 == 0 ) {
			if ( y % 400 == 0 ) {
				lunar ( m , d );
			} else {
				common ( m , d );
			}
		} else {
			if ( y % 4 == 0 ) {
				lunar ( m , d );
			} else {
				common ( m , d );
			}
		}
	}
	return 0;
}
