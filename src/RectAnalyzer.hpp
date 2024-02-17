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

class RectAnalyzer : public DrawableObject {
protected:
    std::array<float, 128>* fftSmoothed;
    
public:
    RectAnalyzer();
    void setup(Timer* timer) override;
    void setFFT(std::array<float, 128>* fftSmoothed);
    void draw() override;
};

#endif /* RectAnalyzer_hpp */
