#include <stdio.h>
#include <string.h>



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
