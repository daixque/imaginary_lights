//
//  RectAnalyzer.cpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/05.
//

#include "RectAnalyzer.hpp"

RectAnalyzer::RectAnalyzer() : DrawableObject() {
    
}

void RectAnalyzer::setup(Timer* timer) {
    DrawableObject::setup(timer);
}

void RectAnalyzer::setFFT(std::array<float, 128> *fftSmoothed) {
    this->fftSmoothed = fftSmoothed;
}

void RectAnalyzer::draw() {
    if (!fftSmoothed) return;
    if (timer) {
        cameraMovement.begin(timer->getElapsedTime());
        ofBackground(GlobalSettings::getInstance().dark);
        
        float c = 255.0f;
        ofSetColor(GlobalSettings::getInstance().lineColor);
        for (int i = 0; i < fftSmoothed->size(); i++) {
            float v = (*fftSmoothed)[i];
            float deg = ofMap(v, 0.0f, 1.0f, 0.f, 360.f);
            
            ofPushMatrix();
            ofRotate(deg, 0.0f, 0.0f, 1.0f);
            ofPushMatrix();
            glm::vec3 p = glm::vec3(-100.0f, -100.0f, (float)-i * 20.0f);
            ofTranslate(p);
            ofNoFill();
            ofDrawRectangle(0, 0, 200, 200);
            ofPopMatrix();
            ofPopMatrix();
        }
        cameraMovement.end();
    }
}
