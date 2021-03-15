#include <iostream>
using namespace std;

#include "snowman.hpp"
#include <stdexcept>
#include <string>
#include <array>


const int MIN = 11111111, MAX=44444444;
const int DIVIDE = 10;
const int SIZE = 8;
const int OPTION =4;
const int HEAD = 0, NOSE=1,LE=2,RE=3,LA=4,RA=5,T=6,B=7;

array<int,SIZE> list;



int validInput(int n){
    if (n < MIN || n > MAX)
    {
       return -1;
    }
    int j = SIZE-1;
    while (n>0)
        {
            int c = n%DIVIDE;
            n = n/DIVIDE;
            if (c < 1 || c > 4){
                return -1;
            }
            list.at(j) = c;
            j--;
        }   
   return 1;
}

array<string ,OPTION> h = {" _===_ \n", "  ___\n .....\n", "   _\n  /_\\\n", "  ___\n (_*_)\n"};
array<string ,OPTION> n = {",", ".", "_", " "};
array<string ,OPTION> le = {"(.", "(o", "(O", "(-"};
array<string ,OPTION> re = {".)", "o)", "O)", "-)"};
array<string ,OPTION> la = {"<", "\\", "/"," "};
array<string ,OPTION> ra = {">", "/", "\\", " "};
array<string ,OPTION> t = {"( : )", "(] [)", "(> <)", "(   )"};
array<string ,OPTION> b = {" ( : )\n", " (\" \")\n", " (___)\n", " (   )\n"};


namespace ariel {
	    string snowman(int x) {
        if (validInput(x) == -1){
            throw std::out_of_range{"invalid input!!\n"};
        }
        //head
        string ans = h.at(list.at(HEAD)-1);

        //check for left arm
        if (list.at(LA) == 2)
        {
            ans.append(la.at(NOSE));
        }
        else{
              ans.append(" ");
        }
          

        //eyes and nose
        ans.append(le.at(list.at(LE)-1));
        ans.append(n.at(list.at(NOSE)-1));
        ans.append(re.at(list.at(RE)-1));

        //check for right arm
        if (list.at(RA) == 2)
        {
            ans.append(ra.at(NOSE));
        }
        else{
             ans.append(" ");
        } 

        ans.append("\n");


        if (list.at(LA) != 2)
        {
            ans.append(la.at(list.at(LA)-1));
        }
        else{
            ans.append(" ");
        } 
        
        //troso
        ans.append(t.at(list.at(T)-1));

         if (list.at(RA) != 2)
        {
            ans.append(ra.at(list.at(RA)-1));
        }
        ans.append("\n");

        //base
        ans.append(b.at(list.at(B)-1));

        return ans;

    }
}