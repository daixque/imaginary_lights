//
//  RandomCubes.hpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/07.
//

#ifndef RandomCubes_hpp
#define RandomCubes_hpp

#include "ofMain.h"
#include "DrawableObject.hpp"

class RandomCubes : DrawableObject {
protected:
    int N;
    vector<ofBoxPrimitive> cubes;
    vector<ofColor> colors;
public:
    RandomCubes();
    void draw();
};

#endif /* RandomCubes_hpp */
