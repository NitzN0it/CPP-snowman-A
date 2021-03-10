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
const array<string,4> hats = {"_===_"," ---\\n .....", "  -\\n  /_\\"," ---\\n (_*_)"};
const array<string,4> eyes = {".","o","O","-"};
const array<string,4> noses = {",",".","_"," "};
const array<string,4> left_arm = {"<","\\","/"," "};
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
        CHECK(snowman(MIN_SNOWMAN_SIZE*i*10000000) == " "+hats[i]+"\\n (.,.) \\n<( : )>\\n ( : )\\n"); //hats
    }
    for (int i = 0; i < 4; ++i) {
        CHECK(snowman(MIN_SNOWMAN_SIZE*i*1000000) == " _===_\\n (."+noses[i]+".) \\n<( : )>\\n ( : )\\n"); //noses
    }
    for (int i = 0; i < 4; ++i) {
        CHECK(snowman(MIN_SNOWMAN_SIZE*i*100000) == " _===_\\n ("+eyes[i]+",.) \\n<( : )>\\n ( : )\\n"); //left eye
    }
    for (int i = 0; i < 4; ++i) {
        CHECK(snowman(MIN_SNOWMAN_SIZE*i*10000) == " _===_\\n (.,"+eyes[i]+") \\n<( : )>\\n ( : )\\n"); //right eye
    }
    for (int i = 0; i < 4; ++i) {
        if (i < 3)
            CHECK(snowman(MIN_SNOWMAN_SIZE*i*1000) == " _===_\\n (.,.) \\n"+left_arm[i]+"( : )>\\n ( : )\\n"); //left arm
        else
            CHECK(snowman(MIN_SNOWMAN_SIZE*i*1000) == " _===_\\n \\(.,.) \\\n( : )>\\n ( : )\\n"); //left arm up

    }
    for (int i = 0; i < 4; ++i) {
        if (i < 3)
            CHECK(snowman(MIN_SNOWMAN_SIZE*i*1000) == " _===_\\n (.,"") \\n<( : )"+right_arm[i]+"\\n ( : )\\n"); //right arm
        else
            CHECK(snowman(MIN_SNOWMAN_SIZE*i*1000) == " _===_\\n \\(.,.)/\\\n<( : )\\n ( : )\\n"); //right arm up

    }
    for (int i = 0; i < 4; ++i) {
        CHECK(snowman(MIN_SNOWMAN_SIZE*i*10) == " _===_\n (.,.) \n<("+torsos[i]+")>\n ( : )\n"); //torso
    }
    for (int i = 0; i < 4; ++i) {
        CHECK(snowman(MIN_SNOWMAN_SIZE*i) == " _===_\n (.,.) \n<( : )>\n ("+bases[i]+")\n"); //base
    }
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\\n(.,.)\\n( : )\\n( : )"));
    CHECK(nospaces(snowman(33232124)) == nospaces("   _\\n  /_\\\\n\\(o_O)\\n (] [)>\\n (   )"));
    CHECK(nospaces(snowman(12222212)) == nospaces(" _===_\\n\\(o.o)/\\n ( : ) \\n (\" \")"));
    CHECK(nospaces(snowman(11111111)) == nospaces(" _===_ \\n (.,.) \\n<( : )>\\n ( : )"));
    CHECK(nospaces(snowman(22222222)) == nospaces("  ___  \\n ..... \\n\\(o.o)/\\n (] [) \\n (\" \")"));
    CHECK(nospaces(snowman(33333333)) == nospaces("   _   \\n  /_\\  \\n (O_O) \\n/(> <)\\\\n (___)"));
    CHECK(nospaces(snowman(44444444)) == nospaces("  ___  \\n (_*_) \\n (- -) \\n (   ) \\n (   )"));
}

