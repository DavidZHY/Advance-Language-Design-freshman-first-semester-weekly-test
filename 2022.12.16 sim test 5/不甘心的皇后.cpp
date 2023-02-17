/*皇后是国际象棋里最厉害的角色(so are women in real world)。
随着社会的不断发展，越来越多的人们意识到皇后在国际象棋里的地位应该降低,这样国际象棋才会更公平，更有意思。
在传统的棋盘上，皇后能在任意的方向(横,竖,斜)上移动任意的步数。 
新的国际象棋规定，皇后在竖直方向上还是可以移动任意的步数，但在除此之外的其他方向上（水平和对角），她只能像国王一样移动一格。
但皇后们并不罢休，即使他们被剥夺了的某些权利，她们也要想办法联合起来，即每个皇后都能被同伴支援保护。

在每个棋盘上，我们在每一列上放一个皇后。
正如前面所说，棋盘上所有的皇后都想要联合起来，
也就是说，每两个相邻列的皇后之间的行距离最多只能差一格，这样才可以及时互相支援(下图给出了四个例子，前三个是正确的，最后一个是错误的)。
现在我们给出棋盘的大小和初始状态，你能计算出一共有多少种不同的放置皇后的方法使得所有的皇后都能联合起来吗?

本题包括多组测试数据。每组数据的第一行包含一个整数n(1≤n≤10)，代表一个n*n的棋盘。接下来的一行包括n个整数。
代表初始时每列已有的皇后的位置：如果这个值为i，则代表在这一列上，由上向下数第i个格子已经放了皇后；
如果这个值为0，代表这一列还没有皇后，这时你可以在满足题目要求的情况下把一个皇后放在这一列的任意位置。
当n=0时输入结束，这组数据不包括在需要计算的数据中。

输出
对于每一组输入数据，输出一个整数，代表在这种情况下符合条件的放置皇后的方法种数。输出0代表无法满足条件。*/

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
