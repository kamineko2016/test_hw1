#include "gtest/gtest.h"
#include "hw1_Triangle.h"

namespace {



// boundary : {1,2,199,200}
// normal : {100}
// robust : {0,201}

TEST(normal_weak_value, boundary_test)
{
	//weak : only 1 value boundary
	EXPECT_EQ(2, triangle(100,100,1));
	EXPECT_EQ(2, triangle(100,100,2));
	EXPECT_EQ(1, triangle(100,100,100));
	EXPECT_EQ(2, triangle(100,100,199));
	EXPECT_EQ(4, triangle(100,100,200));
	
	EXPECT_EQ(2, triangle(100,1,100));
	EXPECT_EQ(2, triangle(100,2,100));
	EXPECT_EQ(1, triangle(100,100,100));
	EXPECT_EQ(2, triangle(100,199,100));
	EXPECT_EQ(4, triangle(100,200,100));
	
	EXPECT_EQ(2, triangle(1,100,100));
	EXPECT_EQ(2, triangle(2,100,100));
	EXPECT_EQ(1, triangle(100,100,100));
	EXPECT_EQ(2, triangle(199,100,100));
	EXPECT_EQ(4, triangle(200,100,100));
	
}

TEST(normal_strong_value, boundary_test)
{
	//strong : multiple value boundary
	EXPECT_EQ(1, triangle(1,1,1));
	EXPECT_EQ(4, triangle(1,1,2));
	EXPECT_EQ(4, triangle(1,1,100));
	EXPECT_EQ(4, triangle(1,1,199));
	EXPECT_EQ(4, triangle(1,1,200));
	EXPECT_EQ(4, triangle(1,2,1));
	EXPECT_EQ(2, triangle(1,2,2));
	EXPECT_EQ(4, triangle(1,2,100));
	EXPECT_EQ(4, triangle(1,2,199));
	EXPECT_EQ(4, triangle(1,2,200));
	EXPECT_EQ(4, triangle(1,100,1));
	EXPECT_EQ(4, triangle(1,100,2));
	EXPECT_EQ(2, triangle(1,100,100));
	EXPECT_EQ(4, triangle(1,100,199));
	EXPECT_EQ(4, triangle(1,100,200));
	EXPECT_EQ(4, triangle(1,199,1));
	EXPECT_EQ(4, triangle(1,199,2));
	EXPECT_EQ(4, triangle(1,199,100));
	EXPECT_EQ(2, triangle(1,199,199));
	EXPECT_EQ(4, triangle(1,199,200));
	EXPECT_EQ(4, triangle(1,200,1));
	EXPECT_EQ(4, triangle(1,200,2));
	EXPECT_EQ(4, triangle(1,200,100));
	EXPECT_EQ(4, triangle(1,200,199));
	EXPECT_EQ(2, triangle(1,200,200));
	
	EXPECT_EQ(4, triangle(2,1,1));
	EXPECT_EQ(2, triangle(2,1,2));
	EXPECT_EQ(4, triangle(2,1,100));
	EXPECT_EQ(4, triangle(2,1,199));
	EXPECT_EQ(4, triangle(2,1,200));
	EXPECT_EQ(2, triangle(2,2,1));
	EXPECT_EQ(1, triangle(2,2,2));
	EXPECT_EQ(4, triangle(2,2,100));
	EXPECT_EQ(4, triangle(2,2,199));
	EXPECT_EQ(4, triangle(2,2,200));
	EXPECT_EQ(4, triangle(2,100,1));
	EXPECT_EQ(4, triangle(2,100,2));
	EXPECT_EQ(2, triangle(2,100,100));
	EXPECT_EQ(4, triangle(2,100,199));
	EXPECT_EQ(4, triangle(2,100,200));
	EXPECT_EQ(4, triangle(2,199,1));
	EXPECT_EQ(4, triangle(2,199,2));
	EXPECT_EQ(4, triangle(2,199,100));
	EXPECT_EQ(2, triangle(2,199,199));
	EXPECT_EQ(3, triangle(2,199,200));
	EXPECT_EQ(4, triangle(2,200,1));
	EXPECT_EQ(4, triangle(2,200,2));
	EXPECT_EQ(4, triangle(2,200,100));
	EXPECT_EQ(3, triangle(2,200,199));
	EXPECT_EQ(2, triangle(2,200,200));
	
	EXPECT_EQ(4, triangle(100,1,1));
	EXPECT_EQ(4, triangle(100,1,2));
	EXPECT_EQ(2, triangle(100,1,100));
	EXPECT_EQ(4, triangle(100,1,199));
	EXPECT_EQ(4, triangle(100,1,200));
	EXPECT_EQ(4, triangle(100,2,1));
	EXPECT_EQ(4, triangle(100,2,2));
	EXPECT_EQ(2, triangle(100,2,100));
	EXPECT_EQ(4, triangle(100,2,199));
	EXPECT_EQ(4, triangle(100,2,200));
	EXPECT_EQ(2, triangle(100,100,1));
	EXPECT_EQ(2, triangle(100,100,2));
	EXPECT_EQ(1, triangle(100,100,100));
	EXPECT_EQ(2, triangle(100,100,199));
	EXPECT_EQ(4, triangle(100,100,200));
	EXPECT_EQ(4, triangle(100,199,1));
	EXPECT_EQ(4, triangle(100,199,2));
	EXPECT_EQ(2, triangle(100,199,100));
	EXPECT_EQ(2, triangle(100,199,199));
	EXPECT_EQ(3, triangle(100,199,200));
	EXPECT_EQ(4, triangle(100,200,1));
	EXPECT_EQ(4, triangle(100,200,2));
	EXPECT_EQ(4, triangle(100,200,100));
	EXPECT_EQ(3, triangle(100,200,199));
	EXPECT_EQ(2, triangle(100,200,200));
	
	EXPECT_EQ(4, triangle(199,1,1));
	EXPECT_EQ(4, triangle(199,1,2));
	EXPECT_EQ(4, triangle(199,1,100));
	EXPECT_EQ(2, triangle(199,1,199));
	EXPECT_EQ(4, triangle(199,1,200));
	EXPECT_EQ(4, triangle(199,2,1));
	EXPECT_EQ(4, triangle(199,2,2));
	EXPECT_EQ(4, triangle(199,2,100));
	EXPECT_EQ(2, triangle(199,2,199));
	EXPECT_EQ(3, triangle(199,2,200));
	EXPECT_EQ(4, triangle(199,100,1));
	EXPECT_EQ(4, triangle(199,100,2));
	EXPECT_EQ(2, triangle(199,100,100));
	EXPECT_EQ(2, triangle(199,100,199));
	EXPECT_EQ(3, triangle(199,100,200));
	EXPECT_EQ(2, triangle(199,199,1));
	EXPECT_EQ(2, triangle(199,199,2));
	EXPECT_EQ(2, triangle(199,199,100));
	EXPECT_EQ(1, triangle(199,199,199));
	EXPECT_EQ(2, triangle(199,199,200));
	EXPECT_EQ(4, triangle(199,200,1));
	EXPECT_EQ(3, triangle(199,200,2));
	EXPECT_EQ(3, triangle(199,200,100));
	EXPECT_EQ(2, triangle(199,200,199));
	EXPECT_EQ(2, triangle(199,200,200));
	
	EXPECT_EQ(4, triangle(200,1,1));
	EXPECT_EQ(4, triangle(200,1,2));
	EXPECT_EQ(4, triangle(200,1,100));
	EXPECT_EQ(4, triangle(200,1,199));
	EXPECT_EQ(2, triangle(200,1,200));
	EXPECT_EQ(4, triangle(200,2,1));
	EXPECT_EQ(4, triangle(200,2,2));
	EXPECT_EQ(4, triangle(200,2,100));
	EXPECT_EQ(3, triangle(200,2,199));
	EXPECT_EQ(2, triangle(200,2,200));
	EXPECT_EQ(4, triangle(200,100,1));
	EXPECT_EQ(4, triangle(200,100,2));
	EXPECT_EQ(4, triangle(200,100,100));
	EXPECT_EQ(3, triangle(200,100,199));
	EXPECT_EQ(2, triangle(200,100,200));
	EXPECT_EQ(4, triangle(200,199,1));
	EXPECT_EQ(3, triangle(200,199,2));
	EXPECT_EQ(3, triangle(200,199,100));
	EXPECT_EQ(2, triangle(200,199,199));
	EXPECT_EQ(2, triangle(200,199,200));
	EXPECT_EQ(2, triangle(200,200,1));
	EXPECT_EQ(2, triangle(200,200,2));
	EXPECT_EQ(2, triangle(200,200,100));
	EXPECT_EQ(2, triangle(200,200,199));
	EXPECT_EQ(1, triangle(200,200,200));
	
}

TEST(robust_weak_value, boundary_test)
{
	//weak : only 1 value boundary and robust
	EXPECT_EQ(7, triangle(100,100,0));
	EXPECT_EQ(2, triangle(100,100,1));
	EXPECT_EQ(2, triangle(100,100,2));
	EXPECT_EQ(1, triangle(100,100,100));
	EXPECT_EQ(2, triangle(100,100,199));
	EXPECT_EQ(4, triangle(100,100,200));
	EXPECT_EQ(7, triangle(100,100,201));
	
	EXPECT_EQ(6, triangle(100,0,100));
	EXPECT_EQ(2, triangle(100,1,100));
	EXPECT_EQ(2, triangle(100,2,100));
	EXPECT_EQ(1, triangle(100,100,100));
	EXPECT_EQ(2, triangle(100,199,100));
	EXPECT_EQ(4, triangle(100,200,100));
	EXPECT_EQ(6, triangle(100,201,100));
	
	EXPECT_EQ(5, triangle(0,100,100));
	EXPECT_EQ(2, triangle(1,100,100));
	EXPECT_EQ(2, triangle(2,100,100));
	EXPECT_EQ(1, triangle(100,100,100));
	EXPECT_EQ(2, triangle(199,100,100));
	EXPECT_EQ(4, triangle(200,100,100));
	EXPECT_EQ(5, triangle(201,100,100));
	
}

TEST(robust_strong_value, boundary_test)
{
	//strong : multiple value boundary and robust
	EXPECT_EQ(11, triangle(0,0,0));
	EXPECT_EQ(8, triangle(0,0,1));
	EXPECT_EQ(8, triangle(0,0,2));
	EXPECT_EQ(8, triangle(0,0,100));
	EXPECT_EQ(8, triangle(0,0,199));
	EXPECT_EQ(8, triangle(0,0,200));
	EXPECT_EQ(11, triangle(0,0,201));
	EXPECT_EQ(10, triangle(0,1,0));
	EXPECT_EQ(5, triangle(0,1,1));
	EXPECT_EQ(5, triangle(0,1,2));
	EXPECT_EQ(5, triangle(0,1,100));
	EXPECT_EQ(5, triangle(0,1,199));
	EXPECT_EQ(5, triangle(0,1,200));
	EXPECT_EQ(10, triangle(0,1,201));
	EXPECT_EQ(10, triangle(0,2,0));
	EXPECT_EQ(5, triangle(0,2,1));
	EXPECT_EQ(5, triangle(0,2,2));
	EXPECT_EQ(5, triangle(0,2,100));
	EXPECT_EQ(5, triangle(0,2,199));
	EXPECT_EQ(5, triangle(0,2,200));
	EXPECT_EQ(10, triangle(0,2,201));
	EXPECT_EQ(10, triangle(0,100,0));
	EXPECT_EQ(5, triangle(0,100,1));
	EXPECT_EQ(5, triangle(0,100,2));
	EXPECT_EQ(5, triangle(0,100,100));
	EXPECT_EQ(5, triangle(0,100,199));
	EXPECT_EQ(5, triangle(0,100,200));
	EXPECT_EQ(10, triangle(0,100,201));
	EXPECT_EQ(10, triangle(0,199,0));
	EXPECT_EQ(5, triangle(0,199,1));
	EXPECT_EQ(5, triangle(0,199,2));
	EXPECT_EQ(5, triangle(0,199,100));
	EXPECT_EQ(5, triangle(0,199,199));
	EXPECT_EQ(5, triangle(0,199,200));
	EXPECT_EQ(10, triangle(0,199,201));
	EXPECT_EQ(10, triangle(0,200,0));
	EXPECT_EQ(5, triangle(0,200,1));
	EXPECT_EQ(5, triangle(0,200,2));
	EXPECT_EQ(5, triangle(0,200,100));
	EXPECT_EQ(5, triangle(0,200,199));
	EXPECT_EQ(5, triangle(0,200,200));
	EXPECT_EQ(10, triangle(0,200,201));
	EXPECT_EQ(11, triangle(0,201,0));
	EXPECT_EQ(8, triangle(0,201,1));
	EXPECT_EQ(8, triangle(0,201,2));
	EXPECT_EQ(8, triangle(0,201,100));
	EXPECT_EQ(8, triangle(0,201,199));
	EXPECT_EQ(8, triangle(0,201,200));
	EXPECT_EQ(11, triangle(0,201,201));
	
	EXPECT_EQ(9, triangle(1,0,0));
	EXPECT_EQ(6, triangle(1,0,1));
	EXPECT_EQ(6, triangle(1,0,2));
	EXPECT_EQ(6, triangle(1,0,100));
	EXPECT_EQ(6, triangle(1,0,199));
	EXPECT_EQ(6, triangle(1,0,200));
	EXPECT_EQ(9, triangle(1,0,201));
	EXPECT_EQ(7, triangle(1,1,0));
	EXPECT_EQ(1, triangle(1,1,1));
	EXPECT_EQ(4, triangle(1,1,2));
	EXPECT_EQ(4, triangle(1,1,100));
	EXPECT_EQ(4, triangle(1,1,199));
	EXPECT_EQ(4, triangle(1,1,200));
	EXPECT_EQ(7, triangle(1,1,201));
	EXPECT_EQ(7, triangle(1,2,0));
	EXPECT_EQ(4, triangle(1,2,1));
	EXPECT_EQ(2, triangle(1,2,2));
	EXPECT_EQ(4, triangle(1,2,100));
	EXPECT_EQ(4, triangle(1,2,199));
	EXPECT_EQ(4, triangle(1,2,200));
	EXPECT_EQ(7, triangle(1,2,201));
	EXPECT_EQ(7, triangle(1,100,0));
	EXPECT_EQ(4, triangle(1,100,1));
	EXPECT_EQ(4, triangle(1,100,2));
	EXPECT_EQ(2, triangle(1,100,100));
	EXPECT_EQ(4, triangle(1,100,199));
	EXPECT_EQ(4, triangle(1,100,200));
	EXPECT_EQ(7, triangle(1,100,201));
	EXPECT_EQ(7, triangle(1,199,0));
	EXPECT_EQ(4, triangle(1,199,1));
	EXPECT_EQ(4, triangle(1,199,2));
	EXPECT_EQ(4, triangle(1,199,100));
	EXPECT_EQ(2, triangle(1,199,199));
	EXPECT_EQ(4, triangle(1,199,200));
	EXPECT_EQ(7, triangle(1,199,201));
	EXPECT_EQ(7, triangle(1,200,0));
	EXPECT_EQ(4, triangle(1,200,1));
	EXPECT_EQ(4, triangle(1,200,2));
	EXPECT_EQ(4, triangle(1,200,100));
	EXPECT_EQ(4, triangle(1,200,199));
	EXPECT_EQ(2, triangle(1,200,200));
	EXPECT_EQ(7, triangle(1,200,201));
	EXPECT_EQ(9, triangle(1,201,0));
	EXPECT_EQ(6, triangle(1,201,1));
	EXPECT_EQ(6, triangle(1,201,2));
	EXPECT_EQ(6, triangle(1,201,100));
	EXPECT_EQ(6, triangle(1,201,199));
	EXPECT_EQ(6, triangle(1,201,200));
	EXPECT_EQ(9, triangle(1,201,201));
	
	EXPECT_EQ(9, triangle(2,0,0));
	EXPECT_EQ(6, triangle(2,0,1));
	EXPECT_EQ(6, triangle(2,0,2));
	EXPECT_EQ(6, triangle(2,0,100));
	EXPECT_EQ(6, triangle(2,0,199));
	EXPECT_EQ(6, triangle(2,0,200));
	EXPECT_EQ(9, triangle(2,0,201));
	EXPECT_EQ(7, triangle(2,1,0));
	EXPECT_EQ(4, triangle(2,1,1));
	EXPECT_EQ(2, triangle(2,1,2));
	EXPECT_EQ(4, triangle(2,1,100));
	EXPECT_EQ(4, triangle(2,1,199));
	EXPECT_EQ(4, triangle(2,1,200));
	EXPECT_EQ(7, triangle(2,1,201));
	EXPECT_EQ(7, triangle(2,2,0));
	EXPECT_EQ(2, triangle(2,2,1));
	EXPECT_EQ(1, triangle(2,2,2));
	EXPECT_EQ(4, triangle(2,2,100));
	EXPECT_EQ(4, triangle(2,2,199));
	EXPECT_EQ(4, triangle(2,2,200));
	EXPECT_EQ(7, triangle(2,2,201));
	EXPECT_EQ(7, triangle(2,100,0));
	EXPECT_EQ(4, triangle(2,100,1));
	EXPECT_EQ(4, triangle(2,100,2));
	EXPECT_EQ(2, triangle(2,100,100));
	EXPECT_EQ(4, triangle(2,100,199));
	EXPECT_EQ(4, triangle(2,100,200));
	EXPECT_EQ(7, triangle(2,100,201));
	EXPECT_EQ(7, triangle(2,199,0));
	EXPECT_EQ(4, triangle(2,199,1));
	EXPECT_EQ(4, triangle(2,199,2));
	EXPECT_EQ(4, triangle(2,199,100));
	EXPECT_EQ(2, triangle(2,199,199));
	EXPECT_EQ(3, triangle(2,199,200));
	EXPECT_EQ(7, triangle(2,199,201));
	EXPECT_EQ(7, triangle(2,200,0));
	EXPECT_EQ(4, triangle(2,200,1));
	EXPECT_EQ(4, triangle(2,200,2));
	EXPECT_EQ(4, triangle(2,200,100));
	EXPECT_EQ(3, triangle(2,200,199));
	EXPECT_EQ(2, triangle(2,200,200));
	EXPECT_EQ(7, triangle(2,200,201));
	EXPECT_EQ(9, triangle(2,201,0));
	EXPECT_EQ(6, triangle(2,201,1));
	EXPECT_EQ(6, triangle(2,201,2));
	EXPECT_EQ(6, triangle(2,201,100));
	EXPECT_EQ(6, triangle(2,201,199));
	EXPECT_EQ(6, triangle(2,201,200));
	EXPECT_EQ(9, triangle(2,201,201));
	
	EXPECT_EQ(9, triangle(100,0,0));
	EXPECT_EQ(6, triangle(100,0,1));
	EXPECT_EQ(6, triangle(100,0,2));
	EXPECT_EQ(6, triangle(100,0,100));
	EXPECT_EQ(6, triangle(100,0,199));
	EXPECT_EQ(6, triangle(100,0,200));
	EXPECT_EQ(9, triangle(100,0,201));
	EXPECT_EQ(7, triangle(100,1,0));
	EXPECT_EQ(4, triangle(100,1,1));
	EXPECT_EQ(4, triangle(100,1,2));
	EXPECT_EQ(2, triangle(100,1,100));
	EXPECT_EQ(4, triangle(100,1,199));
	EXPECT_EQ(4, triangle(100,1,200));
	EXPECT_EQ(7, triangle(100,1,201));
	EXPECT_EQ(7, triangle(100,2,0));
	EXPECT_EQ(4, triangle(100,2,1));
	EXPECT_EQ(4, triangle(100,2,2));
	EXPECT_EQ(2, triangle(100,2,100));
	EXPECT_EQ(4, triangle(100,2,199));
	EXPECT_EQ(4, triangle(100,2,200));
	EXPECT_EQ(7, triangle(100,2,201));
	EXPECT_EQ(7, triangle(100,100,0));
	EXPECT_EQ(2, triangle(100,100,1));
	EXPECT_EQ(2, triangle(100,100,2));
	EXPECT_EQ(1, triangle(100,100,100));
	EXPECT_EQ(2, triangle(100,100,199));
	EXPECT_EQ(4, triangle(100,100,200));
	EXPECT_EQ(7, triangle(100,100,201));
	EXPECT_EQ(7, triangle(100,199,0));
	EXPECT_EQ(4, triangle(100,199,1));
	EXPECT_EQ(4, triangle(100,199,2));
	EXPECT_EQ(2, triangle(100,199,100));
	EXPECT_EQ(2, triangle(100,199,199));
	EXPECT_EQ(3, triangle(100,199,200));
	EXPECT_EQ(7, triangle(100,199,201));
	EXPECT_EQ(7, triangle(100,200,0));
	EXPECT_EQ(4, triangle(100,200,1));
	EXPECT_EQ(4, triangle(100,200,2));
	EXPECT_EQ(4, triangle(100,200,100));
	EXPECT_EQ(3, triangle(100,200,199));
	EXPECT_EQ(2, triangle(100,200,200));
	EXPECT_EQ(7, triangle(100,200,201));
	EXPECT_EQ(9, triangle(100,201,0));
	EXPECT_EQ(6, triangle(100,201,1));
	EXPECT_EQ(6, triangle(100,201,2));
	EXPECT_EQ(6, triangle(100,201,100));
	EXPECT_EQ(6, triangle(100,201,199));
	EXPECT_EQ(6, triangle(100,201,200));
	EXPECT_EQ(9, triangle(100,201,201));
	
	EXPECT_EQ(9, triangle(199,0,0));
	EXPECT_EQ(6, triangle(199,0,1));
	EXPECT_EQ(6, triangle(199,0,2));
	EXPECT_EQ(6, triangle(199,0,100));
	EXPECT_EQ(6, triangle(199,0,199));
	EXPECT_EQ(6, triangle(199,0,200));
	EXPECT_EQ(9, triangle(199,0,201));
	EXPECT_EQ(7, triangle(199,1,0));
	EXPECT_EQ(4, triangle(199,1,1));
	EXPECT_EQ(4, triangle(199,1,2));
	EXPECT_EQ(4, triangle(199,1,100));
	EXPECT_EQ(2, triangle(199,1,199));
	EXPECT_EQ(4, triangle(199,1,200));
	EXPECT_EQ(7, triangle(199,1,201));
	EXPECT_EQ(7, triangle(199,2,0));
	EXPECT_EQ(4, triangle(199,2,1));
	EXPECT_EQ(4, triangle(199,2,2));
	EXPECT_EQ(4, triangle(199,2,100));
	EXPECT_EQ(2, triangle(199,2,199));
	EXPECT_EQ(3, triangle(199,2,200));
	EXPECT_EQ(7, triangle(199,2,201));
	EXPECT_EQ(7, triangle(199,100,0));
	EXPECT_EQ(4, triangle(199,100,1));
	EXPECT_EQ(4, triangle(199,100,2));
	EXPECT_EQ(2, triangle(199,100,100));
	EXPECT_EQ(2, triangle(199,100,199));
	EXPECT_EQ(3, triangle(199,100,200));
	EXPECT_EQ(7, triangle(199,100,201));
	EXPECT_EQ(7, triangle(199,199,0));
	EXPECT_EQ(2, triangle(199,199,1));
	EXPECT_EQ(2, triangle(199,199,2));
	EXPECT_EQ(2, triangle(199,199,100));
	EXPECT_EQ(1, triangle(199,199,199));
	EXPECT_EQ(2, triangle(199,199,200));
	EXPECT_EQ(7, triangle(199,199,201));
	EXPECT_EQ(7, triangle(199,200,0));
	EXPECT_EQ(4, triangle(199,200,1));
	EXPECT_EQ(3, triangle(199,200,2));
	EXPECT_EQ(3, triangle(199,200,100));
	EXPECT_EQ(2, triangle(199,200,199));
	EXPECT_EQ(2, triangle(199,200,200));
	EXPECT_EQ(7, triangle(199,200,201));
	EXPECT_EQ(9, triangle(199,201,0));
	EXPECT_EQ(6, triangle(199,201,1));
	EXPECT_EQ(6, triangle(199,201,2));
	EXPECT_EQ(6, triangle(199,201,100));
	EXPECT_EQ(6, triangle(199,201,199));
	EXPECT_EQ(6, triangle(199,201,200));
	EXPECT_EQ(9, triangle(199,201,201));
	
	EXPECT_EQ(9, triangle(200,0,0));
	EXPECT_EQ(6, triangle(200,0,1));
	EXPECT_EQ(6, triangle(200,0,2));
	EXPECT_EQ(6, triangle(200,0,100));
	EXPECT_EQ(6, triangle(200,0,199));
	EXPECT_EQ(6, triangle(200,0,200));
	EXPECT_EQ(9, triangle(200,0,201));
	EXPECT_EQ(7, triangle(200,1,0));
	EXPECT_EQ(4, triangle(200,1,1));
	EXPECT_EQ(4, triangle(200,1,2));
	EXPECT_EQ(4, triangle(200,1,100));
	EXPECT_EQ(4, triangle(200,1,199));
	EXPECT_EQ(2, triangle(200,1,200));
	EXPECT_EQ(7, triangle(200,1,201));
	EXPECT_EQ(7, triangle(200,2,0));
	EXPECT_EQ(4, triangle(200,2,1));
	EXPECT_EQ(4, triangle(200,2,2));
	EXPECT_EQ(4, triangle(200,2,100));
	EXPECT_EQ(3, triangle(200,2,199));
	EXPECT_EQ(2, triangle(200,2,200));
	EXPECT_EQ(7, triangle(200,2,201));
	EXPECT_EQ(7, triangle(200,100,0));
	EXPECT_EQ(4, triangle(200,100,1));
	EXPECT_EQ(4, triangle(200,100,2));
	EXPECT_EQ(4, triangle(200,100,100));
	EXPECT_EQ(3, triangle(200,100,199));
	EXPECT_EQ(2, triangle(200,100,200));
	EXPECT_EQ(7, triangle(200,100,201));
	EXPECT_EQ(7, triangle(200,199,0));
	EXPECT_EQ(4, triangle(200,199,1));
	EXPECT_EQ(3, triangle(200,199,2));
	EXPECT_EQ(3, triangle(200,199,100));
	EXPECT_EQ(2, triangle(200,199,199));
	EXPECT_EQ(2, triangle(200,199,200));
	EXPECT_EQ(7, triangle(200,199,201));
	EXPECT_EQ(7, triangle(200,200,0));
	EXPECT_EQ(2, triangle(200,200,1));
	EXPECT_EQ(2, triangle(200,200,2));
	EXPECT_EQ(2, triangle(200,200,100));
	EXPECT_EQ(2, triangle(200,200,199));
	EXPECT_EQ(1, triangle(200,200,200));
	EXPECT_EQ(7, triangle(200,200,201));
	EXPECT_EQ(9, triangle(200,201,0));
	EXPECT_EQ(6, triangle(200,201,1));
	EXPECT_EQ(6, triangle(200,201,2));
	EXPECT_EQ(6, triangle(200,201,100));
	EXPECT_EQ(6, triangle(200,201,199));
	EXPECT_EQ(6, triangle(200,201,200));
	EXPECT_EQ(9, triangle(200,201,201));
	
	EXPECT_EQ(11, triangle(201,0,0));
	EXPECT_EQ(8, triangle(201,0,1));
	EXPECT_EQ(8, triangle(201,0,2));
	EXPECT_EQ(8, triangle(201,0,100));
	EXPECT_EQ(8, triangle(201,0,199));
	EXPECT_EQ(8, triangle(201,0,200));
	EXPECT_EQ(11, triangle(201,0,201));
	EXPECT_EQ(10, triangle(201,1,0));
	EXPECT_EQ(5, triangle(201,1,1));
	EXPECT_EQ(5, triangle(201,1,2));
	EXPECT_EQ(5, triangle(201,1,100));
	EXPECT_EQ(5, triangle(201,1,199));
	EXPECT_EQ(5, triangle(201,1,200));
	EXPECT_EQ(10, triangle(201,1,201));
	EXPECT_EQ(10, triangle(201,2,0));
	EXPECT_EQ(5, triangle(201,2,1));
	EXPECT_EQ(5, triangle(201,2,2));
	EXPECT_EQ(5, triangle(201,2,100));
	EXPECT_EQ(5, triangle(201,2,199));
	EXPECT_EQ(5, triangle(201,2,200));
	EXPECT_EQ(10, triangle(201,2,201));
	EXPECT_EQ(10, triangle(201,100,0));
	EXPECT_EQ(5, triangle(201,100,1));
	EXPECT_EQ(5, triangle(201,100,2));
	EXPECT_EQ(5, triangle(201,100,100));
	EXPECT_EQ(5, triangle(201,100,199));
	EXPECT_EQ(5, triangle(201,100,200));
	EXPECT_EQ(10, triangle(201,100,201));
	EXPECT_EQ(10, triangle(201,199,0));
	EXPECT_EQ(5, triangle(201,199,1));
	EXPECT_EQ(5, triangle(201,199,2));
	EXPECT_EQ(5, triangle(201,199,100));
	EXPECT_EQ(5, triangle(201,199,199));
	EXPECT_EQ(5, triangle(201,199,200));
	EXPECT_EQ(10, triangle(201,199,201));
	EXPECT_EQ(10, triangle(201,200,0));
	EXPECT_EQ(5, triangle(201,200,1));
	EXPECT_EQ(5, triangle(201,200,2));
	EXPECT_EQ(5, triangle(201,200,100));
	EXPECT_EQ(5, triangle(201,200,199));
	EXPECT_EQ(5, triangle(201,200,200));
	EXPECT_EQ(10, triangle(201,200,201));
	EXPECT_EQ(11, triangle(201,201,0));
	EXPECT_EQ(8, triangle(201,201,1));
	EXPECT_EQ(8, triangle(201,201,2));
	EXPECT_EQ(8, triangle(201,201,100));
	EXPECT_EQ(8, triangle(201,201,199));
	EXPECT_EQ(8, triangle(201,201,200));
	EXPECT_EQ(11, triangle(201,201,201));
	
}





// partition X : any value < 1
// partition Y1 : any value >= 1 and <= 100
// partition Y2 : any value >= 101 and <= 200
// partition Z : any value > 200

TEST(normal_weak_value, equivalence_test)
{
	
	EXPECT_EQ(1, triangle(50,50,50));
	
	EXPECT_EQ(4, triangle(50,150,50));
	
	EXPECT_EQ(2, triangle(150,50,150));
	
	EXPECT_EQ(1, triangle(150,150,150));
	
}

TEST(normal_strong_value, equivalence_test)
{
	// {50,150}
	EXPECT_EQ(1, triangle(50,50,50));
	
	EXPECT_EQ(4, triangle(50,50,150));
	EXPECT_EQ(4, triangle(50,150,50));
	EXPECT_EQ(4, triangle(150,50,50));
	
	EXPECT_EQ(2, triangle(50,150,150));
	EXPECT_EQ(2, triangle(150,50,150));
	EXPECT_EQ(2, triangle(150,150,50));
	
	EXPECT_EQ(1, triangle(150,150,150));
	
}

TEST(robust_weak_value, equivalence_test)
{
	
	// {-1,50,150,250}
	
	EXPECT_EQ(5, triangle(-1,50,50));
	EXPECT_EQ(5, triangle(-1,50,150));
	EXPECT_EQ(5, triangle(-1,150,50));
	EXPECT_EQ(5, triangle(-1,150,150));
	EXPECT_EQ(5, triangle(250,50,50));
	EXPECT_EQ(5, triangle(250,50,150));
	EXPECT_EQ(5, triangle(250,150,50));
	EXPECT_EQ(5, triangle(250,150,150));
	
	EXPECT_EQ(6, triangle(50,-1,50));
	EXPECT_EQ(6, triangle(50,-1,150));
	EXPECT_EQ(6, triangle(50,250,50));
	EXPECT_EQ(6, triangle(50,250,150));
	EXPECT_EQ(6, triangle(150,-1,50));
	EXPECT_EQ(6, triangle(150,-1,150));
	EXPECT_EQ(6, triangle(150,250,50));
	EXPECT_EQ(6, triangle(150,250,150));
	
	EXPECT_EQ(7, triangle(50,50,-1));
	EXPECT_EQ(7, triangle(50,50,250));
	EXPECT_EQ(7, triangle(50,150,-1));
	EXPECT_EQ(7, triangle(50,150,250));
	EXPECT_EQ(7, triangle(150,50,-1));
	EXPECT_EQ(7, triangle(150,50,250));
	EXPECT_EQ(7, triangle(150,150,-1));
	EXPECT_EQ(7, triangle(150,150,250));
	
}

TEST(robust_strong_value, equivalence_test)
{
	
	// {-1,50,150,250}
	
	EXPECT_EQ(11, triangle(-1,-1,-1));
	EXPECT_EQ(8, triangle(-1,-1,50));
	EXPECT_EQ(8, triangle(-1,-1,150));
	EXPECT_EQ(11, triangle(-1,-1,250));
	EXPECT_EQ(10, triangle(-1,50,-1));
	EXPECT_EQ(5, triangle(-1,50,50));
	EXPECT_EQ(5, triangle(-1,50,150));
	EXPECT_EQ(10, triangle(-1,50,250));
	EXPECT_EQ(10, triangle(-1,150,-1));
	EXPECT_EQ(5, triangle(-1,150,50));
	EXPECT_EQ(5, triangle(-1,150,150));
	EXPECT_EQ(10, triangle(-1,150,250));
	EXPECT_EQ(11, triangle(-1,250,-1));
	EXPECT_EQ(8, triangle(-1,250,50));
	EXPECT_EQ(8, triangle(-1,250,150));
	EXPECT_EQ(11, triangle(-1,250,250));
	
	EXPECT_EQ(9, triangle(50,-1,-1));
	EXPECT_EQ(6, triangle(50,-1,50));
	EXPECT_EQ(6, triangle(50,-1,150));
	EXPECT_EQ(9, triangle(50,-1,250));
	EXPECT_EQ(7, triangle(50,50,-1));
	EXPECT_EQ(1, triangle(50,50,50));
	EXPECT_EQ(4, triangle(50,50,150));
	EXPECT_EQ(7, triangle(50,50,250));
	EXPECT_EQ(7, triangle(50,150,-1));
	EXPECT_EQ(4, triangle(50,150,50));
	EXPECT_EQ(2, triangle(50,150,150));
	EXPECT_EQ(7, triangle(50,150,250));
	EXPECT_EQ(9, triangle(50,250,-1));
	EXPECT_EQ(6, triangle(50,250,50));
	EXPECT_EQ(6, triangle(50,250,150));
	EXPECT_EQ(9, triangle(50,250,250));
	
	EXPECT_EQ(9, triangle(150,-1,-1));
	EXPECT_EQ(6, triangle(150,-1,50));
	EXPECT_EQ(6, triangle(150,-1,150));
	EXPECT_EQ(9, triangle(150,-1,250));
	EXPECT_EQ(7, triangle(150,50,-1));
	EXPECT_EQ(4, triangle(150,50,50));
	EXPECT_EQ(2, triangle(150,50,150));
	EXPECT_EQ(7, triangle(150,50,250));
	EXPECT_EQ(7, triangle(150,150,-1));
	EXPECT_EQ(2, triangle(150,150,50));
	EXPECT_EQ(1, triangle(150,150,150));
	EXPECT_EQ(7, triangle(150,150,250));
	EXPECT_EQ(9, triangle(150,250,-1));
	EXPECT_EQ(6, triangle(150,250,50));
	EXPECT_EQ(6, triangle(150,250,150));
	EXPECT_EQ(9, triangle(150,250,250));
	
	EXPECT_EQ(11, triangle(250,-1,-1));
	EXPECT_EQ(8, triangle(250,-1,50));
	EXPECT_EQ(8, triangle(250,-1,150));
	EXPECT_EQ(11, triangle(250,-1,250));
	EXPECT_EQ(10, triangle(250,50,-1));
	EXPECT_EQ(5, triangle(250,50,50));
	EXPECT_EQ(5, triangle(250,50,150));
	EXPECT_EQ(10, triangle(250,50,250));
	EXPECT_EQ(10, triangle(250,150,-1));
	EXPECT_EQ(5, triangle(250,150,50));
	EXPECT_EQ(5, triangle(250,150,150));
	EXPECT_EQ(10, triangle(250,150,250));
	EXPECT_EQ(11, triangle(250,250,-1));
	EXPECT_EQ(8, triangle(250,250,50));
	EXPECT_EQ(8, triangle(250,250,150));
	EXPECT_EQ(11, triangle(250,250,250));
	
}





// edge X- : 0
// edge X : 1
// edge X+ : 2
// edge Y- : 99
// edge Y : 100
// edge Y+ : 101
// edge Z- : 199
// edge Z : 200
// edge Z+ : 201

TEST(normal_weak_value, edge_test)
{
	
	EXPECT_EQ(1, triangle(1,1,1));
	
	EXPECT_EQ(4, triangle(1,2,99));
	
	EXPECT_EQ(4, triangle(1,99,100));
	
	EXPECT_EQ(4, triangle(1,100,101));
	
	EXPECT_EQ(4, triangle(1,101,199));
	
	EXPECT_EQ(4, triangle(1,199,200));
	
	EXPECT_EQ(2, triangle(1,200,200));
	
}

TEST(normal_strong_value, edge_test)
{
	// {1,2,99,100,101,199,200}
	EXPECT_EQ(1, triangle(1,1,1));
	EXPECT_EQ(4, triangle(1,1,2));
	EXPECT_EQ(4, triangle(1,1,99));
	EXPECT_EQ(4, triangle(1,1,100));
	EXPECT_EQ(4, triangle(1,1,101));
	EXPECT_EQ(4, triangle(1,1,199));
	EXPECT_EQ(4, triangle(1,1,200));
	
	EXPECT_EQ(4, triangle(1,2,1));
	EXPECT_EQ(2, triangle(1,2,2));
	EXPECT_EQ(4, triangle(1,2,99));
	EXPECT_EQ(4, triangle(1,2,100));
	EXPECT_EQ(4, triangle(1,2,101));
	EXPECT_EQ(4, triangle(1,2,199));
	EXPECT_EQ(4, triangle(1,2,200));
	
	EXPECT_EQ(4, triangle(1,99,1));
	EXPECT_EQ(4, triangle(1,99,2));
	EXPECT_EQ(2, triangle(1,99,99));
	EXPECT_EQ(4, triangle(1,99,100));
	EXPECT_EQ(4, triangle(1,99,101));
	EXPECT_EQ(4, triangle(1,99,199));
	EXPECT_EQ(4, triangle(1,99,200));
	
	EXPECT_EQ(4, triangle(1,100,1));
	EXPECT_EQ(4, triangle(1,100,2));
	EXPECT_EQ(4, triangle(1,100,99));
	EXPECT_EQ(2, triangle(1,100,100));
	EXPECT_EQ(4, triangle(1,100,101));
	EXPECT_EQ(4, triangle(1,100,199));
	EXPECT_EQ(4, triangle(1,100,200));
	
	EXPECT_EQ(4, triangle(1,101,1));
	EXPECT_EQ(4, triangle(1,101,2));
	EXPECT_EQ(4, triangle(1,101,99));
	EXPECT_EQ(4, triangle(1,101,100));
	EXPECT_EQ(2, triangle(1,101,101));
	EXPECT_EQ(4, triangle(1,101,199));
	EXPECT_EQ(4, triangle(1,101,200));
	
	EXPECT_EQ(4, triangle(1,199,1));
	EXPECT_EQ(4, triangle(1,199,2));
	EXPECT_EQ(4, triangle(1,199,99));
	EXPECT_EQ(4, triangle(1,199,100));
	EXPECT_EQ(4, triangle(1,199,101));
	EXPECT_EQ(2, triangle(1,199,199));
	EXPECT_EQ(4, triangle(1,199,200));
	
	EXPECT_EQ(4, triangle(1,200,1));
	EXPECT_EQ(4, triangle(1,200,2));
	EXPECT_EQ(4, triangle(1,200,99));
	EXPECT_EQ(4, triangle(1,200,100));
	EXPECT_EQ(4, triangle(1,200,101));
	EXPECT_EQ(4, triangle(1,200,199));
	EXPECT_EQ(2, triangle(1,200,200));
	
	//剩下的排列組合太多 這裡省略
	
}

TEST(robust_weak_value, edge_test)
{
	
	EXPECT_EQ(9, triangle(1,0,0));
	
	EXPECT_EQ(4, triangle(1,1,2));
	
	EXPECT_EQ(4, triangle(1,2,99));
	
	EXPECT_EQ(4, triangle(1,99,100));
	
	EXPECT_EQ(4, triangle(1,100,101));
	
	EXPECT_EQ(4, triangle(1,101,199));
	
	EXPECT_EQ(4, triangle(1,199,200));
	
	EXPECT_EQ(7, triangle(1,200,201));
	
	EXPECT_EQ(9, triangle(1,201,201));
	
}

TEST(robust_strong_value, edge_test)
{
	
	// {0,1,2,99,100,101,199,200,201}
	EXPECT_EQ(9, triangle(1,0,0));
	EXPECT_EQ(6, triangle(1,0,1));
	EXPECT_EQ(6, triangle(1,0,2));
	EXPECT_EQ(6, triangle(1,0,99));
	EXPECT_EQ(6, triangle(1,0,100));
	EXPECT_EQ(6, triangle(1,0,101));
	EXPECT_EQ(6, triangle(1,0,199));
	EXPECT_EQ(6, triangle(1,0,200));
	EXPECT_EQ(9, triangle(1,0,201));
	
	EXPECT_EQ(7, triangle(1,1,0));
	EXPECT_EQ(1, triangle(1,1,1));
	EXPECT_EQ(4, triangle(1,1,2));
	EXPECT_EQ(4, triangle(1,1,99));
	EXPECT_EQ(4, triangle(1,1,100));
	EXPECT_EQ(4, triangle(1,1,101));
	EXPECT_EQ(4, triangle(1,1,199));
	EXPECT_EQ(4, triangle(1,1,200));
	EXPECT_EQ(7, triangle(1,1,201));
	
	EXPECT_EQ(7, triangle(1,2,0));
	EXPECT_EQ(4, triangle(1,2,1));
	EXPECT_EQ(2, triangle(1,2,2));
	EXPECT_EQ(4, triangle(1,2,99));
	EXPECT_EQ(4, triangle(1,2,100));
	EXPECT_EQ(4, triangle(1,2,101));
	EXPECT_EQ(4, triangle(1,2,199));
	EXPECT_EQ(4, triangle(1,2,200));
	EXPECT_EQ(7, triangle(1,2,201));
	
	EXPECT_EQ(7, triangle(1,99,0));
	EXPECT_EQ(4, triangle(1,99,1));
	EXPECT_EQ(4, triangle(1,99,2));
	EXPECT_EQ(2, triangle(1,99,99));
	EXPECT_EQ(4, triangle(1,99,100));
	EXPECT_EQ(4, triangle(1,99,101));
	EXPECT_EQ(4, triangle(1,99,199));
	EXPECT_EQ(4, triangle(1,99,200));
	EXPECT_EQ(7, triangle(1,99,201));
	
	EXPECT_EQ(7, triangle(1,100,0));
	EXPECT_EQ(4, triangle(1,100,1));
	EXPECT_EQ(4, triangle(1,100,2));
	EXPECT_EQ(4, triangle(1,100,99));
	EXPECT_EQ(2, triangle(1,100,100));
	EXPECT_EQ(4, triangle(1,100,101));
	EXPECT_EQ(4, triangle(1,100,199));
	EXPECT_EQ(4, triangle(1,100,200));
	EXPECT_EQ(7, triangle(1,100,201));
	
	EXPECT_EQ(7, triangle(1,101,0));
	EXPECT_EQ(4, triangle(1,101,1));
	EXPECT_EQ(4, triangle(1,101,2));
	EXPECT_EQ(4, triangle(1,101,99));
	EXPECT_EQ(4, triangle(1,101,100));
	EXPECT_EQ(2, triangle(1,101,101));
	EXPECT_EQ(4, triangle(1,101,199));
	EXPECT_EQ(4, triangle(1,101,200));
	EXPECT_EQ(7, triangle(1,101,201));
	
	EXPECT_EQ(7, triangle(1,199,0));
	EXPECT_EQ(4, triangle(1,199,1));
	EXPECT_EQ(4, triangle(1,199,2));
	EXPECT_EQ(4, triangle(1,199,99));
	EXPECT_EQ(4, triangle(1,199,100));
	EXPECT_EQ(4, triangle(1,199,101));
	EXPECT_EQ(2, triangle(1,199,199));
	EXPECT_EQ(4, triangle(1,199,200));
	EXPECT_EQ(7, triangle(1,199,201));
	
	EXPECT_EQ(7, triangle(1,200,0));
	EXPECT_EQ(4, triangle(1,200,1));
	EXPECT_EQ(4, triangle(1,200,2));
	EXPECT_EQ(4, triangle(1,200,99));
	EXPECT_EQ(4, triangle(1,200,100));
	EXPECT_EQ(4, triangle(1,200,101));
	EXPECT_EQ(4, triangle(1,200,199));
	EXPECT_EQ(2, triangle(1,200,200));
	EXPECT_EQ(7, triangle(1,200,201));
	
	EXPECT_EQ(9, triangle(1,201,0));
	EXPECT_EQ(6, triangle(1,201,1));
	EXPECT_EQ(6, triangle(1,201,2));
	EXPECT_EQ(6, triangle(1,201,99));
	EXPECT_EQ(6, triangle(1,201,100));
	EXPECT_EQ(6, triangle(1,201,101));
	EXPECT_EQ(6, triangle(1,201,199));
	EXPECT_EQ(6, triangle(1,201,200));
	EXPECT_EQ(9, triangle(1,201,201));
	
	//剩下的排列組合太多 這裡省略
	
}





// c1 : a<b+c
// c2 : b<a+c
// c3 : c<a+b
// c4 : a==b
// c5 : a==c
// c6 : b==c

TEST(rules, decision_table_test)
{
	//每個情況只取一條rule做為test case
	
	// c1 F
	EXPECT_EQ(4, triangle(100,5,3));
	
	// c1 T, c2 F
	EXPECT_EQ(4, triangle(5,100,3));
	
	// c1 T, c2 T, c3 F
	EXPECT_EQ(4, triangle(5,3,100));
	
	// c1 T, c2 T, c3 T, c4 T, c5 T, c6 T
	EXPECT_EQ(1, triangle(25,25,25));
	
	// c1 T, c2 T, c3 T, c4 T, c5 F, c6 F
	EXPECT_EQ(2, triangle(25,25,10));
	
	// c1 T, c2 T, c3 T, c4 F, c5 T, c6 F
	EXPECT_EQ(2, triangle(25,10,25));
	
	// c1 T, c2 T, c3 T, c4 F, c5 F, c6 T
	EXPECT_EQ(2, triangle(10,25,25));
	
	// c1 T, c2 T, c3 T, c4 F, c5 F, c6 F
	EXPECT_EQ(3, triangle(25,20,15));
	
}



}  // namespace

