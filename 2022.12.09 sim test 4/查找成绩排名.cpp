/*读入n名学生的姓名、身份证号、成绩。查找并输出匹配查找串的学生的姓名和学号和成绩。学生名单中可能缺考，没有成绩，表示为n/a。
如果查找串是针对姓名或者身份证号，则是模糊查找，即只要其中包含查找串(区分大小写)即算满足条件，如果查找串是针对成绩，则是精确查找。

输入
每个测试输入包含1个测试用例，格式为

正整数n 待查找串
第1个学生的姓名 学号 成绩
第2个学生的姓名 学号 成绩
… … …
第n个学生的姓名 学号 成绩

其中n≤10，姓名为不超过10个字符的字符串，身份证是标准18位，成绩为0到100之间的一个整数。
输出包含相应查找串的学生信息(姓名 学号 成绩 排名)(如果成绩为n/a，则排名就为n/a)，项之间用空格隔开。
每个学生一行。其中排名是按照成绩降序排列的排名。如果有多个学生的成绩相同，则这些学生的排名相同，并且随后的几个排名将跳过。
满足条件的多个学生按照输入的顺序输出。*/

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
