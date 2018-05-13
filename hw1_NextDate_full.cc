#include <stdio.h>
#include <string.h>
#include "gtest/gtest.h"


int nextdate(int year, int month, int day)
{
	
	if(year < 1812 || year > 2012)
	{
		return 0;
	}
	
	if(month < 1 || month > 12)
	{
		return 0;
	}
	
	if(day < 1 || day > 31)
	{
		return 0;
	}
	
	int next_year = 0;
	int next_month = 0;
	int next_day = 0;
	
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
	{
		if(day < 31)
		{
			next_year = year;
			next_month = month;
			next_day = day + 1;
		}
		
		if(day == 31)
		{
			next_year = year;
			next_month = month + 1;
			next_day = 1;
		}
	}
	
	if(month == 4 || month == 6 || month == 9 || month == 11)
	{
		if(day < 30)
		{
			next_year = year;
			next_month = month;
			next_day = day + 1;
		}
		else if(day == 30)
		{
			next_year = year;
			next_month = month + 1;
			next_day = 1;
		}
		else
		{
			return 0;
		}
	}
	
	if(month == 12)
	{
		if(day < 31)
		{
			next_year = year;
			next_month = month;
			next_day = day + 1;
		}
		
		if(day == 31)
		{
			next_year = year + 1;
			next_month = 1;
			next_day = 1;
		}
	}
	
	if(month == 2)
	{
		if(day < 28)
		{
			next_year = year;
			next_month = month;
			next_day = day + 1;
		}
		else if(day == 28)
		{
			if(year % 4 == 0)
			{
				next_year = year;
				next_month = month;
				next_day = day + 1;
			}
			else
			{
				next_year = year;
				next_month = month + 1;
				next_day = 1;
			}
		}
		else if(day == 29)
		{
			if(year % 4 == 0)
			{
				next_year = year;
				next_month = month + 1;
				next_day = 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	
	
	return next_year*10000 + next_month*100 + next_day;
	
}


// return 0 : error input
// return date : correct




namespace {



// boundary : year{1812,2012} month{1,12} day{1,31}
// normal : year{2000} month{6} day{15}
// robust : year{1811,2013} month{0,13} day{0,32}

TEST(normal_weak_value, boundary_test)
{
	
	EXPECT_EQ(18120616, nextdate(1812,6,15));
	
	EXPECT_EQ(20000116, nextdate(2000,1,15));
	
	EXPECT_EQ(20000602, nextdate(2000,6,1));
	
	EXPECT_EQ(20000616, nextdate(2000,6,15));
	
	EXPECT_EQ(0, nextdate(2000,6,31));
	
	EXPECT_EQ(20001216, nextdate(2000,12,15));
	
	EXPECT_EQ(20120616, nextdate(2012,6,15));
	
}

TEST(normal_strong_value, boundary_test)
{
	
	EXPECT_EQ(18120102, nextdate(1812,1,1));
	EXPECT_EQ(18120116, nextdate(1812,1,15));
	EXPECT_EQ(18120201, nextdate(1812,1,31));
	
	EXPECT_EQ(18120602, nextdate(1812,6,1));
	EXPECT_EQ(18120616, nextdate(1812,6,15));
	EXPECT_EQ(0, nextdate(1812,6,31));
	
	EXPECT_EQ(18121202, nextdate(1812,12,1));
	EXPECT_EQ(18121216, nextdate(1812,12,15));
	EXPECT_EQ(18130101, nextdate(1812,12,31));
	
	EXPECT_EQ(20000102, nextdate(2000,1,1));
	EXPECT_EQ(20000116, nextdate(2000,1,15));
	EXPECT_EQ(20000201, nextdate(2000,1,31));
	
	EXPECT_EQ(20000602, nextdate(2000,6,1));
	EXPECT_EQ(20000616, nextdate(2000,6,15));
	EXPECT_EQ(0, nextdate(2000,6,31));
	
	EXPECT_EQ(20001202, nextdate(2000,12,1));
	EXPECT_EQ(20001216, nextdate(2000,12,15));
	EXPECT_EQ(20010101, nextdate(2000,12,31));
	
	EXPECT_EQ(20120102, nextdate(2012,1,1));
	EXPECT_EQ(20120116, nextdate(2012,1,15));
	EXPECT_EQ(20120201, nextdate(2012,1,31));
	
	EXPECT_EQ(20120602, nextdate(2012,6,1));
	EXPECT_EQ(20120616, nextdate(2012,6,15));
	EXPECT_EQ(0, nextdate(2012,6,31));
	
	EXPECT_EQ(20121202, nextdate(2012,12,1));
	EXPECT_EQ(20121216, nextdate(2012,12,15));
	EXPECT_EQ(20130101, nextdate(2012,12,31));
	
}

TEST(robust_weak_value, boundary_test)
{
	
	EXPECT_EQ(0, nextdate(1811,1,1));
	
	EXPECT_EQ(0, nextdate(1811,1,31));
	
	EXPECT_EQ(0, nextdate(1811,12,1));
	
	EXPECT_EQ(0, nextdate(1811,12,31));
	
}

TEST(robust_strong_value, boundary_test)
{
	
	EXPECT_EQ(0, nextdate(1811,0,0));
	EXPECT_EQ(0, nextdate(1811,0,1));
	EXPECT_EQ(0, nextdate(1811,0,31));
	EXPECT_EQ(0, nextdate(1811,0,32));
	
	EXPECT_EQ(0, nextdate(1811,1,0));
	EXPECT_EQ(0, nextdate(1811,1,1));
	EXPECT_EQ(0, nextdate(1811,1,31));
	EXPECT_EQ(0, nextdate(1811,1,32));
	
	EXPECT_EQ(0, nextdate(1811,12,0));
	EXPECT_EQ(0, nextdate(1811,12,1));
	EXPECT_EQ(0, nextdate(1811,12,31));
	EXPECT_EQ(0, nextdate(1811,12,32));
	
	EXPECT_EQ(0, nextdate(1811,13,0));
	EXPECT_EQ(0, nextdate(1811,13,1));
	EXPECT_EQ(0, nextdate(1811,13,31));
	EXPECT_EQ(0, nextdate(1811,13,32));
	
	//剩下的排列組合太多 這裡省略
	
}





// valid Y : value >= 1812 and <= 2012
// valid M : value >= 1 and <= 12
// valid D : value >= 1 and <= 31
// robust Y1 : value < 1812
// robust M1 : value < 1
// robust D1 : value < 1
// robust Y2 : value > 2012
// robust M2 : value > 12
// robust D2 : value < 31

TEST(normal_weak_value, equivalence_test)
{
	
	EXPECT_EQ(19500411, nextdate(1950,4,10));
	
	EXPECT_EQ(19500921, nextdate(1950,9,20));
	
	EXPECT_EQ(20000411, nextdate(2000,4,10));
	
	EXPECT_EQ(20000921, nextdate(2000,9,20));
	
}

TEST(normal_strong_value, equivalence_test)
{
	// Y{1950,2000} M{4,9} D{10,20}
	EXPECT_EQ(19500411, nextdate(1950,4,10));
	EXPECT_EQ(19500421, nextdate(1950,4,20));
	EXPECT_EQ(19500911, nextdate(1950,9,10));
	EXPECT_EQ(19500921, nextdate(1950,9,20));
	
	EXPECT_EQ(20000411, nextdate(2000,4,10));
	EXPECT_EQ(20000421, nextdate(2000,4,20));
	EXPECT_EQ(20000911, nextdate(2000,9,10));
	EXPECT_EQ(20000921, nextdate(2000,9,20));
	
}

TEST(robust_weak_value, equivalence_test)
{
	
	EXPECT_EQ(0, nextdate(1800,0,15));
	
	EXPECT_EQ(0, nextdate(1800,5,35));
	
	EXPECT_EQ(19500516, nextdate(1950,5,15));
	
	EXPECT_EQ(0, nextdate(1950,15,0));
	
	EXPECT_EQ(0, nextdate(2050,5,0));
	
	EXPECT_EQ(0, nextdate(2050,15,35));
	
}

TEST(robust_strong_value, equivalence_test)
{
	
	// Y{1800,1950,2050} M{0,5,15} D{0,15,35}
	EXPECT_EQ(0, nextdate(1800,0,0));
	EXPECT_EQ(0, nextdate(1800,0,15));
	EXPECT_EQ(0, nextdate(1800,0,35));
	EXPECT_EQ(0, nextdate(1800,5,0));
	EXPECT_EQ(0, nextdate(1800,5,15));
	EXPECT_EQ(0, nextdate(1800,5,35));
	EXPECT_EQ(0, nextdate(1800,15,0));
	EXPECT_EQ(0, nextdate(1800,15,15));
	EXPECT_EQ(0, nextdate(1800,15,35));
	
	EXPECT_EQ(0, nextdate(1950,0,0));
	EXPECT_EQ(0, nextdate(1950,0,15));
	EXPECT_EQ(0, nextdate(1950,0,35));
	EXPECT_EQ(0, nextdate(1950,5,0));
	EXPECT_EQ(19500516, nextdate(1950,5,15));
	EXPECT_EQ(0, nextdate(1950,5,35));
	EXPECT_EQ(0, nextdate(1950,15,0));
	EXPECT_EQ(0, nextdate(1950,15,15));
	EXPECT_EQ(0, nextdate(1950,15,35));
	
	EXPECT_EQ(0, nextdate(2050,0,0));
	EXPECT_EQ(0, nextdate(2050,0,15));
	EXPECT_EQ(0, nextdate(2050,0,35));
	EXPECT_EQ(0, nextdate(2050,5,0));
	EXPECT_EQ(0, nextdate(2050,5,15));
	EXPECT_EQ(0, nextdate(2050,5,35));
	EXPECT_EQ(0, nextdate(2050,15,0));
	EXPECT_EQ(0, nextdate(2050,15,15));
	EXPECT_EQ(0, nextdate(2050,15,35));
	
}





// edge Y1- : 1811
// edge Y1 : 1812
// edge Y1+ : 1813
// edge Y2- : 2011
// edge Y2 : 2012
// edge Y2+ : 2013
// edge M1- : 0
// edge M1 : 1
// edge M1+ : 2
// edge M2- : 11
// edge M2 : 12
// edge M2+ : 13
// edge D1- : 0
// edge D1 : 1
// edge D1+ : 2
// edge D2- : 30
// edge D2 : 31
// edge D2+ : 32

TEST(normal_weak_value, edge_test)
{
	
	EXPECT_EQ(18120102, nextdate(1812,1,1));
	
	EXPECT_EQ(18120203, nextdate(1812,2,2));
	
	EXPECT_EQ(18121201, nextdate(1812,11,30));
	
	EXPECT_EQ(18130101, nextdate(1812,12,31));
	
}

TEST(normal_strong_value, edge_test)
{
	
	// Y{1812,1813,2011,2012} M{1,2,11,12} D{1,2,30,31}
	EXPECT_EQ(18120102, nextdate(1812,1,1));
	EXPECT_EQ(18120103, nextdate(1812,1,2));
	EXPECT_EQ(18120131, nextdate(1812,1,30));
	EXPECT_EQ(18120201, nextdate(1812,1,31));
	
	EXPECT_EQ(18120202, nextdate(1812,2,1));
	EXPECT_EQ(18120203, nextdate(1812,2,2));
	EXPECT_EQ(0, nextdate(1812,2,30));
	EXPECT_EQ(0, nextdate(1812,2,31));
	
	EXPECT_EQ(18121102, nextdate(1812,11,1));
	EXPECT_EQ(18121103, nextdate(1812,11,2));
	EXPECT_EQ(18121201, nextdate(1812,11,30));
	EXPECT_EQ(0, nextdate(1812,11,31));
	
	EXPECT_EQ(18121202, nextdate(1812,12,1));
	EXPECT_EQ(18121203, nextdate(1812,12,2));
	EXPECT_EQ(18121231, nextdate(1812,12,30));
	EXPECT_EQ(18130101, nextdate(1812,12,31));
	
	//剩下的排列組合太多 這裡省略
	
}

TEST(robust_weak_value, edge_test)
{
	
	EXPECT_EQ(0, nextdate(1811,0,0));
	
	EXPECT_EQ(0, nextdate(1811,1,1));
	
	EXPECT_EQ(0, nextdate(1811,12,31));
	
	EXPECT_EQ(0, nextdate(1811,13,32));
	
}

TEST(robust_strong_value, edge_test)
{
	
	// Y{1811,1812,2012,2013} M{0,1,12,13} D{0,1,31,32}
	EXPECT_EQ(0, nextdate(1811,0,0));
	EXPECT_EQ(0, nextdate(1811,0,1));
	EXPECT_EQ(0, nextdate(1811,0,31));
	EXPECT_EQ(0, nextdate(1811,0,32));
	
	EXPECT_EQ(0, nextdate(1811,1,0));
	EXPECT_EQ(0, nextdate(1811,1,1));
	EXPECT_EQ(0, nextdate(1811,1,31));
	EXPECT_EQ(0, nextdate(1811,1,32));
	
	EXPECT_EQ(0, nextdate(1811,12,0));
	EXPECT_EQ(0, nextdate(1811,12,1));
	EXPECT_EQ(0, nextdate(1811,12,31));
	EXPECT_EQ(0, nextdate(1811,12,32));
	
	EXPECT_EQ(0, nextdate(1811,13,0));
	EXPECT_EQ(0, nextdate(1811,13,1));
	EXPECT_EQ(0, nextdate(1811,13,31));
	EXPECT_EQ(0, nextdate(1811,13,32));
	
	//剩下的排列組合太多 這裡省略
	
}





// M1 : 30day in month
// M2 : 31day in month except 12月
// M3 : 12月
// M4 : 2月
// D1 : day is 1~27
// D2 : day is 28
// D3 : day is 29
// D4 : day is 30
// D5 : day is 31
// Y1 : leap year
// Y2 : common year

TEST(rules, decision_table_test)
{
	
	EXPECT_EQ(20010416, nextdate(2001,4,15));
	
	EXPECT_EQ(20010501, nextdate(2001,4,30));
	
	EXPECT_EQ(0, nextdate(2001,4,31));
	
	EXPECT_EQ(20010116, nextdate(2001,1,15));
	
	EXPECT_EQ(20010201, nextdate(2001,1,31));
	
	EXPECT_EQ(20011216, nextdate(2001,12,15));
	
	EXPECT_EQ(20020101, nextdate(2001,12,31));
	
	EXPECT_EQ(20010216, nextdate(2001,2,15));
	
	EXPECT_EQ(20040229, nextdate(2004,2,28));
	
	EXPECT_EQ(20010301, nextdate(2001,2,28));
	
	EXPECT_EQ(20040301, nextdate(2004,2,29));
	
	EXPECT_EQ(0, nextdate(2001,2,29));
	
	EXPECT_EQ(0, nextdate(2001,2,30));
	
}



}  // namespace

