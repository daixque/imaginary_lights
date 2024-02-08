//
//  RandomRectangles.hpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/07.
//

#ifndef RandomRectangles_hpp
#define RandomRectangles_hpp

#include "ofMain.h"
#include "DrawableObject.hpp"

class RandomRectangles : public DrawableObject {
protected:
    int number;
    ofVboMesh rectangles;
    vector<ofColor> colors;
    
public:
    RandomRectangles();
    void setup();
    void draw();
    void reset();
};

#endif /* RandomRectangles_hpp */
