#include <iostream>
using namespace std;

#include "snowman.hpp"
#include <stdexcept>
#include <string>

namespace ariel {
	string snowman(int x) {
        if (x < 11111111 || x > 44444444)
        {
            throw std::out_of_range{"x must be in the range"};
        }
        
        return"_===_ \n(.,.)\n( : )\n( : )\n";

	}
}