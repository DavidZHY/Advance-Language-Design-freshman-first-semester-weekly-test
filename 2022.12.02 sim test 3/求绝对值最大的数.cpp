/*��һ�������о���ֵ�����������

����
ÿ���������һ��������������һ������m(1<=m<=20)����ʾ�����m������(�ܹ���32λ������ʾ)������֮���ÿո�ָ���

���
ÿ�����ռһ�У��������ֵ��������(���������ֵ��Ӧ�����������)*/

#include <stdio.h>

int main () {
	int n;
	long long a;
	long long max = 0;
	int no , maxno;
	scanf ( "%d" , &n );
	for ( int i = 0 ; i < n ; i++ ) {
		no = 1;
		scanf ( "%lld" , &a );
		if ( a < 0 ) {
			a *= -1;
			no = -1;
		}
		if ( a > max ) {
			max = a;
			maxno = no;
		}
	} 
	printf ( "%lld" , max * maxno );
	return 0;
}
