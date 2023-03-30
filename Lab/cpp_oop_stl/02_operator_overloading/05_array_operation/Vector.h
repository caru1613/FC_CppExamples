#include <iostream>

class Vector
{
public:
    float x, y, z;

    Vector(float x, float y, float z)
        : x(x), y(y), z(z)
    {

    }

    float& operator[](int index)
    {
        if (index < 1)
            return x;
        if (index < 2)
            return y;
        return z;
    }

    //const float& operator[](int index) const // Å« °´Ã¼ ¹ÝÈ¯ ½Ã const ÂüÁ¶
    float operator[](int index) const
    {
        if (index < 1)
            return x;
        if (index < 2)
            return y;
        return z;
    }
};
