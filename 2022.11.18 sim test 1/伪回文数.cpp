/*����һ���������� �ж����ǲ���һ��α������������������˳�ſ��͵��ſ���һ������������1221��12321���ǻ�������α�������ǸĶ�һ�����־��ܱ�ɻ�����������1λ������α���������� 

����
��һ������һ��������n����ʾ������n�����ݡ�
ÿ������Ϊһ�����������ܹ���int���棬ռ��һ�С� 

���
����ÿ�����ݣ�����α�������������yes�������������no��*/

#include <stdio.h>

int main () {
	int n;
	char ch;
	int digit , count;
	int a [ 100 ] = { 0 };
	scanf ( "%d" , &n );
	getchar();
	for ( int i = 0 ; i < n ; i++ ) {
		count = 0;
		ch = getchar();
		for ( digit = 0 ; ch != '\n' ; digit++ ) {
			a [ digit ] = ch - 48;
			ch = getchar();
		}
		for ( int j = 0 ; j < digit ; j++ ) {
			if ( a [ j ] != a [ digit - j - 1 ] ) {
				count++;
			}
		}
		if ( count == 2 ) {
			printf ("yes\n");
		} else {
			printf ("no\n");
		}
	}
	return 0;
}
