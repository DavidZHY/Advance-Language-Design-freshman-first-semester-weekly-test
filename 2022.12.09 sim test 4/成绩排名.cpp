/*读入n名学生的姓名、身份证号、成绩，分别输出成绩最高和成绩最低学生的姓名和身份证号。注意：学生名单中可能缺考，没有成绩，表示为n/a.

输入
每个测试输入包含1个测试用例，格式为
正整数n
第1个学生的姓名 学号 成绩
第2个学生的姓名 学号 成绩
… … …
第n个学生的姓名 学号 成绩

其中1≤n≤100，姓名为不超过10个字符的字符串，身份证是标准18位，成绩为0到100之间的一个整数，字段之间用1个或多个空格隔开。
输入中至少有一位学生有成绩。

输出
对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，项与项之间有1个空格。
如果成绩最高的学生有多个，输出姓名字典序最小的那个，如果成绩最低的有多个，输出姓名字典序最大的那个。*/

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
