/*�ʺ��ǹ����������������Ľ�ɫ(so are women in real world)��
�������Ĳ��Ϸ�չ��Խ��Խ���������ʶ���ʺ��ڹ���������ĵ�λӦ�ý���,������������Ż����ƽ��������˼��
�ڴ�ͳ�������ϣ��ʺ���������ķ���(��,��,б)���ƶ�����Ĳ����� 
�µĹ�������涨���ʺ�����ֱ�����ϻ��ǿ����ƶ�����Ĳ��������ڳ���֮������������ϣ�ˮƽ�ͶԽǣ�����ֻ�������һ���ƶ�һ��
���ʺ��ǲ������ݣ���ʹ���Ǳ������˵�ĳЩȨ��������ҲҪ��취������������ÿ���ʺ��ܱ�ͬ��֧Ԯ������

��ÿ�������ϣ�������ÿһ���Ϸ�һ���ʺ�
����ǰ����˵�����������еĻʺ���Ҫ����������
Ҳ����˵��ÿ���������еĻʺ�֮����о������ֻ�ܲ�һ�������ſ��Լ�ʱ����֧Ԯ(��ͼ�������ĸ����ӣ�ǰ��������ȷ�ģ����һ���Ǵ����)��
�������Ǹ������̵Ĵ�С�ͳ�ʼ״̬�����ܼ����һ���ж����ֲ�ͬ�ķ��ûʺ�ķ���ʹ�����еĻʺ�������������?

�����������������ݡ�ÿ�����ݵĵ�һ�а���һ������n(1��n��10)������һ��n*n�����̡���������һ�а���n��������
�����ʼʱÿ�����еĻʺ��λ�ã�������ֵΪi�����������һ���ϣ�������������i�������Ѿ����˻ʺ�
������ֵΪ0��������һ�л�û�лʺ���ʱ�������������ĿҪ�������°�һ���ʺ������һ�е�����λ�á�
��n=0ʱ����������������ݲ���������Ҫ����������С�

���
����ÿһ���������ݣ����һ����������������������·��������ķ��ûʺ�ķ������������0�����޷�����������*/

#include <stdio.h>

int queen ( int a [ ] , int n ) {
	int position = 0;
	int result = 0;
	int temp;
	for ( int i = 0 ; i < n - 1 ; i++ ) {
		if ( a [ i ] != 0 && a [ i + 1 ] != 0 ) {
			if ( a [ i ] - a [ i + 1 ] > 1 || a [ i ] - a [ i + 1 ] < -1 ) {
				return 0;
			}
		}
	}
	while ( a [ position ] != 0 ) {
		position++;
	}
	if ( position == n ) {
		return 1;
	}//no 0 exsists
	if ( position == 0 ) {
		if ( a [ 1 ] != 0 ) {
			if ( a [ 1 ] == 1 ) {
				temp = a [ 0 ];
				a [ 0 ] = 1;
				result += queen ( a , n );
				a [ 0 ] = 2;
				result += queen ( a , n );
				a [ 0 ] = temp;
			} else if ( a [ 1 ] == n ) {
				temp = a [ 0 ];
				a [ 0 ] = n - 1;
				result += queen ( a , n );
				a [ 0 ] = n;
				result += queen ( a , n );
				a [ 0 ] = temp;
			} else {
				temp = a [ 0 ];
				a [ 0 ] = a [ 1 ];
				result += queen ( a , n );
				a [ 0 ] = a [ 1 ] - 1;
				result += queen ( a , n );
				a [ 0 ] = a [ 1 ] + 1;
				result += queen ( a , n );
				a [ 0 ] = temp;
			}
		} else {
			for ( int i = 1 ; i <= n ; i++ ) {
				temp = a [ 0 ];
				a [ 0 ] = i;
				result += queen ( a , n );
				a [ 0 ] = temp;
			}
			//return result;
		}
	} else {
		if ( a [ position + 1 ] != 0 ) {
			if ( a [ position + 1 ] == a [ position - 1 ] ) {
				if ( a [ position + 1 ] == 1 ) {
					temp = a [ position ];
					a [ position ] = 1;
					result += queen ( a , n );
					a [ position ] = 2;
					result += queen ( a , n );
					a [ position ] = temp;
				} else if ( a [ position + 1 ] == n ) {
					temp = a [ position ];
					a [ position ] = n;
					result += queen ( a , n );
					a [ position ] = n - 1;
					result += queen ( a , n );
					a [ position ] = temp;
				} else {
					temp = a [ position ];
					a [ position ] = a [ position - 1 ];
					result += queen ( a , n );
					a [ position ] = a [ position - 1 ] + 1;
					result += queen ( a , n );
					a [ position ] = a [ position - 1 ] - 1;
					result += queen ( a , n );
					a [ position ] = temp;
				}
			}
			if ( a [ position + 1 ] - a [ position - 1 ] == -1 || a [ position + 1 ] - a [ position - 1 ] == 1 ) {
				temp = a [ position ];
				a [ position ] = a [ position + 1 ];
				result += queen ( a , n );
				a [ position ] = a [ position - 1 ];
				result += queen ( a , n );
				a [ position ] = temp;
			}
			if ( a [ position + 1 ] - a [ position - 1 ] == -2 || a [ position + 1 ] - a [ position - 1 ] == 2 ) {
				temp = a [ position ];
				a [ position ] = ( a [ position - 1 ] + a [ position + 1 ] ) / 2;
				result += queen ( a , n );
				a [ position ] = temp;
			}
		} else {
			if ( a [ position - 1 ] == 1 ) {
				temp = a [ position ];
				a [ position ] = 1;
				result += queen ( a , n );
				a [ position ] = 2;
				result += queen ( a , n );
				a [ position ] = temp;
			} else if ( a [ position - 1 ] == n ) {
				temp = a [ position ];
			 	a [ position ] = n;
				result += queen ( a , n );
				a [ position ] = n - 1;
				result += queen ( a , n );
				a [ position ] = temp;
			} else {
				temp = a [ position ];
			 	a [ position ] = a [ position - 1 ];
				result += queen ( a , n );
				a [ position ] = a [ position - 1 ] + 1;
				result += queen ( a , n );
				a [ position ] = a [ position - 1 ] - 1;
				result += queen ( a , n );
				a [ position ] = temp;
			}
		}
	}
	return result;
}

int main () {
	int n;
	int a [ 11 ] = { 0 };
	int result;
	while ( scanf ( "%d" , &n ) != EOF && n != 0 ) {
		for ( int i = 0 ; i < 11 ; i++ ) {
			a [ i ] = 0;
		}
		for ( int i = 0 ; i < n ; i++ ) {
			scanf ( "%d" , &a [ i ] );
		}
		result = queen ( a , n );
		printf ( "%d\n" , result );
	}
	return 0;
} 
