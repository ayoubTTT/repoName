#pragma once

#include <cmath>
#include <exception>
#include <iostream>

class Base
{
    public:
        virtual ~Base(void);
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);