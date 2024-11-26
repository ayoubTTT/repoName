#include "Serializer.hpp"

int main()
{
    Data data1;
    data1.i = 151;

    uintptr_t i = Serializer::serialize(&data1);
    std::cout << &data1 << std::endl;

    Data *data2 = Serializer::deserialize(i);
    std::cout << data2 << std::endl;
    return 0;
}