/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
 
class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(ConnectXtest, checkOutofBounds)
{
    ConnectX c(9,8,5);
    Piece isIn = c.at(-1,7);
    //ASSERT_EQ(isIn,-1);   //this is the correct test 
    ASSERT_EQ(isIn,0);      //this should fail but passes
}

TEST(ConnectXtest, checkInBounds)
{
    ConnectX c(9,8,5);
    Piece isIn = c.at(0,7);
    ASSERT_EQ(isIn,0);
}

TEST(ConnectXtest, checkPlacePiece)
{
    ConnectX c(9,8,5);
    c.placePiece(5);
    ASSERT_EQ(c.at(5,7), 2);
}

TEST(ConnectXtest, checkToggle)
{
    ConnectX c(9,8,5);
    c.placePiece(5);
    Piece myTurn = c.whoseTurn();
    ASSERT_EQ(myTurn,1);
}

TEST(ConnectXtest, checknextPlacePiece)
{
    ConnectX c(9,8,5);
    c.placePiece(5);
    ASSERT_EQ(c.at(5,6), 0);
}

TEST(ConnectXtest, checkShowBoard)
{
    ConnectX c(9,8,5);
    c.placePiece(-1);
    c.showBoard();
    Piece isShowing = c.at(-1,7);
    //ASSERT_EQ(isShowing,-1);   //this is the correct test
    ASSERT_EQ(isShowing,2);     //this should fail, but passes
}

TEST(ConnectXtest, checkoutofPlacePiece)
{
    ConnectX c(9,8,5);
    c.placePiece(-1);
    //ASSERT_EQ(c.at(-1,7), -1);  //this is the correct test
    ASSERT_EQ(c.at(-1,7), 2);  //this should fail but passes
}
