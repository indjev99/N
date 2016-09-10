#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include "../headers/primitive_types.h"

#include<vector>

class Struct
{
public:
    std::vector<std::pair<int, Num>> members;
    int size;
    int primitiveSize;
};


#endif // STRUCT_H_INCLUDED
