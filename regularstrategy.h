#pragma once
#include "movementstrategy.h"

namespace corsim
{

    class RegularStrategy : public MovementStrategy
    {
    public:
        bool move() {
            return true;
        }
    };
}