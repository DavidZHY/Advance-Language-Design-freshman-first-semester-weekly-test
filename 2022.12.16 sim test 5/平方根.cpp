/*����������ƽ������

����
��1����һ������n����ʾ�����n�����ݡ�ÿ������ռһ�У�����һ������-10000��m��10000��

���
��ÿ������m������m��ƽ��������ȷ��С�����2λ�����mû��ƽ�����������ERROR��*/

#include <stdio.h>
#include <math.h>

int main () {
	int n;
	double num;
	float up , down;
	scanf ( "%d" , &n );
	for ( int k = 0 ; k < n ; k++ ) {
		scanf ( "%lf" , &num );
		if ( num == 0 ) {
			printf ("0.00\n");
			continue;
		}
		if ( num < 0 ) {
			printf ("ERROR\n");
			continue;
		}
		printf ( "%.2lf\n" , sqrt ( num ) );
	}
	return 0;
}
