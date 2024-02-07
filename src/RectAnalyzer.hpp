//
//  RectAnalyzer.hpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/05.
//

#ifndef RectAnalyzer_hpp
#define RectAnalyzer_hpp

#include "ofMain.h"
#include "DrawableObject.hpp"

class RectAnalyzer : DrawableObject {
public:
    RectAnalyzer();
    void draw(std::array<float, 128>& fftSmoothed);
};

#endif /* RectAnalyzer_hpp */
