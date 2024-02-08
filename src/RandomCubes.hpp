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

class RandomCubes : public DrawableObject {
protected:
    std::vector<ofBoxPrimitive> boxes;
    ofShader shader;
public:
    RandomCubes();
    void draw();
};

#endif /* RandomCubes_hpp */
