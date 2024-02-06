//
//  Field.hpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/06.
//

#ifndef Field_hpp
#define Field_hpp

#include "ofMain.h"

class Field {
protected:
    ofImage image;
    
public:
    Field();
    void draw(std::array<float, 128>& fftSmoothed);
};

#endif /* Field_hpp */
