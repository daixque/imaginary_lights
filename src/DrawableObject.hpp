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

class DrawableObject {
protected:
    glm::vec3 position;
    
public:
    DrawableObject();
    
    void setup();
    void draw();
};


#endif /* DrawableObject_hpp */
