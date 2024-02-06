//
//  Atractor.cpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/06.
//

#include "Attractor.hpp"

Attractor::Attractor() {
    
    // Initialize parameters
    pres = 1000.0f;
    xxmin = -2.0f;
    xxmax = 2.0f;
    yymin = -2.0f;
    yymax = 2.0f;
    a = 2.24f;
    b = 0.43f;
    c = -0.65f;
    d = -2.43f;
    e = 1.0f;
    iter1 = 100;
    iter2 = 100;
}

void Attractor::draw() {
    
    float xinc = pres / (xxmax - xxmin); // Controls x-pixel position
    float yinc = pres / (yymax - yymin); // Controls y-pixel position

    float x = ofMap(ofGetFrameNum() * 0.01f, 0.0f, 1000000.0f, 0.0, 1.0f), y = 0, z = 0; // Starting point

    int count = 0;
    //int j = ofGetFrameNum();
    // Iteration loops
    for(int j = 0; j < iter1; j++){
        for(int i = 0; i < iter2; i++){
            float xx = sin(a * y) - z * cos(b * x);
            float yy = z * sin(c * x) - cos(d * y);
            float zz = e * sin(x);

            x = xx;
            y = yy;
            z = zz;

            // If the point is within the specified range
            if(xx < xxmax && xx > xxmin && yy < yymax && yy > yymin){
                int xxx = (xx - xxmin) * xinc; // Scale to range (0, pres)
                int yyy = (yy - yymin) * yinc; // Scale to range (0, pres)

                // Increase the brightness of the pixel at (xxx, yyy)
//                ofColor color = p.getColor(xxx, yyy);
//                color += ofColor::white;
//                p.setColor(xxx, yyy, color);
//                if (count == 40) {
//                    ofSetColor(255, 0, 0);
//                    ofDrawCircle(xxx, yyy, 1);
//                } else {
//                    //ofSetColor(255, 255, 255);
//                }
                ofSetColor(255, 255, 255);
                float tone = ofMap(z, 0.0f, e, 0.0f, 255.0f);
                ofPushMatrix();
                ofTranslate(glm::vec3(0, 0, zz * -100));
                ofDrawCircle(xxx, yyy, 1);
                ofPopMatrix();
                count++;
            }
        }
    }
}
