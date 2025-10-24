#include "particle.h"
#include <iostream>
#include <cmath>

// default constructor - ROOT needs the default one where everything is set to 0
particle::particle() :
// initialize all members to null
px(0), py(0), pz(0)
{
}

// another constructor
particle::particle(Double_t x, Double_t y, Double_t z) :
// something should go here
px(x), py(y), pz(z)
{
}
// destructor
particle::~particle(){
// right now I’m empty
}

Double_t particle::getMagnitude() const {
    return std::sqrt(px*px + py*py + pz*pz);
}
