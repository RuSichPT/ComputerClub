#include <gtest/gtest.h>
#include "../src/Time/Time.h"

TEST(TimeTest, shouldProperlySubtract) {
    //given
    Time time1(14, 55);
    Time time2(15, 10);
    Time time3(0, 15);

    //when
    Time time = time2 - time1;

    //then
    EXPECT_EQ(time, time3);
}

TEST(TimeTest, shouldProperlySum) {
    //given
    Time time1(14, 55);
    Time time2(15, 10);
    Time time3(6, 5);

    //when
    Time time = time2 + time1;

    //then
    EXPECT_EQ(time, time3);
}