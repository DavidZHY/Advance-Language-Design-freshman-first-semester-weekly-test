/*����n��ѧ�������������֤�š��ɼ������Ҳ����ƥ����Ҵ���ѧ����������ѧ�źͳɼ���ѧ�������п���ȱ����û�гɼ�����ʾΪn/a��
������Ҵ�����������������֤�ţ�����ģ�����ң���ֻҪ���а������Ҵ�(���ִ�Сд)��������������������Ҵ�����Գɼ������Ǿ�ȷ���ҡ�

����
ÿ�������������1��������������ʽΪ

������n �����Ҵ�
��1��ѧ�������� ѧ�� �ɼ�
��2��ѧ�������� ѧ�� �ɼ�
�� �� ��
��n��ѧ�������� ѧ�� �ɼ�

����n��10������Ϊ������10���ַ����ַ��������֤�Ǳ�׼18λ���ɼ�Ϊ0��100֮���һ��������
���������Ӧ���Ҵ���ѧ����Ϣ(���� ѧ�� �ɼ� ����)(����ɼ�Ϊn/a����������Ϊn/a)����֮���ÿո������
ÿ��ѧ��һ�С����������ǰ��ճɼ��������е�����������ж��ѧ���ĳɼ���ͬ������Щѧ����������ͬ���������ļ���������������
���������Ķ��ѧ�����������˳�������*/

#include <stdio.h>
#include <string.h>

struct student {
	char name [ 11 ];
	char ID [ 19 ];
	int score;
	int rank;
} stu [ 10 ];

int main () {
	int n;
	char ch;
	char temp , temp1 , temp2;
	char name [ 11 ];
	int score;
	for ( int i = 0 ; i < 11 ; i++ ) {
		name [ i ] = '\0';
	}
	scanf ( "%d %s" , &n , name );
	getchar();
	score = 0;
	for ( int i = 0 ; i < strlen ( name ) ; i++ ) {
		if ( name [ i ] != '\0' ) {
			score *= 10;
			score += name [ i ] - 48;
		}
	}
	if ( name [ 0 ] == 'n' ) {
		score = -1;
	} else if ( score < 0 || score > 100 ) {
		score = -2;
	}
	for ( int i = 0 ; i < n ; i++ ) {
		for ( int j = 0 ; j < 11 ; j++ ) {
			stu [ i ] . name [ j ] = '\0';
		}
		for ( int j = 0 ; j < 19 ; j++ ) {
			stu [ i ] . ID [ j ] = '\0';
		}
		stu [ i ] . score = 0;
		stu [ i ] . rank = -1;
		//end initialize data
		ch = getchar();
		while ( ch == '\n' ) {
			ch = getchar();
		}//skip \n
		for ( int j = 0 ; ch != ' ' ; j++ ) {
			stu [ i ] . name [ j ] = ch;
			ch = getchar();
		}//input name
		while ( ch == ' ' ) {
			ch = getchar();
		}//skip ' '
		for ( int j = 0 ; ch != ' ' ; j++ ) {
			stu [ i ] . ID [ j ] = ch;
			ch = getchar();
		}//input ID
		while ( ch == ' ' ) {
			ch = getchar();
		}//skip ' '
		if ( ch == 'n' ) {
			stu [ i ] . score = -1;
			getchar();
			getchar();
			getchar();
			continue;
		}//score is n/a
		for ( int j = 0 ; ch != '\n' ; j++ ) {
			stu [ i ] . score *= 10;
			stu [ i ] . score += ch - 48;
			ch = getchar();
		}//input score
	}//end input data
	temp1 = 1;
	for ( int i = 100 ; i > -1 ; i-- ) {
		temp2 = 0;
		for ( int j = 0 ; j < n ; j++ ) {
			if ( stu [ j ] . score == i ) {
				stu [ j ] . rank = temp1;
				temp2++;
			}
		}
		temp1 += temp2;
	}//end entering rank
	for ( int i = 0 ; i < n ; i++ ) {
		for ( int j = 0 ; j < 11 - strlen ( name ) + 1 ; j++ ) {
			temp1 = 1;
			for ( int k = 0 ; k < strlen ( name ) ; k++ ) {
				if ( name [ k ] != stu [ i ] . name [ j + k ] ) {
					temp1 = 0;
				}
			}
			if ( temp1 ) {
				break;
			}
		}//find in name
		for ( int j = 0 ; j < 19 - strlen ( name ) + 1 ; j++ ) {
			temp2 = 1;
			for ( int k = 0 ; k < strlen ( name ) ; k++ ) {
				if ( name [ k ] != stu [ i ] . ID [ j + k ] ) {
					temp2 = 0;
				}
			}
			if ( temp2 ) {
				break;
			}
		}//find in ID
		if ( stu [ i ] . score == score ) {
			temp2 = 1;
		}
		if ( temp1 || temp2 ) {
			printf ( "%s %s " , stu [ i ] . name , stu [ i ] . ID );
			if ( stu [ i ] . score != -1 ) {
				printf ( "%d %d\n" , stu [ i ] . score , stu [ i ] . rank );
			} else {
				printf ("n/a n/a\n");
			}
		}
	}
	return 0;
}
