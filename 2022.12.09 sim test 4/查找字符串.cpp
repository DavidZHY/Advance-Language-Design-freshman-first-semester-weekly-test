/*�ж��ַ����Ƿ�����Ҫ������ַ�����������Ҫ��֮һ���ַ������YES���������NO��
�ַ�������SCU��
����xSCUx���ַ���,����x�ǽ�����ĸA��ɵ��ַ�����

����
ÿ�������������1��������������1�и���һ����Ȼ��n (n<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�

���
ÿ���ַ����ļ����ռһ�У�������ַ������������������YES���������NO��*/

#include <stdio.h>

#define N 100

int main () {
	int n;
	char ch;
	int length;
	int temp;
	int startp , startA , endA;
	char a [ N ];
	scanf ( "%d" , &n );
	getchar();
	for ( int k = 0 ; k < n ; k++ ) {
		temp = 0;
		length = 0;
		for ( int i = 0 ; i < N ; i++ ) {
			a [ i ] = '\0';
		}
		ch  = getchar();
		while ( ch != '\n' ) {
			a [ length ] = ch;
			length++;
			ch = getchar();
		}//end input array
		startp = N + 1;
		for ( int i = 0 ; i < length - 2 ; i++ ) {
			if ( a [ i ] == 'S' && a [ i + 1 ] == 'C' && a [ i + 2 ] == 'U' ) {
				startp = i;
				break;
			}
		}//find SCU
		if ( startp == N + 1 ) {
			printf ("NO\n");
			temp = 1;
			continue;
		}//case: no SCU found
		startA = 0;
		endA = 0;
		temp = 0;
		for ( int i = 0 ; i < startp ; i++ ) {
			if ( a [ i ] == 'A' ) {
				startA++;
			} else {
				printf ("NO\n");
				temp = 1;
				break;
			}//not A array
		}//get startA
		if ( temp == 1 ) {
			continue;
		}
		temp = 0;
		for ( int i = startp + 3 ; i < length ; i++ ) {
			if ( a [ i ] == 'A' ) {
				endA++;
			} else {
				printf ("NO\n");
				temp = 1;
				break;
			}//not A array
		}//get endA
		if ( temp == 1 ) {
			continue;
		}
		if ( startA != endA ) {
			printf ("NO\n");
		} else {
			printf ("YES\n");
		}
	}
	return 0;
}
