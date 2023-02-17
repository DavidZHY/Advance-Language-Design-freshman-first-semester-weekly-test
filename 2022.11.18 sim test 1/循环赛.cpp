/*在某场赛事中，有n支队伍进行循环赛，即任意两支队之间都要进行一场比赛。名次在n/2(含)以内的队伍可以获奖。
名次按照积分和净得分从1开始依次往后排。
积分多的队伍名次靠前，如果积分相同，则净得分多的名次靠前，如果净得分仍然相同，则名次相同。
如果某个名次有多支队伍(例如x支)，则将跳过后续的x-1个名次再继续排名。
积分规则为：获胜一场积3分，平局积1分，输不积分。净得分为总得分-总失分。（3-1-0赛制） 

输入
第一行一个整数n(2<=n<=1000，n为偶数)，表示队伍数量；随后n行，每行表示一支队伍的名称(队名包含字母数字和空格这几种字符，长度不超过50个字符)；再随后n(n-1)/2行，每行的格式为name1-name2: score1-score2表示两队比赛得分。其中在“:”“-”前后可能存在若干空格。每场得分不超过100分。

输出
按名次从前到后输出获奖队伍的名称。名次相同的队伍，按队名字典序顺序输出。*/

#include <stdio.h>

#define N 500

int main () {
	int team [ 1001 ] [ N ] = { 0 };
	int match [ 2 ] [ N ] = { 0 };
	int n;
	int digit;
	int score1 , score2;
	char ch;
	int temp;
	scanf ( "%d\n" , &n );
	for ( int i = 0 ; i < n ; i++ ) {
		digit = 0;
		ch = getchar();
		while ( ch != '\n' ) {
			team [ i ] [ digit + 3 ] = ch;
			digit++;
			ch = getchar();
		}
		team [ i ] [ 2 ] = digit;
	}//end enter team name
	for ( int j = 0 ; j < ( n * ( n - 1 ) ) / 2 ; j++ ) {
		temp = 0;
		digit = 0;
		ch = getchar();
		while ( ch != '-' ) {
			if ( ch == ' ' ) {
				temp++;
			} else {
				temp = 0;
			}
			match [ 0 ] [ digit + 3 ] = ch;
			digit++;
			ch = getchar();
		}
		for ( int i = 0 ; i < temp + 1 ; i++ ) {
			match [ 0 ] [ digit - i + 3 ] = 0;
		}
		match [ 0 ] [ 2 ] = digit - temp;
		temp = 0;
		digit = 0;//enter name1
		while ( ch == ' ' || ch == '-' ) {
			ch = getchar();
		}//skip '-'
		while ( ch != ':' ) {
			if ( ch == ' ' ) {
				temp++;
			} else {
				temp = 0;
			}
			match [ 1 ] [ digit + 3 ] = ch;
			digit++;
			ch = getchar();
		}
		for ( int i = 0 ; i < temp + 1 ; i++ ) {
			match [ 1 ] [ digit - i + 3 ] = 0;
		}
		match [ 1 ] [ 2 ] = digit - temp;
		digit = 0;//enter name2
		score1 = 0;
		score2 = 0;
		while ( ch == ' ' || ch == ':' ) {
			ch = getchar();
		}//skip ':'
		score1 += ch - 48;
		ch = getchar();
		if ( ch >= '0' && ch <= '9' ) {
			score1 = score1 * 10 + ch - 48;
		}
		ch = getchar();
		while ( ch == ' ' || ch == '-' ) {
			ch = getchar();
		}//skip '-'
		score2 += ch - 48;
		ch = getchar();
		if ( ch >= '0' && ch <= '9' ) {
			score2 = score2 * 10 + ch - 48;
		}//end collect score
		if ( score1 < score2 ) {
			match [ 0 ] [ 0 ] = 0;
			match [ 1 ] [ 0 ] = 3;
			match [ 0 ] [ 1 ] = score1 - score2;
			match [ 1 ] [ 1 ] = score2 - score1;
		} else if ( score1 > score2 ) {
			match [ 0 ] [ 0 ] = 3;
			match [ 1 ] [ 0 ] = 0;
			match [ 0 ] [ 1 ] = score1 - score2;
			match [ 1 ] [ 1 ] = score2 - score1;
		} else {
			match [ 0 ] [ 0 ] = 1;
			match [ 1 ] [ 0 ] = 1;
			match [ 0 ] [ 1 ] = 0;
			match [ 1 ] [ 1 ] = 0;
		}//end allot data
		for ( int j = 0 ; j < n ; j++ ) {
			temp = 0;
			for ( int k = 3 ; k < N ; k++ ) {
				if ( team [ j ] [ k ] == match [ 0 ] [ k ] ) {
					
				} else {
					temp++;
				}
			}
			if ( temp == 0 ) {
				team [ j ] [ 0 ] += match [ 0 ] [ 0 ];
				team [ j ] [ 1 ] += match [ 0 ] [ 1 ];
				break;
			}
		}//upload data 1
		for ( int j = 0 ; j < n ; j++ ) {
			temp = 0;
			for ( int k = 3 ; k < N ; k++ ) {
				if ( team [ j ] [ k ] == match [ 1 ] [ k ] ) {
					
				} else {
					temp++;
				}
			}
			if ( temp == 0 ) {
				team [ j ] [ 0 ] += match [ 1 ] [ 0 ];
				team [ j ] [ 1 ] += match [ 1 ] [ 1 ];
				break;
			}
		}//upload data 2
		if ( ch != '\n' ) {
			ch = getchar();
		}
	}//end uploading data into team[][]
	for ( int i = 0 ; i < n ; i++ ) {//start requeuing
		for ( int j = 0 ; j < n - i - 1 ; j++ ) {
			if ( team [ j ] [ 0 ] < team [ j + 1 ] [ 0 ] || team [ j ] [ 0 ] == team [ j + 1 ] [ 0 ] && team [ j ] [ 1 ] < team [ j + 1 ] [ 1 ] ) {
				for ( int m = 0 ; m < N ; m++ ) {
					team [ 1000 ] [ m ] = team [ j ] [ m ];
					team [ j ] [ m ] = team [ j + 1 ] [ m ];
					team [ j + 1 ] [ m ] = team [ 1000 ] [ m ];
				}//orgnized by points
			} else if ( team [ j ] [ 0 ] == team [ j + 1 ] [ 0 ] && team [ j ] [ 1 ] == team [ j + 1 ] [ 1 ] ) {
				temp = 0;
					for ( int k = 0 ; k < team [ j ] [ 2 ] ; k++ ) {
						temp = team [ j ] [ k + 3 ] - team [ j + 1 ] [ k + 3 ];
						if ( temp != 0 ) {
							break;
						}
					}
					if ( temp > 0 ) {
						for ( int m = 0 ; m < N ; m++ ) {
							team [ 1000 ] [ m ] = team [ j ] [ m ];
							team [ j ] [ m ] = team [ j + 1 ] [ m ];
							team [ j + 1 ] [ m ] = team [ 1000 ] [ m ];
						}
					}
			}//organized by names
		}
	}
	for ( int i = 0 ; i < n / 2 ; i++ ) {
		for ( int j = 0 ; j < team [ i ] [ 2 ] ; j++ ) {
			printf ( "%c" , team [ i ] [ j + 3 ] ); 
		}
		printf ("\n");
	}
	for ( int i = n / 2 - 1 ; team [ i ] [ 0 ] == team [ i + 1 ] [ 0 ] && team [ i ] [ 1 ] == team [ i + 1 ] [ 1 ] ; i++ ) {
		for ( int j = 0 ; j < team [ i + 1 ] [ 2 ] ; j++ ) {
			printf ( "%c" , team [ i + 1 ] [ j + 3 ] ); 
		}
		printf ("\n");
	}//print out result
	return 0;
}
