#include "gtest/gtest.h"


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



namespace {



// boundary : L {-1,1,2,69,70} S {1,2,79,80} B {1,2,89,90}
// normal : {45}
// robust : L {0,71} S {0,81} B {0,91}

TEST(normal_weak_value, boundary_test)
{
	//weak : only 1 value boundary
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,45,45));
	EXPECT_DOUBLE_EQ(364.0,commission(1,45,45));
	EXPECT_DOUBLE_EQ(373.0,commission(2,45,45));
	EXPECT_DOUBLE_EQ(976.0,commission(69,45,45));
	EXPECT_DOUBLE_EQ(985.0,commission(70,45,45));
	
	EXPECT_DOUBLE_EQ(496.0,commission(45,1,45));
	EXPECT_DOUBLE_EQ(502.0,commission(45,2,45));
	EXPECT_DOUBLE_EQ(964.0,commission(45,79,45));
	EXPECT_DOUBLE_EQ(970.0,commission(45,80,45));
	
	EXPECT_DOUBLE_EQ(540.0,commission(45,45,1));
	EXPECT_DOUBLE_EQ(545.0,commission(45,45,2));
	EXPECT_DOUBLE_EQ(980.0,commission(45,45,89));
	EXPECT_DOUBLE_EQ(985.0,commission(45,45,90));
}

TEST(normal_strong_value, boundary_test)
{
	//strong : multiple value boundary
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,1,45));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,2,45));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,79,45));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,80,45));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,45,1));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,45,2));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,45,89));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,45,90));
	
	EXPECT_DOUBLE_EQ(130,commission(1,1,45));
	EXPECT_DOUBLE_EQ(134.5,commission(1,2,45));
	EXPECT_DOUBLE_EQ(568,commission(1,79,45));
	EXPECT_DOUBLE_EQ(574,commission(1,80,45));
	EXPECT_DOUBLE_EQ(163,commission(1,45,1));
	EXPECT_DOUBLE_EQ(166.75,commission(1,45,2));
	EXPECT_DOUBLE_EQ(584,commission(1,45,89));
	EXPECT_DOUBLE_EQ(589,commission(1,45,90));
	
	EXPECT_DOUBLE_EQ(136.75,commission(2,1,45));
	EXPECT_DOUBLE_EQ(141.25,commission(2,2,45));
	EXPECT_DOUBLE_EQ(577,commission(2,79,45));
	EXPECT_DOUBLE_EQ(583,commission(2,80,45));
	EXPECT_DOUBLE_EQ(169.75,commission(2,45,1));
	EXPECT_DOUBLE_EQ(173.5,commission(2,45,2));
	EXPECT_DOUBLE_EQ(593,commission(2,45,89));
	EXPECT_DOUBLE_EQ(598,commission(2,45,90));
	
	EXPECT_DOUBLE_EQ(712,commission(69,1,45));
	EXPECT_DOUBLE_EQ(718,commission(69,2,45));
	EXPECT_DOUBLE_EQ(1180,commission(69,79,45));
	EXPECT_DOUBLE_EQ(1186,commission(69,80,45));
	EXPECT_DOUBLE_EQ(756,commission(69,45,1));
	EXPECT_DOUBLE_EQ(761,commission(69,45,2));
	EXPECT_DOUBLE_EQ(1196,commission(69,45,89));
	EXPECT_DOUBLE_EQ(1201,commission(69,45,90));
	
	EXPECT_DOUBLE_EQ(721,commission(70,1,45));
	EXPECT_DOUBLE_EQ(727,commission(70,2,45));
	EXPECT_DOUBLE_EQ(1189,commission(70,79,45));
	EXPECT_DOUBLE_EQ(1195,commission(70,80,45));
	EXPECT_DOUBLE_EQ(765,commission(70,45,1));
	EXPECT_DOUBLE_EQ(770,commission(70,45,2));
	EXPECT_DOUBLE_EQ(1205,commission(70,45,89));
	EXPECT_DOUBLE_EQ(1210,commission(70,45,90));
	
}

TEST(robust_weak_value, boundary_test)
{
	//weak : only 1 value boundary and robust
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,45,45));
	EXPECT_DOUBLE_EQ(-2.0,commission(0,45,45));
	EXPECT_DOUBLE_EQ(364.0,commission(1,45,45));
	EXPECT_DOUBLE_EQ(373.0,commission(2,45,45));
	EXPECT_DOUBLE_EQ(976.0,commission(69,45,45));
	EXPECT_DOUBLE_EQ(985.0,commission(70,45,45));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,45,45));
	
	EXPECT_DOUBLE_EQ(-3.0,commission(45,0,45));
	EXPECT_DOUBLE_EQ(496.0,commission(45,1,45));
	EXPECT_DOUBLE_EQ(502.0,commission(45,2,45));
	EXPECT_DOUBLE_EQ(964.0,commission(45,79,45));
	EXPECT_DOUBLE_EQ(970.0,commission(45,80,45));
	EXPECT_DOUBLE_EQ(-3.0,commission(45,81,45));
	
	EXPECT_DOUBLE_EQ(-4.0,commission(45,45,0));
	EXPECT_DOUBLE_EQ(540.0,commission(45,45,1));
	EXPECT_DOUBLE_EQ(545.0,commission(45,45,2));
	EXPECT_DOUBLE_EQ(980.0,commission(45,45,89));
	EXPECT_DOUBLE_EQ(985.0,commission(45,45,90));
	EXPECT_DOUBLE_EQ(-4.0,commission(45,45,91));
	
	
}

TEST(robust_strong_value, boundary_test)
{
	//strong : multiple value boundary and robust
	EXPECT_DOUBLE_EQ(-5.0,commission(0,0,45));
	EXPECT_DOUBLE_EQ(-2.0,commission(0,1,45));
	EXPECT_DOUBLE_EQ(-2.0,commission(0,2,45));
	EXPECT_DOUBLE_EQ(-2.0,commission(0,79,45));
	EXPECT_DOUBLE_EQ(-2.0,commission(0,80,45));
	EXPECT_DOUBLE_EQ(-5.0,commission(0,81,45));
	
	EXPECT_DOUBLE_EQ(-6.0,commission(0,45,0));
	EXPECT_DOUBLE_EQ(-2.0,commission(0,45,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(0,45,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(0,45,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(0,45,90));
	EXPECT_DOUBLE_EQ(-6.0,commission(0,45,91));
	
	EXPECT_DOUBLE_EQ(-7.0,commission(45,0,0));
	EXPECT_DOUBLE_EQ(-4.0,commission(45,1,0));
	EXPECT_DOUBLE_EQ(-4.0,commission(45,2,0));
	EXPECT_DOUBLE_EQ(-4.0,commission(45,79,0));
	EXPECT_DOUBLE_EQ(-4.0,commission(45,80,0));
	EXPECT_DOUBLE_EQ(-7.0,commission(45,81,0));
	
	//剩下的排列組合太多 這裡省略
	
}





// partition L : >=1 and <=70
// partition S : >=1 and <=80
// partition B : >=1 and <=90
// partition L2 : -1

TEST(normal_weak_value, equivalence_test)
{
	
	EXPECT_DOUBLE_EQ(260.0,commission(20,20,20));
	
	EXPECT_DOUBLE_EQ(460.0,commission(20,20,60));
	
	EXPECT_DOUBLE_EQ(500.0,commission(20,60,20));
	
	EXPECT_DOUBLE_EQ(620.0,commission(60,20,20));
	
	EXPECT_DOUBLE_EQ(1060.0,commission(60,60,60));
	
}

TEST(normal_strong_value, equivalence_test)
{
	// L{-1,20,60} S{20,60} B{20,60}
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,20,20));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,20,60));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,60,20));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,60,60));
	
	EXPECT_DOUBLE_EQ(260.0,commission(20,20,20));
	EXPECT_DOUBLE_EQ(460.0,commission(20,20,60));
	EXPECT_DOUBLE_EQ(500.0,commission(20,60,20));
	EXPECT_DOUBLE_EQ(700.0,commission(20,60,60));
	
	EXPECT_DOUBLE_EQ(620.0,commission(60,20,20));
	EXPECT_DOUBLE_EQ(820.0,commission(60,20,60));
	EXPECT_DOUBLE_EQ(860.0,commission(60,60,20));
	EXPECT_DOUBLE_EQ(1060.0,commission(60,60,60));
	
}

TEST(robust_weak_value, equivalence_test)
{
	
	// L{-5,-1,45,100} S{-5,45,100} S{-5,45,100} but only one value robust
	EXPECT_DOUBLE_EQ(-2.0,commission(-5,45,45));
	
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,-5,45));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,45,-5));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,45,45));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,45,100));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,100,45));
	
	EXPECT_DOUBLE_EQ(-3.0,commission(45,-5,45));
	EXPECT_DOUBLE_EQ(-4.0,commission(45,45,-5));
	EXPECT_DOUBLE_EQ(760.0,commission(45,45,45));
	EXPECT_DOUBLE_EQ(-4.0,commission(45,45,100));
	EXPECT_DOUBLE_EQ(-3.0,commission(45,100,45));
	
	EXPECT_DOUBLE_EQ(-2.0,commission(100,45,45));
	
}

TEST(robust_strong_value, equivalence_test)
{
	
	// L{-5,-1,45,100} S{-5,45,100} S{-5,45,100}
	EXPECT_DOUBLE_EQ(-8.0,commission(-5,-5,-5));
	EXPECT_DOUBLE_EQ(-5.0,commission(-5,-5,45));
	EXPECT_DOUBLE_EQ(-8.0,commission(-5,-5,100));
	EXPECT_DOUBLE_EQ(-6.0,commission(-5,45,-5));
	EXPECT_DOUBLE_EQ(-2.0,commission(-5,45,45));
	EXPECT_DOUBLE_EQ(-6.0,commission(-5,45,100));
	EXPECT_DOUBLE_EQ(-8.0,commission(-5,100,-5));
	EXPECT_DOUBLE_EQ(-5.0,commission(-5,100,45));
	EXPECT_DOUBLE_EQ(-8.0,commission(-5,100,100));
	
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,-5,-5));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,-5,45));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,-5,100));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,45,-5));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,45,45));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,45,100));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,100,-5));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,100,45));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,100,100));
	
	EXPECT_DOUBLE_EQ(-7.0,commission(45,-5,-5));
	EXPECT_DOUBLE_EQ(-3.0,commission(45,-5,45));
	EXPECT_DOUBLE_EQ(-7.0,commission(45,-5,100));
	EXPECT_DOUBLE_EQ(-4.0,commission(45,45,-5));
	EXPECT_DOUBLE_EQ(760.0,commission(45,45,45));
	EXPECT_DOUBLE_EQ(-4.0,commission(45,45,100));
	EXPECT_DOUBLE_EQ(-7.0,commission(45,100,-5));
	EXPECT_DOUBLE_EQ(-3.0,commission(45,100,45));
	EXPECT_DOUBLE_EQ(-7.0,commission(45,100,100));
	
	EXPECT_DOUBLE_EQ(-8.0,commission(100,-5,-5));
	EXPECT_DOUBLE_EQ(-5.0,commission(100,-5,45));
	EXPECT_DOUBLE_EQ(-8.0,commission(100,-5,100));
	EXPECT_DOUBLE_EQ(-6.0,commission(100,45,-5));
	EXPECT_DOUBLE_EQ(-2.0,commission(100,45,45));
	EXPECT_DOUBLE_EQ(-6.0,commission(100,45,100));
	EXPECT_DOUBLE_EQ(-8.0,commission(100,100,-5));
	EXPECT_DOUBLE_EQ(-5.0,commission(100,100,45));
	EXPECT_DOUBLE_EQ(-8.0,commission(100,100,100));
	
}





// edge L- : 0
// edge L : 1
// edge L+ : 2
// edge S- : 0
// edge S : 1
// edge S+ : 2
// edge B- : 0
// edge B : 1
// edge B+ : 2

// edge L2- : 69
// edge L2 : 70
// edge L2+ : 71
// edge S2- : 79
// edge S2 : 80
// edge S2+ : 81
// edge B2- : 89
// edge B2 : 90
// edge B2+ : 91

// edge L3- : -2
// edge L3 : -1
// edge L3+ : 0

TEST(normal_weak_value, edge_test)
{
	// L{-1,1,2,69,70} S{1,2,79,80} S{1,2,89,90} 
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,1,1));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,1,2));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,1,89));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,1,90));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,80,1));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,80,2));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,80,89));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,80,90));
	
	EXPECT_DOUBLE_EQ(10.0,commission(1,1,1));
	EXPECT_DOUBLE_EQ(12.5,commission(1,1,2));
	EXPECT_DOUBLE_EQ(320.0,commission(1,1,89));
	EXPECT_DOUBLE_EQ(325.0,commission(1,1,90));
	EXPECT_DOUBLE_EQ(354.0,commission(1,80,1));
	EXPECT_DOUBLE_EQ(359.0,commission(1,80,2));
	EXPECT_DOUBLE_EQ(794.0,commission(1,80,89));
	EXPECT_DOUBLE_EQ(799.0,commission(1,80,90));
	
	EXPECT_DOUBLE_EQ(501.0,commission(70,1,1));
	EXPECT_DOUBLE_EQ(506.0,commission(70,1,2));
	EXPECT_DOUBLE_EQ(941.0,commission(70,1,89));
	EXPECT_DOUBLE_EQ(946.0,commission(70,1,90));
	EXPECT_DOUBLE_EQ(975.0,commission(70,80,1));
	EXPECT_DOUBLE_EQ(980.0,commission(70,80,2));
	EXPECT_DOUBLE_EQ(1415.0,commission(70,80,89));
	EXPECT_DOUBLE_EQ(1420.0,commission(70,80,90));
	
	//剩下的排列組合太多 這裡省略
}

TEST(normal_strong_value, edge_test)
{
	// L{-1,1,2,69,70} S{1,2,79,80} S{1,2,89,90}
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,1,1));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,1,2));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,1,89));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,1,90));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,2,1));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,2,2));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,2,89));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,2,90));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,79,1));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,79,2));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,79,89));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,79,90));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,80,1));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,80,2));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,80,89));
	EXPECT_DOUBLE_EQ(-1.0,commission(-1,80,90));
	
	EXPECT_DOUBLE_EQ(10.0,commission(1,1,1));
	EXPECT_DOUBLE_EQ(12.5,commission(1,1,2));
	EXPECT_DOUBLE_EQ(320.0,commission(1,1,89));
	EXPECT_DOUBLE_EQ(325.0,commission(1,1,90));
	EXPECT_DOUBLE_EQ(13.0,commission(1,2,1));
	EXPECT_DOUBLE_EQ(15.5,commission(1,2,2));
	EXPECT_DOUBLE_EQ(326.0,commission(1,2,89));
	EXPECT_DOUBLE_EQ(331.0,commission(1,2,90));
	EXPECT_DOUBLE_EQ(348.0,commission(1,79,1));
	EXPECT_DOUBLE_EQ(353.0,commission(1,79,2));
	EXPECT_DOUBLE_EQ(788.0,commission(1,79,89));
	EXPECT_DOUBLE_EQ(793.0,commission(1,79,90));
	EXPECT_DOUBLE_EQ(354.0,commission(1,80,1));
	EXPECT_DOUBLE_EQ(359.0,commission(1,80,2));
	EXPECT_DOUBLE_EQ(794.0,commission(1,80,89));
	EXPECT_DOUBLE_EQ(799.0,commission(1,80,90));
	
	EXPECT_DOUBLE_EQ(501.0,commission(70,1,1));
	EXPECT_DOUBLE_EQ(506.0,commission(70,1,2));
	EXPECT_DOUBLE_EQ(941.0,commission(70,1,89));
	EXPECT_DOUBLE_EQ(946.0,commission(70,1,90));
	EXPECT_DOUBLE_EQ(507.0,commission(70,2,1));
	EXPECT_DOUBLE_EQ(512.0,commission(70,2,2));
	EXPECT_DOUBLE_EQ(947.0,commission(70,2,89));
	EXPECT_DOUBLE_EQ(952.0,commission(70,2,90));
	EXPECT_DOUBLE_EQ(969.0,commission(70,79,1));
	EXPECT_DOUBLE_EQ(974.0,commission(70,79,2));
	EXPECT_DOUBLE_EQ(1409.0,commission(70,79,89));
	EXPECT_DOUBLE_EQ(1414.0,commission(70,79,90));
	EXPECT_DOUBLE_EQ(975.0,commission(70,80,1));
	EXPECT_DOUBLE_EQ(980.0,commission(70,80,2));
	EXPECT_DOUBLE_EQ(1415.0,commission(70,80,89));
	EXPECT_DOUBLE_EQ(1420.0,commission(70,80,90));
	
	
	//剩下的排列組合太多 這裡省略
	
}

TEST(robust_weak_value, edge_test)
{
	// L{-2,-1,0,1,2,69,70,71} S{0,1,2,79,80,81} S{0,1,2,89,90,91}
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,1,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,1,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,1,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,1,90));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,2,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,2,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,2,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,2,90));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,79,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,79,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,79,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,79,90));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,80,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,80,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,80,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,80,90));
	
	EXPECT_DOUBLE_EQ(-2.0,commission(71,1,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,1,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,1,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,1,90));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,2,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,2,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,2,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,2,90));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,79,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,79,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,79,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,79,90));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,80,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,80,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,80,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(71,80,90));
	
	//剩下的排列組合太多 這裡省略
	
}

TEST(robust_strong_value, edge_test)
{
	
	// L{-2,-1,0,1,2,69,70,71} S{0,1,2,79,80,81} S{0,1,2,89,90,91}
	
	EXPECT_DOUBLE_EQ(-8.0,commission(-2,0,0));
	EXPECT_DOUBLE_EQ(-5.0,commission(-2,0,1));
	EXPECT_DOUBLE_EQ(-5.0,commission(-2,0,2));
	EXPECT_DOUBLE_EQ(-5.0,commission(-2,0,89));
	EXPECT_DOUBLE_EQ(-5.0,commission(-2,0,90));
	EXPECT_DOUBLE_EQ(-8.0,commission(-2,0,91));
	EXPECT_DOUBLE_EQ(-6.0,commission(-2,1,0));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,1,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,1,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,1,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,1,90));
	EXPECT_DOUBLE_EQ(-6.0,commission(-2,1,91));
	EXPECT_DOUBLE_EQ(-6.0,commission(-2,2,0));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,2,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,2,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,2,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,2,90));
	EXPECT_DOUBLE_EQ(-6.0,commission(-2,2,91));
	EXPECT_DOUBLE_EQ(-6.0,commission(-2,79,0));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,79,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,79,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,79,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,79,90));
	EXPECT_DOUBLE_EQ(-6.0,commission(-2,79,91));
	EXPECT_DOUBLE_EQ(-6.0,commission(-2,80,0));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,80,1));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,80,2));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,80,89));
	EXPECT_DOUBLE_EQ(-2.0,commission(-2,80,90));
	EXPECT_DOUBLE_EQ(-6.0,commission(-2,80,91));
	EXPECT_DOUBLE_EQ(-8.0,commission(-2,81,0));
	EXPECT_DOUBLE_EQ(-5.0,commission(-2,81,1));
	EXPECT_DOUBLE_EQ(-5.0,commission(-2,81,2));
	EXPECT_DOUBLE_EQ(-5.0,commission(-2,81,89));
	EXPECT_DOUBLE_EQ(-5.0,commission(-2,81,90));
	EXPECT_DOUBLE_EQ(-8.0,commission(-2,81,91));
	
	
	//剩下的排列組合太多 這裡省略
	
}




/*
TEST(rules, decision_table_test)
{
	// NOT suitable for commission problem
	// the same test cases correspond to the equivalence classes
	
}
*/


}  // namespace

