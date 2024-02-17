//
//  DrawableObject.hpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/07.
//

#ifndef DrawableObject_hpp
#define DrawableObject_hpp

#include "ofMain.h"
#include "GlobalSettings.hpp"
#include "CameraMovement.hpp"
#include "Timer.h"

class DrawableObject {
protected:
    glm::vec3 position;
    CameraMovement cameraMovement;
    Timer* timer;
    
public:
    DrawableObject();
    
    virtual void setup(Timer* timer);
    virtual void draw();
};


#endif /* DrawableObject_hpp */
