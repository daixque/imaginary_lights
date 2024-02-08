//
//  Field.hpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/06.
//

#ifndef Field_hpp
#define Field_hpp

#include "ofMain.h"
#include "DrawableObject.hpp"

class Field : public DrawableObject {
protected:
    ofImage image;
    ofMesh mesh;
    ofShader shader;
    
public:
    Field();
    void setup();
    void draw(std::array<float, 128>& fftSmoothed);
};

#endif /* Field_hpp */
