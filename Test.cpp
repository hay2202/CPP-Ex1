/**
 * AUTHORS: Hay Asa
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
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


TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(11111111) == "_===_\n(.,.)\n<( : )>\n( : )");
	CHECK(snowman(44444444) == " ___\n(_*_)\n(- -)\n<(  )>\n(  )");
	CHECK(snowman(12224411) == "_===_\n(o.o)\n( : )\n( : )");
	CHECK(snowman(11114433) == "_===_\n(.,.)\n(> <)\n(___)");
	CHECK(snowman(11114421) == "_===_\n(.,.)\n(] [)\n( : )");
	CHECK(snowman(11112211) == "_===_\n'\'(.,.)/\n( : )\n( : )");
	CHECK(snowman(13344411) == "_===_\n(O_-)\n( : )\n( : )");
	CHECK(snowman(11114412) == "_===_\n(.,.)\n( : )\n(" ")");
	CHECK(snowman(11114442) == "_===_\n(.,.)\n(   )\n(" ")");
	CHECK(snowman(11114434) == "_===_\n(.,.)\n(> <)\n(  )");
	CHECK(snowman(14114411) == "_===_\n(. .)\n( : )\n( : )");
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));
	CHECK_THROWS(snowman(111111111));
	CHECK_THROWS(snowman(011111111));
	CHECK_THROWS(snowman(12345678));
	CHECK_THROWS(snowman(11023344));
	CHECK_THROWS(snowman(11111110));
	CHECK_THROWS(snowman(12345123));
	CHECK_THROWS(snowman(4444444));
    
}

