int triangle(int a, int b, int c)
{
	//check input valid
	
	int a_valid = 0;
	int b_valid = 0;
	int c_valid = 0;
	
	if(a>=1 && a<=200)
	{
		a_valid = 1;
	}
	if(b>=1 && b<=200)
	{
		b_valid = 1;
	}
	if(c>=1 && c<=200)
	{
		c_valid = 1;
	}
	
	if(a_valid == 0)
	{
		if(b_valid == 0)
		{
			if(c_valid == 0)
			{
				return 11;
			}
			else
			{
				return 8;
			}
		}
		else
		{
			if(c_valid == 0)
			{
				return 10;
			}
			else
			{
				return 5;
			}
		}
	}
	else
	{
		if(b_valid == 0)
		{
			if(c_valid == 0)
			{
				return 9;
			}
			else
			{
				return 6;
			}
		}
		else
		{
			if(c_valid == 0)
			{
				return 7;
			}
			else
			{
				
			}
		}
	}
	
	
	//triangle
	
	if(a+b > c && a+c > b && b+c > a)
	{
		if(a == b && b == c && a == c)
		{
			return 1;
		}
		else if(a != b && b != c && a != c)
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 4;
	}
	
}


// return 1 -> 正三角形
// return 2 -> 等腰三角形
// return 3 -> 普通三角形
// return 4 -> 不是三角形

// return 5 -> invalid a
// return 6 -> invalid b
// return 7 -> invalid c

// return 8 -> invalid a,b
// return 9 -> invalid b,c
// return 10 -> invalid a,c

// return 11 -> invalid a,b,c

