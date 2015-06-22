//
//  ParticleController.cpp
//  FrameSubtraction
//
//  Created by Kathleen Sullivan on 6/18/15.
//
//

#include "ParticleController.h"
#include "cinder/Rand.h"

using namespace ci;
using std::list;

ParticleController::ParticleController(){
    
}

void ParticleController::addParticles( ci::Surface8u surface ){
    int count = 0;
    mParticles.clear();
    Surface::Iter iter = surface.getIter();
    while (iter.line() ){
        while( iter.pixel() ){
            if( iter.r() == 0 ){
                // Vec2f randVec = Rand::randVec2f();
                if(count % 100 == 0 ){
                    Vec2f pos = Vec2f( iter.x() * 3.33, iter.y() * 1.875 );
                    //   Vec2f vel = randVec * Rand::randFloat( 5.0f );
                    mParticles.push_back( Particle( pos ));
                    count = 0;
                }
                count++;
            }
        }
    }
}

void ParticleController::draw(){
    gl::setViewport(ci::app::getWindowBounds() );
    for( list <Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p){
        p->draw();
    }
}