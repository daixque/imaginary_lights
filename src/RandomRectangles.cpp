//
//  RandomRectangles.cpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/07.
//

#include "RandomRectangles.hpp"

RandomRectangles::RandomRectangles() {
    number = 1000; // Set the number of rectangles here

    // Set the mode of the VBO to triangles
    rectangles.setMode(OF_PRIMITIVE_TRIANGLES);

    // Generate new rectangles and colors
    for(int i = 0; i < number; i++){
        float x = ofRandomWidth() * 2.0 - ofGetWindowWidth();
        float y = ofMap(ofRandomHeight(), 0, ofGetWindowHeight(), -100, 100);
        float z = -ofRandomHeight() * 10 + 50;
        float w = 100;
        float h = 100;
//        
//        // Add vertices for the rectangle
//        rectangles.addVertex(ofVec3f(x, y, z));
//        rectangles.addVertex(ofVec3f(x + w, y, z));
//        rectangles.addVertex(ofVec3f(x + w, y, z + h));
//        rectangles.addVertex(ofVec3f(x, y, z + h));
        
        // Generate a random color
        ofColor c = GlobalSettings::getInstance().lineColor;

        // Add vertices and color for the rectangle
        rectangles.addVertex(ofVec3f(x, y, z));
        rectangles.addColor(c);
        rectangles.addVertex(ofVec3f(x + w, y, z));
        rectangles.addColor(c);
        rectangles.addVertex(ofVec3f(x + w, y, z + h));
        rectangles.addColor(c);
        rectangles.addVertex(ofVec3f(x, y, z + h));
        rectangles.addColor(c);
        
        // Add indices for two triangles that make up the rectangle
        int index = i * 4;
        rectangles.addIndex(index);
        rectangles.addIndex(index + 1);
        rectangles.addIndex(index + 2);
        rectangles.addIndex(index);
        rectangles.addIndex(index + 2);
        rectangles.addIndex(index + 3);
    }
}

void RandomRectangles::setup() {
    
}

void RandomRectangles::draw() {
    ofPushMatrix();
    //ofSetColor(GlobalSettings::getInstance().lineColor);
    float z = ofGetFrameNum();
    ofTranslate(glm::vec3(0, 0, z));
    rectangles.draw();
    ofPopMatrix();
}
