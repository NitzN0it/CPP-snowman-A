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
using namespace std;
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
TEST_CASE("Input is too short")
{
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(12));
    CHECK_THROWS(snowman(123));
    CHECK_THROWS(snowman(1234));
    CHECK_THROWS(snowman(12341));
    CHECK_THROWS(snowman(123412));
    CHECK_THROWS(snowman(1234123));
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
TEST_CASE("Input is too long")
{
    CHECK_THROWS(snowman(123412341));
    CHECK_THROWS(snowman(1234123412));
}
TEST_CASE("Input is too long and should throw an Length error exception")
{
    CHECK_THROWS_AS(snowman(123412341),std::length_error);
    CHECK_THROWS_AS(snowman(1234123412),std::length_error);
}
TEST_CASE("Negative input")
{
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(-12341234));
}
TEST_CASE("Negative input and should throw an Invalid argument exception")
{
    CHECK_THROWS_AS(snowman(-11111111),std::invalid_argument);
    CHECK_THROWS_AS(snowman(-12341234),std::invalid_argument);
}
TEST_CASE("Unknown body part (not only 1-4 digits)")
{
    CHECK_THROWS(snowman(55555555));
    CHECK_THROWS(snowman(12345678));
    CHECK_THROWS(snowman(87654321));
    CHECK_THROWS(snowman(12348432));
}
TEST_CASE("Unknown body part (not only 1-4 digits) and should throw an out of range exception")
{
    CHECK_THROWS_AS(snowman(55555555),std::out_of_range);
    CHECK_THROWS_AS(snowman(12345678),std::out_of_range);
    CHECK_THROWS_AS(snowman(87654321),std::out_of_range);
    CHECK_THROWS_AS(snowman(12348432),std::out_of_range);
}
TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(33232124)) == nospaces("   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )"));
    CHECK(nospaces(snowman(12222212)) == nospaces(" _===_\n\\(o.o)/\n ( : ) \n (\" \")"));
    CHECK(nospaces(snowman(11111111)) == nospaces(" _===_ \n (.,.) \n<( : )>\n ( : )"));
    CHECK(nospaces(snowman(22222222)) == nospaces("  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \")"));
    CHECK(nospaces(snowman(33333333)) == nospaces("   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___)"));
    CHECK(nospaces(snowman(44444444)) == nospaces("  ___  \n (_*_) \n (- -) \n (   ) \n (   )"));
}

