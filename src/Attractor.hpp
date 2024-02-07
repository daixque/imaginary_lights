//
//  Atractor.hpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/06.
//

#ifndef Atractor_hpp
#define Atractor_hpp

#include "ofMain.h"
#include "DrawableObject.hpp"

class Attractor : DrawableObject {
protected:
    float pres, xxmin, xxmax, yymin, yymax; // Parameters for scaling
    float a, b, c, d, e; // Control parameters
    int iter1, iter2; // Number of iterations
    
public:
    Attractor();
    void draw();
};
#endif /* Atractor_hpp */
