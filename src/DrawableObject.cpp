//
//  DrawableObject.cpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/07.
//

#include "DrawableObject.hpp"

DrawableObject::DrawableObject() {
    position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void DrawableObject::setup(Timer* timer) {
    cameraMovement.loadCSV("camera.csv");
    this->timer = timer;
}

void DrawableObject::draw() {
    
}
