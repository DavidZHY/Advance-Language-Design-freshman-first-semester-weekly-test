/*����
?
n���������������ǵ�ƽ��ֵ������С�������λ��ע�⣺�����������Ч��������ʾΪn/a���ڼ���ƽ��ֵʱ�����ų�����Ч������

����
ÿ���������һ��������������1������n (1��n��100)����2������n��������֮���ÿո�ָ���

���
ƽ��ֵ������С�������λ���������ȫΪn/a�������n/a*/

#include <stdio.h>

int main () {
	int n;
	int temp;
	char ch;
	int no;
	float avg = 0;
	int num;
	scanf ( "%d" , &n );
	num = n;
	getchar();
	for ( int i = 0 ; i < n ; i++ ) {
		no = 1;
		temp = 0;
		ch = getchar();
		if ( ch == 'n' ) {
			num--;
			getchar();
			getchar();
			getchar();
			continue;
		}
		if ( ch == '-' ) {
			no = -1;
			ch = getchar();
		}
		while ( ch != ' ' && ch != '\n' ) {
			temp = temp * 10 + ch - 48;
			ch = getchar();
		}
		avg += temp * no;
	}
	if ( num == 0 ) {
		printf ("n/a");
		return 0;
	}
	avg /= num;
	printf ( "%.2f" , avg );
	return 0;
}
