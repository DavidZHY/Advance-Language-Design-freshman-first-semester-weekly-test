/*��֪nn���ˣ��Ա��1,2,3,...,n1,2,3,...,n�ֱ��ʾ��Χ����һ��Բ����Χ���ӱ��Ϊkk���˿�ʼ����������mm���Ǹ��˳��У�������һ�����ִ�11��ʼ����������mm���Ǹ����ֳ��У����˹����ظ���ȥ��ֱ��Բ��ֻʣ��2���ˣ������������˵ı�ŷֱ��Ƕ��٣�

����
��������n,k,mn,k,m���Կո������1 ��k1��k�� 2 ��m ��n ��1002��m��n��100

���
ʣ�������������������ı�š��Կո����������������ŵ�˳��Ϊ��С��������*/

#include <stdio.h>

int main () {
	int total/*num of personnel*/ , startnum/*start number*/ , T/*circle time*/;
	int remain , currentnum , i = 0 , count = 0;
	int a[101] = {0};
	int temp;
	scanf ( "%d%d%d" , &total , &startnum , &T );
	remain = total;
	currentnum = startnum - 1;
	for ( i = 0 ; i < total ; i++ ) {
		a[i] = i + 1;
	}
	while ( remain > 2 ) {
		currentnum += T;
		while ( currentnum > remain ) {
			currentnum -= remain;
		}
		for ( i = currentnum - 1 ; i < remain ; i++ ) {
			a[i] = a[ i + 1 ];
		}
		currentnum--;
		remain--; 
	}
	for ( i = 0 ; i < 2 ; i++ ) {
		for ( int j = 0 ; j < 2 - i - 1 ; j++ ) {
			if ( a [ j + 1 ] < a [ j ] ) {
				temp = a [ j + 1 ];
				a [ j + 1 ] = a [ j ];
				a [ j ] = temp;
				temp = 0;
			}
		}
	}
	for ( i = 0 ; i < 4 ; i++ ) {
		if ( a[i] ) {
			printf ( "%d " , a[i] );
		}
	}
	return 0;
}
