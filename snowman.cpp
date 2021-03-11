//
// Created by nitzan on 08/03/2021.
//
#include <string>
#include "snowman.hpp"
#include <array>
#include <stdexcept>
#include <iostream>
#include <cmath>

using namespace std;
namespace ariel {
    const array<string,4> hats = {"_===_","  ___ \n.....", "  -\n  /_\\"," ---\n (_*_)"};
    const array<string,4> eyes = {".","o","O","-"};
    const array<string,4> nose = {",",".","_"," "};
    const array<string,4> left_arm_upwards = {"","\\","",""};
    const array<string,4> left_arm = {"<"," ","/"," "};
    const array<string,4> right_arm_upwards = {"","/","",""};
    const array<string,4> right_arm = {">"," ","\\"," "};
    const array<string,4> torsos = {" : ", "] [","> <", "   "};
    const array<string,4> bases = {" : ", "\" \"", "___","   "};
    const int HAT=0,NOSE=1,LEFT_EYE=2,RIGHT_EYE=3,LEFT_ARM=4,RIGHT_ARM=5,TORSO=6,BASE=7,INPUT_SIZE = 8,MAX_SNOWMAN_SIZE=44444444,MIN_SNOWMAN_SIZE=11111111,NEXT_PART=10;
    array<int,INPUT_SIZE> snow_man_arr = {};
    array<int,INPUT_SIZE> int_to_arr(int man){
        array<int,INPUT_SIZE> snow_man = {};
        for (int i = INPUT_SIZE-1; i >= 0; i--) {
            snow_man[i] = man%NEXT_PART -1;
            man /= NEXT_PART;
        }
        return snow_man;
    }
    string face()
    {
        return left_arm_upwards[snow_man_arr[LEFT_ARM]]+"("+eyes[snow_man_arr[LEFT_EYE]]+nose[snow_man_arr[NOSE]]+eyes[snow_man_arr[RIGHT_EYE]]+")"+right_arm_upwards[snow_man_arr[RIGHT_ARM]];

    }
    string body()
    {
        return left_arm[snow_man_arr[LEFT_ARM]]+"("+torsos[snow_man_arr[TORSO]]+")"+right_arm[snow_man_arr[RIGHT_ARM]];
    }
    void validate_input(int man)
    {
        int size = log10(man) +1;
        if (size < INPUT_SIZE)
            throw std::invalid_argument("Too short");
        else if (size > INPUT_SIZE)
            throw std::length_error("Too long");
        for (int i = 0; i < INPUT_SIZE; i++) {
                if ((man%NEXT_PART < 1) || (man%NEXT_PART > 4))
                    throw std::out_of_range("Not an option");
                man /= NEXT_PART;
        }

    }
    string snowman(int man) {
        validate_input(man);
        snow_man_arr = int_to_arr(man);
        string snowman_str = " "+hats[snow_man_arr[HAT]]; // Hat
        snowman_str += "\n"+face(); // Face
        snowman_str += "\n"+body(); // Body(arms + torso)
        snowman_str += "\n ("+bases[snow_man_arr[BASE]]+")"; // Base
        return snowman_str;
    }
}