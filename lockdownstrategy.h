#pragma once
#include "movementstrategy.h"

namespace corsim
{
    class LockdownStrategy : public MovementStrategy
    {
    public:
        virtual bool move();
    };
}