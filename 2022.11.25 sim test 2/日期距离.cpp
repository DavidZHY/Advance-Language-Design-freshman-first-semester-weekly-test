/*众所周知，日期有两种表示方法:MM/DD/YY或者YY/MM/DD.我们假设本题讨论的年份的格式都是20YY。

给你一个字符串，如果它只能代表一个合法的日期，满足MM/DD/YY的格式或者是YY/MM/DD的格式，那么输出 “month date,year”的格式（见第二个样例），
否则输出在这两种表示法下的日期差（见第一个样例）。

提示1：一年有12个月，分别是January, February, March, April, May, June, July, August, September, October, November 和 December。

提示2：注意闰年2月份有29天。闰年需要满足以下两个条件之一:

年份是400的倍数。
年份是4的倍数但年份不是100的倍数。


输入
一个时间字符串，格式为AA/BB/CC。保证AA/BB/CC至少满足两种表示法其中之一。*/

#include <stdio.h>

long days ( int year , int month , int day );
long mon ( int lunar , int month );
long ttmon ( int year , int month );
int lunar ( int year );
void prname ( int month );

void prname ( int month ) {
	switch ( month ) {
		case 1: {
			printf ("January");
			break;
		}
		case 2: {
			printf ("February");
			break;
		}
		case 3: {
			printf ("March");
			break;
		}
		case 4: {
			printf ("April");
			break;
		}
		case 5: {
			printf ("June");
			break;
		}
		case 7: {
			printf ("July");
			break;
		}
		case 8: {
			printf ("August");
			break;
		}
		case 9: {
			printf ("September");
			break;
		}
		case 10: {
			printf ("October");
			break;
		}
		case 11: {
			printf ("November");
			break;
		}
		case 12: {
			printf ("December");
			break;
		}
	}
} 

int lunar ( int year ) {
	int lunar = 0; 
	if ( year % 100 == 0 ) {
		if ( year % 400 == 0 ) {
			lunar = 1;
		}
	} else {
		if ( year % 4 == 0 ) {
			lunar = 1;
		}
	}
	return lunar;
}

long ttday ( int year , int month ) {
	int day = 0;
	for ( int i = 1 ; i < month ; i++ ) {
		day += mon ( lunar ( year ) , i );
	}
	return day;
}

long mon ( int lunar , int month ) {
	if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
		return 30;
	} else if ( month == 2 ) {
		return ( 28 + lunar );
	} else {
		return 31;
	}
}

long days ( int year , int month , int day ) {
	long days = 0;
	for ( int i = 0 ; i < year - 2000 ; i++ ) {
		days += ttday ( i + 2000 , 13 );
	}
	days += ttday ( year , month );
	days += day;
	return days;
}

int main () {
	char ch;
	int temp = 0;
	int year = 0 , month = 0 , day = 0;
	int year1 , month1 , day1;
	long count1 , count2;
	scanf ( "%d/%d/%d" , &year , &month , &day );
	//end input date year month day
	if ( year > 12 || year == month && month == day ) {
		year += 2000;
		prname ( month );
		printf ( " %d, %d" , day , year );
		return 0;
	}
	if ( month > 12 || day > 31 ) {
		temp = day;
		day = month;
		month = year;
		year = temp;
		if ( year < 2000 ) {
			year += 2000;
		}
		prname ( month );
		printf ( " %d, %d" , day , year );
		return 0;
	}
	month1 = year;
	day1 = month;
	year1 = day;
	year1 += 2000;
	year += 2000;
	count1 = days ( year , month , day );
	count2 = days ( year1 , month1 , day1 );
	if ( count1 <= count2 ) {
		printf ( "%ld" , count2 - count1 );
	} else {
		printf ( "%ld" , count1 - count2 );
	}
	return 0;
}
