//
//  RectAnalyzer.cpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/05.
//

#include "RectAnalyzer.hpp"

void RectAnalyzer::draw(std::array<float, 128>& fftSmoothed) {
    
    for (int i = 0; i < fftSmoothed.size(); i++) {
        float v = fftSmoothed[i];
        float deg = ofMap(v, 0.0f, 1.0f, 0.f, 360.f);
        
        ofPushMatrix();
        float c = ofMap(deg, 0.0f, 360.0f, 0, 255);
        c = 255.0f;
        ofSetColor(c, c, c, 30.0f);
        ofRotate(deg, 0.0f, 0.0f, 1.0f);
        ofPushMatrix();
        glm::vec3 p = glm::vec3(-100.0f, -100.0f, (float)-i);
        ofTranslate(p);
        //ofRectangle(100.0f, 100.0f, 200.0f, 200.0f);
        ofNoFill();
        ofDrawRectangle(0, 0, 200, 200);
        ofPopMatrix();
        ofPopMatrix();
    }
}
