//
//  Particle.cpp
//  LobbyProject
//
//  Created by Kat Sullivan on 6/18/15.
//
//

#include "Particle.h"

// CURRENTLY NOT USING THIS CLASS


Particle::Particle( Vec2f pos , float _mRadius){
    mPos = pos;
    //  mVel = vel;
    //mRadius = 0.005;
    mRadius = _mRadius;
}

void Particle::draw(){
    // gl::setViewport( ci::app::getWindowBounds() );
    gl::color(1, 1, 1);
    gl::drawSolidCircle( mPos, mRadius, 16);
}