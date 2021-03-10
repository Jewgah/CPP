/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Jordan Perez>
 * 
 * Date: 2021-03
 */

//  Uncomment lines 16 and 17 when running only Test.cpp using:
//  clang++-9 -std=c++2a Test.cpp            Then        ./a.out 
//  (If uncomment, causes bug with command make test)
//  PS: Put the main in snowman.cpp in comments to do so
// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "snowman.cpp"

#include "doctest.h"
#include "snowman.hpp"
#include <stdexcept>
using namespace ariel;

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */

/*
*   Returns the input string without the whitespace characters: space, newline and tab.
*   I modified the previous code to work with C++11 compiler: hThere was an error with initial code, where erase wasn't recognized as a method from std
*/
string removespaces(string input)
{
    input.erase(remove(input.begin(),input.end(), ' '), input.end());
    input.erase(remove(input.begin(),input.end(), '\t'), input.end());
    input.erase(remove(input.begin(),input.end(), '\n'), input.end());
    input.erase(remove(input.begin(),input.end(), '\r'), input.end());
    return input;
}


//Input is like HNLRXYTB - Hats | Noses | Left Eyes | Right Eyes | Left Arms | Right Arms | Torsos | Bases

TEST_CASE("Working Inputs")
    {
        CHECK(removespaces(snowman(11114411)) == removespaces("_===_\n(.,.)\n( : )\n( : )"));
        CHECK(removespaces(snowman(11223344)) == removespaces("_===_\n(o,o)\n/(   )\\\n(   )"));
        CHECK(removespaces(snowman(34231234)) == removespaces("_\n/_\\\n(o O)/\n<(> <)\n(   )"));
        CHECK(removespaces(snowman(44332211)) == removespaces("___\n(_*_)\n\\(O O)/\n( : )\n( : )"));
        CHECK(removespaces(snowman(12232434)) == removespaces("_===_\n\\(o.O)\n(> <)\n(   )\n"));
         
    }

    TEST_CASE("Not Working Inputs")
{
    //Each digit must be between 1-4:
    CHECK_THROWS(snowman(91111111));
    CHECK_THROWS(snowman(19111111));
    CHECK_THROWS(snowman(11911111));
    CHECK_THROWS(snowman(11191111));
    CHECK_THROWS(snowman(11119111));
    CHECK_THROWS(snowman(11111911));
    CHECK_THROWS(snowman(11111191));
    CHECK_THROWS(snowman(11111119));


    //Check input length:
    CHECK_THROWS(snowman(1111111111));
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(-0));
    CHECK_THROWS(snowman(-26));
    CHECK_THROWS(snowman(16));
    CHECK_THROWS(snowman(11));
}

    
TEST_CASE("Checking Hats") // First digit
{   CHECK(removespaces(snowman(11114411)) == removespaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(removespaces(snowman(21114411)) == removespaces("___\n.....\n(.,.)\n( : )\n( : )"));
    CHECK(removespaces(snowman(31114411)) == removespaces("_\n/_\\\n(.,.)\n( : )\n( : )"));
    CHECK(removespaces(snowman(41114411)) == removespaces("___\n(_*_)\n(.,.)\n( : )\n( : )"));
}

//Noses Tests:
TEST_CASE("Checking Noses") // Second digit
{
    CHECK(removespaces(snowman(31114411)) == removespaces("_\n/_\\\n(.,.)\n( : )\n( : )"));
    CHECK(removespaces(snowman(32114411)) == removespaces("_\n/_\\\n(...)\n( : )\n( : )"));
    CHECK(removespaces(snowman(33114411)) == removespaces("_\n/_\\\n(._.)\n( : )\n( : )"));
    CHECK(removespaces(snowman(34114411)) == removespaces("_\n/_\\\n(. .)\n( : )\n( : )"));
}

//Left Eyes Tests:
TEST_CASE("Checking Left Eye") // Third digit
{
    CHECK(removespaces(snowman(31114411)) == removespaces("_\n/_\\\n(.,.)\n( : )\n( : )"));
    CHECK(removespaces(snowman(31214411)) == removespaces("_\n/_\\\n(o,.)\n( : )\n( : )"));
    CHECK(removespaces(snowman(31314411)) == removespaces("_\n/_\\\n(O,.)\n( : )\n( : )"));
    CHECK(removespaces(snowman(31414411)) == removespaces("_\n/_\\\n(-,.)\n( : )\n( : )"));
}

//Right Eyes Tests:
TEST_CASE("Checking Right Eye") // Fourth digit
{
    CHECK(removespaces(snowman(31114411)) == removespaces("_\n/_\\\n(.,.)\n( : )\n( : )"));
    CHECK(removespaces(snowman(31124411)) == removespaces("_\n/_\\\n(.,o)\n( : )\n( : )"));
    CHECK(removespaces(snowman(31134411)) == removespaces("_\n/_\\\n(.,O)\n( : )\n( : )"));
    CHECK(removespaces(snowman(31144411)) == removespaces("_\n/_\\\n(.,-)\n( : )\n( : )"));
}

//Left Arms Tests:
TEST_CASE("Checking Left Arm") // Fifth digit
{
    CHECK(removespaces(snowman(31111411)) == removespaces("_\n/_\\\n(.,.)\n<( : )\n( : )"));
    CHECK(removespaces(snowman(31112411)) == removespaces("_\n/_\\\n\\(.,.)\n( : )\n( : )"));
    CHECK(removespaces(snowman(31113411)) == removespaces("_\n/_\\\n(.,.)\n/( : )\n( : )"));
    CHECK(removespaces(snowman(31114411)) == removespaces("_\n/_\\\n(.,.)\n( : )\n( : )"));
}

//Right Arms Tests:
TEST_CASE("Checking Right Arm") // Sixth digit
{
    CHECK(removespaces(snowman(31114111)) == removespaces("_\n/_\\\n(.,.)\n( : )>\n( : )"));
    CHECK(removespaces(snowman(31114211)) == removespaces("_\n/_\\\n(.,.)/\n( : )\n( : )"));
    CHECK(removespaces(snowman(31114311)) == removespaces("_\n/_\\\n(.,.)\n( : )\\\n( : )"));
    CHECK(removespaces(snowman(31114411)) == removespaces("_\n/_\\\n(.,.)\n( : )\n( : )"));
}

//Torso Test:
TEST_CASE("Checking Torso") // Seventh digit
{
    CHECK(removespaces(snowman(31144411)) == removespaces("_\n/_\\\n(.,-)\n( : )\n( : )"));
    CHECK(removespaces(snowman(31144421)) == removespaces("_\n/_\\\n(.,-)\n(] [)\n( : )"));
    CHECK(removespaces(snowman(31144431)) == removespaces("_\n/_\\\n(.,-)\n(> <)\n( : )"));
    CHECK(removespaces(snowman(31144441)) == removespaces("_\n/_\\\n(.,-)\n(   )\n( : )"));
}

//Base Test:
TEST_CASE("Checking Base") // Eighth digit
{
    CHECK(removespaces(snowman(31144411)) == removespaces("_\n/_\\\n(.,-)\n( : )\n( : )"));
    CHECK(removespaces(snowman(31144412)) == removespaces("_\n/_\\\n(.,-)\n( : )\n(\" \")"));
    CHECK(removespaces(snowman(31144413)) == removespaces("_\n/_\\\n(.,-)\n( : )\n(___)"));
    CHECK(removespaces(snowman(31144414)) == removespaces("_\n/_\\\n(.,-)\n( : )\n(   )"));
}