#pragma once

#include <stdint.h>
#include <iostream>

struct Data 
{
    unsigned long int i;
};

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
