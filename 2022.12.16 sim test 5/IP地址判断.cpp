/*�Ϸ���IP��ַ����������ʽ��

   A.B.C.D
����A��B��C��D��Ϊλ��[0, 255]�е�������Ϊ�˼���������ǹ涨���ĸ������в�����ǰ������ڣ���001������������д�����ж�IP��ַ�ĺϷ��ԡ�

����
��1����һ������n����ʾ�����n�����ݡ�ÿ������ռһ�У�Ϊһ�����жϺϷ��Ե�IP��ַ��

���
��ÿ�����ݣ�����ǺϷ���IP��ַ�����yes���������no*/

#include <stdio.h>
#include <string.h>

int main () {
	int n;
	int decide;
	int num;
	int temp;
	int point;
	char ch = '\0';
	char a [ 100 ];
	scanf ( "%d" , &n );
	getchar();
	for ( int k = 0 ; k < n ; k++ ) {
		decide = 1;
		point = 0;
		for ( int i = 0 ; i < 20 ; i++ ) {
			a [ i ] = '\0';
		}
		do {
			ch = getchar();
			if ( ch == EOF ) {
				return 0;
			}
			a [ point ] = ch;
			point++;
		} while ( ch != '\n');
		point = 0;
		for ( int i = 0 ; i < 4 ; i++ ) {
			if ( a [ point ] < '0' || a [ point ] > '9' || a [ point ] == '.' || a [ point ] == '\n' ) {
				decide = 0;
			}
			num = 0;
			while ( a [ point ] != '.' && a [ point ] != '\n' ) {
				if ( a [ point ] < '0' || a [ point ] > '9' ) {
					decide = 0;
					break;
				}
				num *= 10;
				num += a [ point ] - 48;
				point++;
			}
			if ( num > 255 || num < 0 ) {
				decide = 0;
			}
			point++;
		}
		temp = 0;
		for ( int i = 0 ; i < strlen ( a ) ; i++ ) {
			if ( a [ i ] == '.' ) {
				temp++;
			}
		}
		if ( temp != 3 ) {
			decide = 0;
		}
		if ( decide ) {
			printf ("yes\n");
		} else {
			printf ("no\n");
		}	
	}
	return 0;
}
