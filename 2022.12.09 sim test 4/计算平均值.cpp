/*��n���������������ǵ�ƽ��ֵ��

����
ÿ���������һ��������������1������n (1��n��100)����2������n��������֮���ÿո�ָ���

���
ƽ��ֵ������С�������λ��*/

#include <stdio.h>

int main () {
	int n;
	int temp;
	float avg = 0;
	scanf ( "%d" , &n );
	for ( int k = 0 ; k < n ; k++ ) {
		scanf ( "%d" , &temp );
		avg += temp;
	}
	avg /= n;
	printf ( "%.2f" , avg );
	return 0;
}
