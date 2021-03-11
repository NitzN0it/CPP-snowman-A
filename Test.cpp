/**
 * AUTHORS: Nitzan
 *
 * Date: 2021-03
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
#include <limits.h>
#include <array>

using namespace std;
const array<string,4> hats = {"_===_","  ___ \n.....", "  -\n  /_\\"," ---\n (_*_)"};
const array<string,4> eyes = {".","o","O","-"};
const array<string,4> nose = {",",".","_"," "};
const array<string,4> left_arm = {"<"," ","/"," "};
const array<string,4> right_arm = {">","/","\\"," "};
const array<string,4> torsos = {" : ", "] [","> <", "   "};
const array<string,4> bases = {" : ", "\" \"", "___","   "};
const int NUM_NUMBER = 8, HAT=0, NOSE=1,LEFT_EYE=2,RIGHT_EYE=3,LEFT_ARM=4,RIGHT_ARM=5,TORSO=6,BASE=7,MAX_SNOWMAN_SIZE=44444444,MIN_SNOWMAN_SIZE=11111111,NEXT_PART=10;
/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}
TEST_CASE("Input is too short and should throw an Invalid argument exception")
{
    CHECK_THROWS_AS(snowman(1), std::invalid_argument);
    CHECK_THROWS_AS(snowman(12), std::invalid_argument);
    CHECK_THROWS_AS(snowman(123), std::invalid_argument);
    CHECK_THROWS_AS(snowman(1234), std::invalid_argument);
    CHECK_THROWS_AS(snowman(12341), std::invalid_argument);
    CHECK_THROWS_AS(snowman(123412), std::invalid_argument);
    CHECK_THROWS_AS(snowman(1234123), std::invalid_argument);
}
TEST_CASE("Input is too long and should throw an Length error exception")
{
    CHECK_THROWS_AS(snowman(123412341),std::length_error);
    CHECK_THROWS_AS(snowman(1234123412),std::length_error);
}
TEST_CASE("Negative input and should throw an Invalid argument exception")
{
    CHECK_THROWS_AS(snowman(-11111111),std::invalid_argument);
    CHECK_THROWS_AS(snowman(-12341234),std::invalid_argument);
}
TEST_CASE("Unknown body part (not only 1-4 digits) and should throw an out of range exception")
{
    CHECK_THROWS_AS(snowman(12341235),std::out_of_range);
    CHECK_THROWS_AS(snowman(12341251),std::out_of_range);
    CHECK_THROWS_AS(snowman(12341512),std::out_of_range);
    CHECK_THROWS_AS(snowman(12345312),std::out_of_range);
    CHECK_THROWS_AS(snowman(12354312),std::out_of_range);
    CHECK_THROWS_AS(snowman(12534312),std::out_of_range);
    CHECK_THROWS_AS(snowman(15234312),std::out_of_range);
    CHECK_THROWS_AS(snowman(52234312),std::out_of_range);
}
TEST_CASE("Good snowman code") {
    for (int i = 0; i < 4; ++i) {
        CHECK(nospaces(snowman(MIN_SNOWMAN_SIZE+(i*10000000))) == nospaces(" "+hats[i]+"\n (.,.) \n<( : )>\n ( : )\n")); //hats
    }
    for (int i = 0; i < 4; ++i) {
        CHECK(nospaces(snowman(MIN_SNOWMAN_SIZE+(i*1000000))) == nospaces(" _===_\n (."+nose[i]+".) \n<( : )>\n ( : )\n")); //noses
    }
    for (int i = 0; i < 4; ++i) {
        CHECK(nospaces(snowman(MIN_SNOWMAN_SIZE+(i*100000))) == nospaces(" _===_\n ("+eyes[i]+",.) \n<( : )>\n ( : )\n")); //left eye
    }
    for (int i = 0; i < 4; ++i) {
        CHECK(nospaces(snowman(MIN_SNOWMAN_SIZE+(i*10000))) == nospaces(" _===_\n (.,"+eyes[i]+") \n<( : )>\n ( : )\n")); //right eye
    }

    for (int i = 0; i < 4; ++i) {
        if (i == 1)
            CHECK(nospaces(snowman(MIN_SNOWMAN_SIZE+(i*1000))) == nospaces(" _===_\n \\(.,.) \n( : )>\n ( : )\n")); //left arm up
        else
            CHECK(nospaces(snowman(MIN_SNOWMAN_SIZE+(i*1000))) == nospaces(" _===_\n (.,.) \n"+left_arm[i]+"( : )>\n ( : )\n")); //left arm

    }
    for (int i = 0; i < 4; ++i) {
        if (i == 1)
            CHECK(nospaces(snowman(MIN_SNOWMAN_SIZE+(i*100))) == nospaces(" _===_\n (.,.)/\n<( : )\n ( : )\n")); //right arm up
        else
            CHECK(nospaces(snowman(MIN_SNOWMAN_SIZE+(i*100))) == nospaces(" _===_\n (.,.)\n<( : )"+right_arm[i]+"\n ( : )\n")); //right arm

    }
    for (int i = 0; i < 4; ++i) {
        CHECK(nospaces(snowman(MIN_SNOWMAN_SIZE+(i*10))) == nospaces(" _===_\n (.,.) \n<("+torsos[i]+")>\n ( : )\n")); //torso
    }
    for (int i = 0; i < 4; ++i) {
        CHECK(nospaces(snowman(MIN_SNOWMAN_SIZE+i)) == nospaces(" _===_\n (.,.) \n<( : )>\n ("+bases[i]+")\n")); //base
    }
}

