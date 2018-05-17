double commission(int sell_L, int sell_S, int sell_B)
{
	int price_L = 45;
	int price_S = 30;
	int price_B = 25;
	
	// sell_L 1~70
	// sell_S 1~80
	// sell_B 1~90
	
	// end
	if(sell_L == (-1))
	{
		return (-1.0);
	}
	
	// check
	if(sell_L >= 1 && sell_L <= 70)
	{
		if(sell_S >= 1 && sell_S <= 80)
		{
			if(sell_B >= 1 && sell_B <= 90)
			{
				
			}
			else
			{
				return (-4.0);
			}
		}
		else
		{
			if(sell_B >= 1 && sell_B <= 90)
			{
				return (-3.0);
			}
			else
			{
				return (-7.0);
			}
		}
	}
	else
	{
		if(sell_S >= 1 && sell_S <= 80)
		{
			if(sell_B >= 1 && sell_B <= 90)
			{
				return (-2.0);
			}
			else
			{
				return (-6.0);
			}
		}
		else
		{
			if(sell_B >= 1 && sell_B <= 90)
			{
				return (-5.0);
			}
			else
			{
				return (-8.0);
			}
		}
	}
	
	
	
	int sum = (sell_L * price_L) + (sell_S * price_S) + (sell_B * price_B);
	
	double money = 0.0;
	
	
	if(sum > 1800)
	{
		money = (1000*0.1) + (800*0.15) + (sum-1800)*0.2;
	}
	else if(sum <= 1800 && sum > 1000)
	{
		money = (1000*0.1) + (sum-1000)*0.15;
	}
	else if(sum <= 1000)
	{
		money = sum*0.1;
	}
	else
	{
		
	}
	
	return money;
	
}


// return -1.0 -> end

// return -2.0 -> sell_L invalid
// return -3.0 -> sell_S invalid
// return -4.0 -> sell_B invalid

// return -5.0 -> sell_L sell_S invalid
// return -6.0 -> sell_L sell_B invalid
// return -7.0 -> sell_S sell_B invalid

// return -8.0 -> sell_L sell_S sell_B invalid
