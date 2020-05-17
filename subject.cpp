// Corona Simulation - basic simulation of a human transmissable virus
// Copyright (C) 2020  wbrinksma

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "subject.h"
#include <math.h>
#include <time.h>

namespace corsim
{

Subject::Subject(int x, int y, int radius, bool infected)
{
    this->_x = x;
    this->_y = y;
    this->_radius = radius;
    this->_infected = infected;
    this->_sick = 0;
    this->_immune = 0;
    this->_strategy = nullptr;
}

double Subject::immune()
{
    return this->_immune;
}

void Subject::set_strategy(MovementStrategy *strategy) 
{
    delete this->_strategy;
    this->_strategy = strategy;
}

int Subject::execute() {
    return this->_strategy->move();
    //uncomment this line and comment the line above to disable the LockdownStrategy
    //return true;
}
void Subject::set_immune()
{
    this->_immune = 3;
}
void Subject::tear_down() {
    if (this->_immune > 0) {
        this->_immune = this->_immune -= 1;
    }
}

double Subject::sick()
{
    return this->_sick;
}
void Subject::set_sick()
{
    if (this->_sick == 0) {

        this->_sick = 100;
    }
    else {
        this->_sick = this->_sick -= 1;
    }
    if(this->_sick == 0) 
    {
        this->recover();
    }
}

double Subject::x()
{
    return this->_x;
}

double Subject::y()
{
    return this->_y;
}

void Subject::set_x(double x)
{
    if (this->execute()) {
        this->_x = x;
    }
}

void Subject::set_y(double y)
{
    if (this->execute()) {
        this->_y = y;
    }
}

double Subject::dx()
{
    return this->_dx;
}

double Subject::dy()
{
    return this->_dy;
}

void Subject::set_dx(double dx)
{
    this->_dx = dx;
}

void Subject::set_dy(double dy)
{
    this->_dy = dy;
}

int Subject::radius()
{
    return this->_radius;
}

bool Subject::infected()
{
    return this->_infected;
}

void Subject::infect()
{
    if (this->_immune <= 0) {
        this->_infected = true;
    }
}

void Subject::recover()
{
    this->set_immune();
    this->_infected = false;
}

double Subject::angle()
{
    return atan2(_dy,_dx);
}

double Subject::speed()
{
    return sqrt(_dx * _dx + _dy * _dy);
}

}