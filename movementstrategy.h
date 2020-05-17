#pragma once

//interface for both strategies.

class MovementStrategy
{
public:
    virtual bool move() = 0;
};