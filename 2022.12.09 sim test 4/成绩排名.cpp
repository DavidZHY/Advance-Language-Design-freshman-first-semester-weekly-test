/*����n��ѧ�������������֤�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ�������������֤�š�ע�⣺ѧ�������п���ȱ����û�гɼ�����ʾΪn/a.

����
ÿ�������������1��������������ʽΪ
������n
��1��ѧ�������� ѧ�� �ɼ�
��2��ѧ�������� ѧ�� �ɼ�
�� �� ��
��n��ѧ�������� ѧ�� �ɼ�

����1��n��100������Ϊ������10���ַ����ַ��������֤�Ǳ�׼18λ���ɼ�Ϊ0��100֮���һ���������ֶ�֮����1�������ո������
������������һλѧ���гɼ���

���
��ÿ�������������2�У���1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ�������֮����1���ո�
����ɼ���ߵ�ѧ���ж������������ֵ�����С���Ǹ�������ɼ���͵��ж������������ֵ��������Ǹ���*/

#include <stdio.h>
#include <string.h>

struct student {
	char name [ 11 ];
	char ID [ 19 ];
	int score;
} stu [ 100 ];

int main () {
	int n;
	char ch;
	char temp;
	int scoremax , scoremin;
	int nummax , nummin;
	char max [ 100 ] [ 30 ] = { 0 };
	char min [ 100 ] [ 30 ] = { 0 };
	scanf ( "%d" , &n );
	getchar();
	for ( int i = 0 ; i < n ; i++ ) {
		for ( int j = 0 ; j < 11 ; j++ ) {
			stu [ i ] . name [ j ] = '\0';
		}
		for ( int j = 0 ; j < 19 ; j++ ) {
			stu [ i ] . ID [ j ] = '\0';
		}
		stu [ i ] . score = 0;
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
			continue;
		}//score is n/a
		for ( int j = 0 ; ch != '\n' ; j++ ) {
			stu [ i ] . score *= 10;
			stu [ i ] . score += ch - 48;
			ch = getchar();
		}//input score
	}//end input data
	scoremax = 0;
	scoremin = 100;
	for ( int i = 0 ; i < n ; i++ ) {
		if ( stu [ i ] . score != -1 ) {
			if ( stu [ i ] . score > scoremax ) {
				scoremax = stu [ i ] . score;
			}
			if ( stu [ i ] . score < scoremin ) {
				scoremin = stu [ i ] . score;
			}
		}
	}//get max & min score
	nummax = 0;
	nummin = 0;
	for ( int i = 0 ; i < n ; i++ ) {
		if ( stu [ i ] . score == scoremax ) {
			for ( int j = 0 ; j < strlen ( stu [ i ] . name ) ; j++ ) {
				max [ nummax ] [ j ] = stu [ i ] . name [ j ];
			}
			max [ nummax ] [ strlen ( stu [ i ] . name ) ] = ' ';
			for ( int j = 0 ; j < 18 ; j++ ) {
				max [ nummax ] [ j + 1 + strlen ( stu [ i ] . name ) ] = stu [ i ] . ID [ j ];
			}
			max [ nummax ] [ 19 + strlen ( stu [ i ] . name ) ] = '\0';
			nummax++;
		}
	}//get max score
	for ( int i = 0 ; i < n ; i++ ) {
		if ( stu [ i ] . score == scoremin ) {
			for ( int j = 0 ; j < strlen ( stu [ i ] . name ) ; j++ ) {
				min [ nummin ] [ j ] = stu [ i ] . name [ j ];
			}
			min [ nummin ] [ strlen ( stu [ i ] . name ) ] = ' ';
			for ( int j = 0 ; j < 18 ; j++ ) {
				min [ nummin ] [ j + 1 + strlen ( stu [ i ] . name ) ] = stu [ i ] . ID [ j ];
			}
			min [ nummin ] [ 19 + strlen ( stu [ i ] . name ) ] = '\0';
			nummin++;
		}
	}//get min score
	for ( int i = 0 ; i < nummax ; i++ ) {
		for ( int j = 0 ; j < nummax - i - 1 ; j++ ) {
			if ( strcmp ( max [ j ] , max [ j + 1 ] ) > 0 ) {
				for ( int k = 0 ; k < 30 ; k++ ) {
					temp = max [ j ] [ k ];
					max [ j ] [ k ] = max [ j + 1 ] [ k ];
					max [ j + 1 ] [ k ] = temp;
				}
			}
		}
	}//requeue max array
	for ( int i = 0 ; i < nummin ; i++ ) {
		for ( int j = 0 ; j < nummin - i - 1 ; j++ ) {
			if ( strcmp ( min [ j ] , min [ j + 1 ] ) < 0 ) {
				for ( int k = 0 ; k < 30 ; k++ ) {
					temp = min [ j ] [ k ];
					min [ j ] [ k ] = min [ j + 1 ] [ k ];
					min [ j + 1 ] [ k ] = temp;
				}
			}
		}
	}//requeue min array
	printf ( "%s\n" , max [ 0 ] );
	printf ( "%s" , min [ 0 ] );
	return 0;
} 
