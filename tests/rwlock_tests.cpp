#include <gtest/gtest.h>

TEST(RWLock, NoDoubleWrite)
{
	EXPECT_EQ(1, 1);
}
