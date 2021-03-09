#include <iostream>
using namespace std;

#include "snowman.hpp"
#include <stdexcept>
#include <string>

   int validInput(int n){
        while (n>0)
        {
            int c = n%10;
            n = n/10;
            if (c < 1 || c > 4)
                return -1;
        }   
        return 1;
    }

namespace ariel {
	string snowman(int x) {
        if (x < 11111111 || x > 44444444)
        {
            throw std::out_of_range{"invalid input!!\n"};
        }
        if (validInput(x) == -1){
            throw std::out_of_range{"invalid input!!\n"};
        }
        return"_===_ \n(.,.)\n( : )\n( : )\n";

	}
}