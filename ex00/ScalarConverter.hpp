#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
    public:
        static void convert(std::string const &str);
        static void disply(char c);
        static void disply(int i);
        static void disply(float f);
        static void disply(double d);
};
