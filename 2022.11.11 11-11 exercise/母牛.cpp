/*��һͷĸţ����ÿ�������һͷСĸţ��ÿͷСĸţ�ӵ��ĸ���ͷ��ʼ��ÿ�����Ҳ��һͷСĸţ������ʵ���ڵ�n���ʱ�򣬹��ж���ͷĸţ��

�����ʽ
����һ������n(0<n<55)��

�����ʽ
�����n��ĸţ��������ռһ�С�*/

#include <stdio.h>

int main () {
	int une , deu , tro;
	une = 0;
	deu = 0;
	tro = 0;
	int adu = 1;
	int year;
	int temp = 0;
	scanf ( "%d" , &year );
	for ( int i = 0 ; i < year - 1 ; i++ ) {
		adu += tro;
		temp = adu;
		tro = deu;
		deu = une;
		une = temp;
	}
	printf ( "%d" , une + deu + tro + adu );
	return 0;
}
