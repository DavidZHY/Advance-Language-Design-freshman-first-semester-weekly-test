/*���дһ�������ҵ�һά�������������в���ͬ�����ĸ�����
��ʾ���Ƚ������������Ȼ���ٴ�����õ��������ҳ�����ͬ������

����
��1����һ������n����ʾ�����n�����ݡ�
ÿ������ռ2�У���1����1������num����������Ԫ�ظ�������2���������Ԫ�ء�

���
��ÿ�����ݣ���������в���ͬ�����ĸ����������С�*/

#include <stdio.h>

int main() {
	int ttl;//count
	int a [ 20 ] = { 0 };//group
	int numnum /*number of number*/ , result = 0 , i;
	int temp;//requeue:
	scanf ( "%d" , &ttl );
	for ( int m = 1 ; m <= ttl ; m++ ) {
		scanf ( "%d" , &numnum );
		for (i = 0; i < numnum ; i++) {
	        scanf( "%d", &a [ i ] );
	    }
		//finish enter
		for ( i = 0 ; i < numnum - 1 ; i++ ) {
			for ( int j = 0 ; j < numnum - i - 1; j++ ) {
				if ( a [ j + 1 ] < a [ j ] ) {
					temp = a [ j + 1 ];
					a [ j + 1 ] = a [ j ];
					a [ j ] = temp;
					temp = 0;
				}
			}
		}//finish requeue
		i = 0;
		while ( i <= numnum - 2 ) {
			if ( a [ i ] != a [ i + 1 ] ) {
				result++;
			}
			i++;
		}
		printf ( "%d\n" , result + 1 );
		result = 0;
	}
	return 0;
}
