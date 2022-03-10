//Evan Sinasac - 1081418
//INFO6025 Configuration and Deployment (Project 1)
//main.cpp description:
//					The purpose of Project 1 is to demonstrate an understanding of the GTest libraries, Unit Testing,
//					Test Fixtures, and Integration Testing.  Using the DumbCalculator dynamic library and the
//					SmarterCalculator static library, we will run 15 tests on them

#include <iostream>
#include <gtest/gtest.h>
#include "dumbCalculator.h"
#include "smarterCalculator.h"

//****************************************************
//DumbCalculatorTesting		- Test Suite 1
//****************************************************
//TestFixture for testing the DumbCalculator project
struct DumbCalculatorTestFixture : testing::Test
{
	dumbCalculator* calcu;
	DumbCalculatorTestFixture() {}
	virtual ~DumbCalculatorTestFixture() {}

	void SetUp()
	{
		calcu = new dumbCalculator();
	}

	virtual void TearDown()
	{
		delete calcu;
	}
};
//Testing the AddTwo function
TEST_F(DumbCalculatorTestFixture, TestAdd2)
{
	SetUp();
	EXPECT_EQ(calcu->AddTwo(1), 3);
}
//Testing the SubTwo function
TEST_F(DumbCalculatorTestFixture, TestSub2)
{
	SetUp();
	EXPECT_EQ(calcu->SubTwo(1), -1);
}
//Testing the FloatAdder function
TEST_F(DumbCalculatorTestFixture, TestFloatAdd)
{
	SetUp();
	EXPECT_FLOAT_EQ(calcu->FloatAdder(1.f, 3.f), 4.f);
}
//Testing the FloatSubtraction function
TEST_F(DumbCalculatorTestFixture, TestFloatSub)
{
	SetUp();
	EXPECT_FLOAT_EQ(calcu->FloatSubtraction(3.f, 1.f), 2);
}
//Testing passing the result from FloatSubtraction to FloatAdder
TEST_F(DumbCalculatorTestFixture, TestBothFloater)
{
	SetUp();
	EXPECT_FLOAT_EQ(calcu->FloatAdder(calcu->FloatSubtraction(4.f, 3.f), 2.f), 3.f);
}

//****************************************************
//SmarterCalculator Testing		- Test Suite 2
//****************************************************
//TestFixture for testing the SmarterCalculator project
struct SmarterCalculatorTestFixture : testing::Test
{
	smarterCalculator* lator;
	SmarterCalculatorTestFixture() {}
	virtual ~SmarterCalculatorTestFixture() {}

	void SetUp()
	{
		lator = new smarterCalculator();
	}

	virtual void TearDown()
	{
		delete lator;
	}
};
//Testing the DoubleIt function
TEST_F(SmarterCalculatorTestFixture, TestDouble)
{
	SetUp();
	EXPECT_EQ(lator->DoubleIt(2.f), 4.f);
}
//Testing the Multiplier function
TEST_F(SmarterCalculatorTestFixture, TestMultiplier)
{
	SetUp();
	EXPECT_FLOAT_EQ(lator->Multiplier(2.f, 2.f), 4.f);
}
//Testing the Square function
TEST_F(SmarterCalculatorTestFixture, TestSquare)
{
	SetUp();
	EXPECT_FLOAT_EQ(lator->Square(3.f), 9.f);
}
//A bad test of the HalveIt function
TEST(IntegrationTest, TestHalveBad)
{
	smarterCalculator* lator = new smarterCalculator();
	EXPECT_FLOAT_EQ(lator->HalveIt(2.00001f), 1.f);
}
//A bad test of the Divider function
TEST(IntegrationTest, TestDividerBad)
{
	smarterCalculator* lator = new smarterCalculator();
	EXPECT_FLOAT_EQ(lator->Divider(1.000001f, 0.01f), 100.f);
}

//****************************************************
//Combining Both Testing		- Test Suite 3
//****************************************************
//TestFixture for testing passing results between the dumbCalculator and the smarterCalculator
struct CombinedCalculatorTestFixture : testing::Test
{
	dumbCalculator* calcu;
	smarterCalculator* lator;
	CombinedCalculatorTestFixture() {}
	virtual ~CombinedCalculatorTestFixture() {}

	void SetUp()
	{
		calcu = new dumbCalculator();
		lator = new smarterCalculator();
	}

	virtual void TearDown()
	{
		delete calcu;
		delete lator;
	}
};
//Passing the result from AddTwo(dumbCalculator) to HalveIt(smarterCalculator)
TEST_F(CombinedCalculatorTestFixture, TestAddTwoHalve)
{
	SetUp();
	EXPECT_FLOAT_EQ(lator->HalveIt(calcu->AddTwo(3)), 2.5f);
}
//Passing the result from SubTwo(dumbCalculator) to DoubleIt(smarterCalculator)
TEST_F(CombinedCalculatorTestFixture, TestSubTwoDouble)
{
	SetUp();
	EXPECT_EQ(lator->DoubleIt(calcu->SubTwo(3)), 2.f);
}
//Passing the result from Square(smarterCalculator) twice to the FloatAdder(dumbCalculator)
TEST_F(CombinedCalculatorTestFixture, TestAddingSquares)
{
	SetUp();
	EXPECT_FLOAT_EQ(calcu->FloatAdder(lator->Square(3.f), lator->Square(4.f)), 25.f);
}
//Passing the results of AddTwo(dumbCalculator) and SubTwo(dumbCalculator) to Multiplier(smarterCalculator), 
//and the results of DoubleIt(smarterCalculator) to DoubleIt(smarterCalculator, then that result and the result from
//Multiplier to FloatSubtraction(dumbCalculator)
TEST_F(CombinedCalculatorTestFixture, TestUsingBothInBoth)
{
	SetUp();
	EXPECT_EQ(calcu->FloatSubtraction(lator->Multiplier(calcu->AddTwo(2), calcu->SubTwo(4)), lator->DoubleIt(lator->DoubleIt(0.5f))), ( (2+2)*(4-2) ) - ( 0.5f*2.f*2.f ));		//6.f
}
//An IntegrationTest of passing the result from FloatAdder(dumbCalculator) to Square (smarterCalculator)
TEST(IntegrationTest, TestSquaringAnAddition)
{
	dumbCalculator* calcu = new dumbCalculator();
	smarterCalculator* lator = new smarterCalculator();
	
	EXPECT_FLOAT_EQ(lator->Square(calcu->FloatAdder(2.f, 2.f)), 16.f);
}

//Main function just initializes the GoogleTest stuff and then runs all tests
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	std::system("pause");
	return 0;
}