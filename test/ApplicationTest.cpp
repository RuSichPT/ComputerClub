#include <gtest/gtest.h>
#include "../src/Application/Application.h"

using namespace std;

TEST(Application, shouldProperlyRun) {
    //given
    Application app("../../test_file.txt");
    string trueOutput = "09:00\n"
                        "08:48 1 client1\n"
                        "08:48 13 NotOpenYet\n"
                        "09:41 1 client1\n"
                        "09:48 1 client2\n"
                        "09:52 3 client1\n"
                        "09:52 13 ICanWaitNoLonger!\n"
                        "09:54 2 client1 1\n"
                        "10:25 2 client2 2\n"
                        "10:58 1 client3\n"
                        "10:59 2 client3 3\n"
                        "11:30 1 client4\n"
                        "11:35 2 client4 2\n"
                        "11:35 13 PlaceIsBusy\n"
                        "11:45 3 client4\n"
                        "12:33 4 client1\n"
                        "12:33 12 client4 1\n"
                        "12:43 4 client2\n"
                        "15:52 4 client4\n"
                        "19:00 11 client3\n"
                        "19:00\n"
                        "1 70 05:58\n"
                        "2 30 02:18\n"
                        "3 90 08:01\n";

    //when
    testing::internal::CaptureStdout();
    app.run();
    string output = testing::internal::GetCapturedStdout();

    //then
    EXPECT_EQ(output, trueOutput);
}
